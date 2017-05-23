#include <stdio.h>
#include <unistd.h>

int main(){
    int minha;

    printf("Antes\n");

    //carrega para disco
    execlp("ls", /*nome do fich. exec*/
            "ls", /*argv[0]*/
            "ps",
            NULL);

    //so corre se houver um erro
    printf("Aconteceu um erro\n");

    return 0;
}

/*
int main(){
    int minha;
    char* opts={"ls","-l","-a",NULL};
    printf("Antes\n");

    //carrega para disco
    execvp("ls",
            opts);

    //so corre se houver um erro
    printf("Aconteceu um erro\n");

    return 0;
}*/
