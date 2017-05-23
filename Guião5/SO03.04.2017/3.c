#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(){
    int pd[2],n;
    char buffer[1024];
    pipe(pd);
    if(fork()==0){
        close(pd[1]);
        dup2(pd[0],0);
        close(pd[0]);
        execlp("wc","wc",NULL);
        _exit(1);
    }
    close(pd[0]);
    while((n=read(0,buffer,sizeof(buffer)))>0)
            write(pd[1],buffer,n);
    close(pd[1]);
    return 0;
}
