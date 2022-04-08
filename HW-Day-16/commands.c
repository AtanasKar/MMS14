#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc,char** argv){
    int fd = open(argv[2],O_RDONLY);
    if(fd<0){
        perror("Error info");
        return EXIT_FAILURE;
    }  

    char buf[BUFSIZ];

    if(strcmp(argv[1],"cat")==0){
        read(fd,buf,BUFSIZ);
        write(1,buf,strlen(buf));
    }else if(strcmp(argv[1],"head")==0){
        read(fd,buf,BUFSIZ);
        size_t size=0;
        for (size_t i = 0; i < 10; )
        {
            if(buf[size]=='\n'){
                i++;
            }
            size++;
        }
        write(1,buf,size);
    }else if(strcmp(argv[1],"tail")==0){
        read(fd,buf,BUFSIZ);
        size_t i=0;
        size_t lines=0;
        while(buf[i]!=EOF){
            if(buf[i]=='\n'){
                lines++;
            }
            i++;
        }

        lines-=10;
        size_t cntOfNotLastChars=0;
        for (size_t j = 0; j < lines;)
        {
            if(buf[i]=='\n'){
                j++;
            }
            cntOfNotLastChars++;
        }
        
        size_t sizeOflastLines=strlen(buf)-cntOfNotLastChars;
        write(1,&buf[cntOfNotLastChars],sizeOflastLines);
    }

    close(fd);
}