#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char cmd[] = "ls -l -a";
    char* args[10];
    int i=0;

    args[i]=strtok(cmd,"\t\n");
    while(args[i]!= NULL){
        args[++i] = strtok(NULL,"\t\n");
    }

    for(i=0;args[i]!=NULL;i++)
        printf("args[%d] = %s\n",i,args[i]);
}
