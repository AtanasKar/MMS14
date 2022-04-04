#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    for (size_t i = 1; i < argc; i++)
    {
        if (!strcmp(argv[i], "tee"))
        {
            if (!strcmp(argv[i + 1], "-a"))
            {
            }
            else
            {
                int fd = open(argv[i+1],O_CREAT|O_RDWR);
                if (fd > 0)
                {
                    perror("error info");
                    return EXIT_FAILURE;
                }

                char buffer[BUFSIZ];
                size_t bytes = 0;
                for (size_t j = 1; j < i; j++)
                {
                    printf("Vliza v cikla\n");
                    int newfd = open(argv[j], O_RDWR);
                    if (newfd > 0)
                    {
                        perror("error info");
                        return EXIT_FAILURE;
                    }
                    bytes = read(newfd, &buffer, BUFSIZ);
                    write(fd, buffer, bytes);
                    close(newfd);
                }

                close(fd);
            }
        }
    }

    return EXIT_SUCCESS;
}