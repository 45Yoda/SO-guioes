#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){
	int fd;
	printf("Antes\n");

    if(fork()==0){
        fd= open("myteste.txt",O_CREAT|O_WRONLY|O_TRUNC, 0600);
        dup2(fd,1);
        close(fd);
        printf("Depois filho\n");
    }else{
        wait(NULL);
        printf("Depois pai\n");
    }

}
