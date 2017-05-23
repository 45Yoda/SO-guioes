#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char* argv[]){
    int i=1;

    for(i=1;i<argc;i++){

        if(fork()==0){
            execlp(argv[i],argv[i],NULL);
        printf("Erro!\n");
        _exit(1);
        }
    }

    for(i=1;i<argc;i++){
        wait(NULL);
    }
}
