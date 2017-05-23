#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>


int main(){
    int p,w,status,r;
    printf("Antes pid=%d ppid=%d\n",getpid(),getppid());

    p=fork();

    if(p==0){
        printf("Filho: Depois pid=%d ppid=%d p=%d\n",getpid(),getppid(),p);
        sleep(5);
        printf("Filho:acabei ppid=%d\n",getppid());

        _exit(123);
    }else{
        printf("Pai: Depois pid=%d ppid=%d p=%d\n",getpid(),getppid(),p);

        sleep(1);
        printf("Pai: à espera....\n");

        w=wait(&status);

        if(WIFEXITED(status)){
            printf("Pai: pid=%d terminou com sucesso\n",w,WEXITSTATUS(status));

        }
        else{
            printf("Pai: pid=%d falhou!\n",w);
        }
        printf("Pai: acabei w=%d\n",w);
    }

}
