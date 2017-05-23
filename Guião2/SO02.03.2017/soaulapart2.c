#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>


int main(){
    int p,i=0,status,f;

    printf("Antes pid=%d ppid=%d\n",getpid(), getppid());

    p=fork();
    if (p==0){
        i++;
        printf("Eu sou o filho! pid=%d ppid=%d p=%d i=%d\n",getpid(),getppid(),p,i);

        sleep(10);
        printf("Filho :Terminei pid=%d ppid=%d p=%d i=%d\n",getpid(),getppid(),p,i);

        _exit(0);
    }
    else{
        i++;
        printf("Eu sou o pai! pid=%d ppid=%d p=%d i=%d\n",getpid(),getppid(),p,i);

        f=wait(&status);

        if (WIFEXITED(status)){

        printf("Pai :O filho terminou com sucesso pid=%d f=%d es=%d\n\n",getpid(),f, WEXITSTATUS(status));
        }

        else{
            printf("Pai :O filho terminou sem sucesso\n");
        }

    }
}
