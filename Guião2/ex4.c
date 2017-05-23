#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>

int main() {
    int p,i,N;
    N=10;
    for(i=1;i<=N;i++){
        if(fork()==0){
            printf("Filho %d : comecei\n",i);

            sleep(2);

            printf("Filho %d : terminei!\n",i);

            _exit(0);
        }
    }

    for(i=1;i<=N;i++)
        wait(NULL);
}
