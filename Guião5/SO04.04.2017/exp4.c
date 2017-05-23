#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <ctype.h>
#include <sys/wait.h>

int main(){
    int pfd[2],n,i=0;

    pipe(pfd);

    if(fork()==0){

        close(pfd[0]);

        dup2(pfd[1],1);
        close(pfd[1]);

        execlp("ls","ls","/etc",NULL);
        perror("ls");
        _exit(1);

    }else{
        close(pfd[1]);

            dup2(pfd[0],0);
            close(pfd[0]);
            execlp("wc","wc","-l",NULL);

            _exit(1);

            wait(NULL);

    }
}
