#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>

void func(){
    printf(" I can't stop!\n");
}

int main(){
    struct sigaction sa;
    sa.sa_handler=func;
    sa.sa_flags=SA_RESTART;
    sigaction(SIGINT,&sa,NULL);
    sigaction(SIGTSTP,&sa,NULL);
    
    //Signalut SIGKILL ne moje da bude maskiran. Izpraten do proces toi vednaga go prikluchva.
    //Tova e taka za da nqma procesi koito ne mogat da budat spreni i da dovedat do problemi.

    while(1){
        printf("MMS C Camp\n");
        sleep(1);
    }

    return EXIT_SUCCESS;
}