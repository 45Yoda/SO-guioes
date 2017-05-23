#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(){

    printf("Antes\n");

    if(fork()==0){
        execl("/usr/bin/ls","ls","-l",NULL);

        perror("naoexiste");

        _exit(1);
    }
    else wait(NULL);

    printf("Depois houve um erro\n");

    return 0;
}
