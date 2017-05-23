#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>

int main(){


    if(fork()==0){
        printf("Filho -%d\n",getpid());
        printf("Pai   -%d\n",getppid());
    }
    printf("Hello!!!\n");
    return 0;
}
