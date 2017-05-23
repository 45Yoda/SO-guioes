#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>

int main(){

    printf("Antes\n");

    execl("/usr/bin/ls","ls","-l",NULL);

    printf("Aconteceu um erro\n");

    return 0;
}
