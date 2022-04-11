#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>

pthread_mutex_t mux;
int sum = 0;

void *sumNums(char *fileName)
{
    FILE *fp;
    if ((fp = fopen(fileName, "r")) != NULL)
    {
        pthread_mutex_lock(&mux);
        int item;
        while (!feof(fp))
        {
            fscanf(fp, "%d", &item);
        }
        sum += item;
        pthread_mutex_unlock(&mux);

        fclose(fp);
    }
    return NULL;
}

int main(int argc, char **argv)
{
    pthread_mutex_init(&mux, NULL);

    pthread_t *ths = malloc(sizeof(pthread_t) * (argc - 1));
    if (ths == NULL)
    {
        perror("malloc");
        return EXIT_FAILURE;
    }

    for (size_t i = 1; i < argc; i++)
    {
        if (pthread_create(&ths[i], NULL, sumNums(argv[i]), NULL) != 0)
        {
            perror("ptherad create");
            return EXIT_FAILURE;
        }
    }

    for (size_t i = 1; i < argc; i++)
    {
        if (pthread_join(ths[i], NULL) != 0)
        {
            perror("pthread join");
            return EXIT_FAILURE;
        }
    }
    pthread_mutex_destroy(&mux);

    printf("sum is: %d\n", sum);

    return EXIT_SUCCESS;
}
