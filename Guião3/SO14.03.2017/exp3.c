#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(){
    int minha;

    printf("Antes\n");

    if(fork()==0){
    //carrega para disco
    execl("/usr/bin/ls",
             "ls",
            "-l",
            NULL);

            //mensagem de erro relacionada com o erro
            perror("naoexiste");

            _exit(1);
    }
    else{wait(NULL);}
    //so corre se houver um erro
    printf("Depois\n");
    return 0;
}

/*
int main(){
    int minha;

    printf("Antes\n");

    if(fork()==0){
    //carrega para disco
    execl("/usr/bin/naoexiste",
             "ls",
            "-l",
            NULL);

            perror("naoexiste");

            _exit(1);
    }
    else{wait(NULL);}
    //so corre se houver um erro
    printf("Depois\n");
    return 0;
}
*/
