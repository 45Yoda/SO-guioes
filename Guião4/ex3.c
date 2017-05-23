#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <string.h>

#define N 45

int main(int argc, char** argv){
    char buf[45];
    int in,out;
    int fdi=0;
    int fdo=0;
    int i=1;

    while(i<argc){
        if(strcmp(argv[i],"-i")==0){
            in = i+1;
            i+=2;
            fdi=1;
        }
        else if(strcmp(argv[i],"-o")==0){
            out = i+1;
            i+=2;
            fdo=1;
        }
        else break;
    }

    if(fdi) fdi=open(argv[in],O_RDONLY);
    if(fdo) fdo=open(argv[out],O_CREAT | O_WRONLY | O_TRUNC, 0644);

    if(!fork()){
        if(fdi!=0 || fdo!=0){
            if(fdi!=1 && fdi!=0){
                dup2(fdi,0);
                close(fdi);
            }
            if(fdo!=1 && fdo!=0){
                dup2(fdo,1);
                close(fdo);
            }
        }
        execvp(argv[i],argv+i);
        perror(argv[i]);
        _exit(1);
    }
    else wait(NULL);

    close(fdi);
    close(fdo);

    return 0;
}
