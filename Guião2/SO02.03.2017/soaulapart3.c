#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>


int main(){
    int i, N=10;

    for(i=0; i<N; i++){

        if(fork() == 0){

            printf("Filho %d : comecei\n",i);

            sleep(2);

            printf("Filho %d : terminei!\n",i);

            _exit(0);
        }
        //alinea 3 (1 a 1 (sequencialmente) começa e termina ex comeca 0 termina 0)
        //wait(NULL);

    }

    //alinea 4 (começam todos ao mesmo tempo  em ordem aleatoria ex comeca 0 2 1 4...)
    for(i = 0; i<N; i++)
            wait(NULL);

}
