#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>


int main (){
    int N=10;
    int i;


    for(i=0;i<N;i++){

        if(fork()==0){
            printf("TAREFA       i=%d\n",i);
            sleep(5);
            _exit(0);
        }
    }
    for(i=0;i<N;i++){
        wait(NULL);
        printf("Terminou\n");
    }
}
