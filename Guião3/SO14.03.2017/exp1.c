#include <stdio.h>
#include <unistd.h>

int main(){
    int minha;

    printf("Antes\n");

    //carrega para disco
    execl("/usr/bin/ls", /*nome do fich. exec*/
            "ls", /*argv[0]*/
            "-l", /*argv[1]*/
            NULL);

    //so corre se houver um erro
    printf("Aconteceu um erro\n");

    return 0;
}
