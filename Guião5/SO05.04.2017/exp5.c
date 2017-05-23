#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <ctype.h>
#include <sys/wait.h>

int main(){
    int n=3;
    char* cmds[400]={"grep -v ˆ# /etc/passwd | cut -f7 -d: | uniq | wc -l"};
    int i, seguinte[2],anterior;
    char* args;

    for(i=0;i<n;i++){

        if(i<n-1)
        pipe(seguinte);



        if(fork()==0){
            //Filho
            if(i>0){
                dup2(anterior,0);
                close(anterior);
            }
            if(i<n-1){
                dup2(seguinte[1],1);
                close(seguinte[1]);
            }
            args= strtok(cmds[i]," ");
            execvp(args[0],args);
            perror(args[0]);
            _exit(1);
        }
        //Pai
        if(i<n-1) close(seguinte[1]);
        if(i>0) close(anterior);
        anterior=seguinte[0];
    }
}
