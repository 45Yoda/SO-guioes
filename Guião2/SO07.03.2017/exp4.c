#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAXSIZE 10


int main(){
    int i,j, N=MAXSIZE;
    int mat[MAXSIZE][MAXSIZE+MAXSIZE]={{0,0,1,0,0,0,0,0,0},{0,0,0,0,0,1,0,0,0},{0,0,0,0,0,0,0,0,0},{0,0,1,0,0,0,0,0,0},
                                       {0,0,0,0,0,1,0,0,0},{0,0,0,0,0,0,0,0,0},{0,0,1,0,0,0,0,0,0},
                                       {0,0,0,0,0,1,0,0,0},{0,0,0,0,0,0,0,1,0},{0,0,0,1,0,0,0,0,0}};
    int x;

    for(i=0; i<N; i++){
        if(fork() == 0){
            printf("Filho %d : a busca começa\n",i);
            for (j=0;j<(N+N);j++){

                if(mat[i][j] == 1){
                        printf("Filho %d: ta aqui\n",i);
                        _exit(0);
                }
           }
           printf("Filho %d : n econtro nada\n",i);
               _exit(1);




        }
        //alinea 3 (1 a 1 (sequencialmente) começa e termina ex comeca 0 termina 0)
        wait(NULL);
    }

    //alinea 4 (começam todos ao mesmo tempo  em ordem aleatoria ex comeca 0 2 1 4...)
    //for(i = 0; i<N; i++)
      // wait(NULL);

}
