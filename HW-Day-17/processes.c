#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <sys/wait.h>

void randomString(char *str);

int main(int argc, char **argv)
{
    srand(time(NULL));
    char str[11];
    randomString(str);
    int N = atoi(argv[1]);
    for (size_t i = 0; i < N; i++)
    {
        if (fork() == 0)
        {
    printf("%s\n", str);
            return EXIT_SUCCESS;
        }
    }
    for (size_t i = 0; i < N; i++)
    {
        wait(NULL);
    }


    return EXIT_SUCCESS;
}

void randomString(char *str)
{
    for (size_t i = 10, j = 0; j < i; j++)
    {
        if (j == 0)
        {
            str[j] = 'A' + (rand() % 26);
        }
        else
        {
            str[j] = 'a' + (rand() % 26);
        }

        if (j + 1 == i)
        {
            str[j + 1] = '\0';
        }
    }
}