#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define N 45

int mysystem(char* buf){
    char* string;
    char* exec_args[N];
    int i=0,fork_ret,exec_ret,wait_ret,status,res;
    int flag=0;

    string = strtok(buf, " \n");

    while(string!=NULL){
        exec_args[i] = string;
        string = strtok(NULL, " \n");
        i++;
    }

    exec_args[i]=NULL;

    if(!strcmp(exec_args[i-1],"&")) flag=1;

    fork_ret=fork();
    if(fork_ret==0){
        if(flag){
            exec_args[i-1]=NULL;
            res=1;
        }

        exec_ret = execvp(exec_args[0],exec_args);
        _exit(exec_ret);
    }
    else if(!flag){
            if(fork_ret != 0){
                wait_ret = wait(&status);
                if(WIFEXITED(status))
                    res = WEXITSTATUS(status);
            }
            else res=-1;
    }
    return res;
}

int main(int argc, char** argv){
    char buf[N];
    char* line;
    int n;

    while(1){
        n=read(0,buf,N);
        line=strtok(buf,"\n");
        if(n==0 || (strcmp(buf,"exit"))==0)
            return 1;
        int res = mysystem(line);
        if(res==-1){
            printf("erro\n");
            break;
        }
    }
    return 0;
}
