#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define COLUNAS 450
#define LINHAS 45

int ** matriz(){
    int j,i;
    int ** m;
    m = malloc(LINHAS*sizeof(int*));
    for(j=0;j<LINHAS;j++)
        m[j] = malloc(COLUNAS*sizeof(int));

    for(j=0;j<LINHAS;j++)
        for(i=0;i<COLUNAS;i++)
            m[j][i]=(rand()%1000)+1;
        return m;
}


int main(int argc, char* argv[]){
    int p,i,j,status,r;
    int pid[LINHAS];

    if(argc != 2) {printf("Erro\n");return 1;}

    int **m = matriz();
    int valor = atoi(argv[1]);

    for(i=0;i<LINHAS;i++){
        r=0;
        pid[i]=fork();
        if(pid[i]==0){
            //Filho
            for(j=0;j<COLUNAS;j++){
                if(m[i][j]==valor) r++;
            }
            _exit(r);
        }
        //Pai não faz nada
    }
    for(i=0;i<LINHAS;i++){
        waitpid(pid[i],&status,0);
        printf("Linhas %d : %d\n",i,WEXITSTATUS(status));
    }
    return 0;
}
