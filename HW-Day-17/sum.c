#include <stdio.h>
#include <stdlib.h>
#include <wait.h>
#include <unistd.h>

int main(int argc, char **argv)
{
    int sum = 0;
    size_t i = 0;

    int fd[2];
    if (pipe(fd) == -1)
    {
        perror("pipe error");
        return EXIT_FAILURE;
    }
    int pid = fork();
    if (pid == -1)
    {
        perror("fork error");
        return EXIT_FAILURE;
    }
    else if (pid == 0)
    {
        close(fd[0]);
        for (; i < argc / 2; i++)
        {
            sum += atoi(argv[i]);
        }
        write(fd[1], &sum, sizeof(sum));
        close(fd[1]);
    }
    else
    {
        close(fd[1]);
        for (size_t j = i + 1; j < argc; j++)
        {
            sum += atoi(argv[j]);
        }
        int sumChild;
        read(fd[0], &sumChild, sizeof(sumChild));
        close(fd[0]);
        printf("%d\n", sum);
        wait(NULL);
    }

    return EXIT_SUCCESS;
}