#include <string.h>
#include <stdio.h>
#include <unistd.h>


int main(){
    int pfd[2],n,i=0;
    char buf[100];
    char dados[1024];

    pipe(pfd);

    if(fork()==0){
        close(pfd[0]);
        while(1){
            i++;
            n=write(pfd[1],dados,1024);
            printf("Escrevi %d bytes\n",n*i);
        }
    }else{
        close(pfd[1]);
        while((n=read(pfd[0],buf,1))>0){
            i++;
            if(i>100)
                _exit(0);
            printf("Li %d bytes\n",n);
        }
    }
}
