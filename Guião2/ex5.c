#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>

int main(){
    int p,status,i;
    p=fork();
    for(i=1;i<=10;i++){
        if(p==0){ //Filho
            p=fork();
        }
        else{//Pai
            wait(&status);
            printf("Filho -> %d Status -> %d | Pai -> %d\n",getpid(),WEXITSTATUS(status),getppid());
            _exit(i);
        }
    }
    return 0;
}
