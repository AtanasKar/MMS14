#include <stdio.h>
#include <sys/time.h>
#include <stdlib.h>
#include <sys/fcntl.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char **argv)
{
    struct timeval tv1;
    gettimeofday(&tv1,NULL);

    //printf("Seconds: %ld, Microseconds: %ld\n", tv1.tv_sec, tv1.tv_usec);

    int pid = fork();
    if (pid < 0)
    {
        perror("Fork failed");
        exit(-1);
    }
    else if (pid == 0)
    {
        execl(argv[1], argv[1], NULL);
        perror("Exec failed\n");
        exit(-1);
    }
    wait(NULL);

    struct timeval tv2;
    gettimeofday(&tv2, NULL);

    long ellapsedMS=(tv2.tv_sec-tv1.tv_sec)*1000000+(tv2.tv_usec-tv1.tv_usec);
    printf("Elapsed time: %ld\n",ellapsedMS);

    exit(0);
}