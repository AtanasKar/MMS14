#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

void* printRandomString(void *arg);

int main(int argc,char** argv){
    
    if(argc<2){
        fprintf(stderr,"input error\n");
        return EXIT_FAILURE;
    }

    int N=atoi(argv[1]);
    pthread_t* ths=malloc(sizeof(pthread_t)*N);
    if(ths==NULL){
        perror("malloc");
        return EXIT_FAILURE;
    }
    
    for (size_t i = 0; i < N; i++)
    {
        if(pthread_create(&ths[i],NULL,printRandomString,NULL)!=0){
            perror("pthread create");
            return EXIT_FAILURE;
        }
    }
    
    for (size_t i = 0; i < N; i++)
    {
        if(pthread_join(ths[i],NULL)!=0){
            perror("pthread join");
            return EXIT_FAILURE;
        }
    }
    

    return EXIT_SUCCESS;
}

void* printRandomString(void *arg)
{
    char str[11];
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
    printf("%s\n",str);
}