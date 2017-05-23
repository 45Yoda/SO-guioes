#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <ctype.h>
#include <sys/wait.h>

int main(){
    int pfd[2],n,i=0;
    char buf[100];
    char dados[1024];

    pipe(pfd);

    if(fork()==0){
        close(pfd[1]);

        dup2(pfd[0],0);
        close(pfd[0]);

        execlp("wc","wc",NULL);
        perror("wc");
        _exit(1);

    }else{
        close(pfd[0]);
        write(pfd[1],"pal1 pal2\npal3\n",15);
        close(pfd[1]);
        wait(NULL);
    }
}
