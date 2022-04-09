#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <wait.h>

int main(int argc, char **argv)
{
    if (argc < 3)
    {
        fprintf(stderr, "Wrong input!\n");
        return EXIT_FAILURE;
    }

    int pid = fork();
    if (pid == -1)
    {
        perror("fork problem");
        return EXIT_FAILURE;
    }
    else if (pid == 0)
    {
        // if ( == -1)
        // {
        //     perror("exec error");
        //     return EXIT_FAILURE;
        // }
        execlp(argv[1], argv[1], NULL);
    }
    else
    {
        int status;
        wait(&status);
        WIFEXITED(status);
        printf("Status %d\n",WEXITSTATUS(status));
        if (status != 0)
        {
            fprintf(stderr, "Command error!\n");
            return EXIT_FAILURE;
        }
        if (execlp(argv[2], argv[2], NULL) == -1)
        {
            perror("exec error");
            return EXIT_FAILURE;
        }
    }

    return EXIT_SUCCESS;
}