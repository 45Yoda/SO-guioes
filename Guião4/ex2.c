#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <string.h>

#define N 45

int main(int argc, char** argv){
    char buf[45];
    int fdi=0;
    int fdoS=0;
    int fdoE=0;
    int n;

    fdi=open ("/etc/passwd", O_RDONLY);
    fdoS=open ("saida.txt",O_CREAT | O_WRONLY | O_TRUNC, 0644);
    fdoE=open ("erros.txt",O_CREAT | O_WRONLY | O_TRUNC, 0644);

    dup2(fdi,0);
    close(fdi);
    dup2(fdoS,1);
    close(fdoS);
    dup2(fdoE,2);
    close(fdoE);

    if(!fork()){
        while(1){
            n=read(0,buf,N);

            if(n==0) break;

            write(1,buf,n);

        }

        _exit(1);
    }
    else wait(NULL);

    close(fdi);
    close(fdoS);
    close(fdoE);

    return 0;
}
