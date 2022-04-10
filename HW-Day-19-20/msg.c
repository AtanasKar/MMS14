#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

void *printMsg(void *arg)
{
    printf("%s\n", (char *)arg);
}

int main(int argc, char **argv)
{
    unsigned P = atoi(argv[1]);
    unsigned T = atoi(argv[2]);

    pthread_t *ths = malloc(sizeof(pthread_t) * T);

    for (size_t i = 0; i < P; i++)
    {
        if (fork() == 0)
        {
            printf("Process num: %ld\n",i);
            for (size_t j = 0; j < T; j++)
            {
                ///printf("Thread num: %ld\n",j);
                if (pthread_create(&ths[j], NULL, printMsg(argv[3]), NULL) != 0)
                {
                    perror("pthread create");
                    return EXIT_FAILURE;
                }
            }
            for (size_t j = 0; j < T; j++)
            {
                if (pthread_join(ths[j], NULL) != 0)
                {
                    perror("pthread create");
                    return EXIT_FAILURE;
                }
            }
        }
    }
    for (size_t i = 0; i < P; i++)
    {
        wait(NULL);
    }

    return EXIT_SUCCESS;
}