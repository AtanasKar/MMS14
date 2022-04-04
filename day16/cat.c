#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    char buffer[BUFSIZ];
    size_t bytes = 0;
    
    if (argc == 1)
    {
        while ((bytes = read(STDIN_FILENO, buffer, BUFSIZ)) > 0)
        {
            write(STDOUT_FILENO, buffer, bytes);
        }
        return EXIT_SUCCESS;
    }

    for (size_t i = 1; i < argc; i++)
    {
        int fd = open(argv[i], O_RDONLY);
        if (fd == -1)
        {
            perror("Error info: ");
            return EXIT_FAILURE;
        }

        bytes=read(fd,buffer,BUFSIZ);
        write(STDOUT_FILENO, buffer, bytes);
        close(fd);
    }

    return EXIT_SUCCESS;
}