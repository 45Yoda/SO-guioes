#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <string.h>


int main (int argc, char** argcs){
    int in,out,fdi,fdo;
    int i=1;

    while(i<argc){
    	if(strcmp(argcs[i],"-i")==0){
    		in = i+1;
    		i+=2;
    	}
    	else if(strcmp(argcs[i],"-o")==0){
    			out = i+1;
    			i+=2;
    	}
    	else break;
    }

    fdi=open (argcs[in], O_RDONLY );
	fdo=open (argcs[out], O_CREAT | O_WRONLY | O_TRUNC, 0666);


    if(!fork()){
        dup2(fdi,0);
        close(fdi);
        dup2(fdo,1);
        close(fdo);

        execvp(argcs[i],argcs+i);
        perror(argcs[i]);
        _exit(1);
         }


    return 0;
}
