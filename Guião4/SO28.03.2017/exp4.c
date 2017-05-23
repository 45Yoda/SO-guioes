#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

int main(int argc,char *argv[]){
	int fd;
	// ./exp4 -i teste.txt wc -w
    if(!strcmp(argv[1],"-i")){
        fd=open(argv[2],O_RDONLY);
		dup2(fd,0);
        close(fd);
        execvp(argv[3],argv+3);
		_exit(1);
    }
	// ./exp4 -o teste.txt wc -w
	if(!strcmp(argv[1],"-o")){
		fd= open(argv[2],O_WRONLY);
		dup2(fd,1);
		close(fd);
		execvp(argv[3],argv+3);
		_exit(1);
	}

}
