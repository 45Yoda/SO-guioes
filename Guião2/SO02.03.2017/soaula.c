#include <stdio.h>
#include <unistd.h>


int main(){
    int p,i=0;

    printf("Antes pid=%d ppid=%d\n",getpid(), getppid());

    p=fork();
    if (p==0){
        i++;
        printf("Eu sou o filho! pid=%d ppid=%d p=%d i=%d\n",getpid(),getppid(),p,i);

        sleep(10);
        printf("Filho :Terminei pid=%d ppid=%d p=%d i=%d\n",getpid(),getppid(),p,i);

    }
    else{
        i++;
        printf("Eu sou o pai! pid=%d ppid=%d p=%d i=%d\n",getpid(),getppid(),p,i);


        printf("Pai :Terminei pid=%d ppid=%d p=%d i=%d\n",getpid(),getppid(),p,i);


    }
}
