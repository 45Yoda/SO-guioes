#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <ctype.h>

int main(){
    int pfd[2],n,i=0;
    char buf[100];
    char dados[1024];

    pipe(pfd);

    if(fork()==0){
        close(pfd[0]);

        dup2(pfd[1],1);
        close(pfd[1]);

        execlp("ls","ls",NULL);
        perror("ls");
        _exit(1);

    }else{
        close(pfd[1]);
        while((n=read(pfd[0],buf,1))>0){
            printf("%c",toupper(buf[0]));
        }
    }
}
