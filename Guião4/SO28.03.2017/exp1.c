#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(){
	int fd;
	printf("Antes\n");

	fd= open("teste.txt",O_CREAT|O_WRONLY|O_TRUNC, 0600);
	dup2(fd,1);
	close(fd);
	printf("Depois\n");
}
