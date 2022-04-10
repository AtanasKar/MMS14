#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>

void *openAndSort(void *);

int main(int argc, char **argv)
{
    pthread_t *ths = malloc(sizeof(pthread_t) * (argc - 1));
    if (ths == NULL)
    {
        perror("malloc");
        return EXIT_FAILURE;
    }

    for (size_t i = 1; i < argc; i++)
    {
        if(pthread_create(&ths[i], NULL, openAndSort(argv[i]), NULL)!=0){
            perror("ptherad create");
            return EXIT_FAILURE;
        }
    }

    for (size_t i = 1; i < argc; i++)
    {
        if(pthread_join(ths[i],NULL)!=0){
            perror("pthread join");
            return EXIT_FAILURE;
        }
    }

    return EXIT_SUCCESS;
}

void *openAndSort(void *arg)
{
    FILE *fp;

    if ((fp = fopen((char *)arg, "rb+")) != NULL)
    {
        size_t itemSize = sizeof(int);
        int data1, data2;
        int flag = 1;

        // bubble sort
        while (flag)
        {
            flag = 0;
            fread(&data1, itemSize, 1, fp);
            fread(&data2, itemSize, 1, fp);
            while (!feof(fp))
            {
                if (data2 < data1)
                {
                    fseek(fp, (itemSize * -2), SEEK_CUR);
                    fwrite(&data2, itemSize, 1, fp);
                    fwrite(&data1, itemSize, 1, fp);
                    flag = 1;
                }
                else
                {
                    data1 = data2;
                }
                fread(&data2, itemSize, 1, fp);
            }
            if (flag)
            {
                rewind(fp);
            }
        }
        fclose(fp);
    }
}