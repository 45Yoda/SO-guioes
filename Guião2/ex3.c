#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>


int main(){
    int i,N=10;

    for(i=0;i<N;i++){
        if(fork() == 0){

            printf("Filho %d : comecei\n",i);

            sleep(2);

            printf("Filho %d : terminei!\n",i);

            _exit(0);
        }
        wait(NULL);
    }
}



/* Resolução 2
int main(){
    int p,i,N,status;
    N=10;
    for(i=1;i<=N;i++){
        p=fork();
        if(p==0){
            printf("Filho %d -> %d | Pai-> %d\n",i,getpid(),getppid());
            _exit(i);
        }
        wait(&status);
        if(WIFEXITED(status)) printf("O filho com pid %d terminou em %d lugar.\n",p,WEXITSTATUS(status));
    }

    return 0;
}
*/
