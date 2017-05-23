
lsof list of open files

echo "ola" > /dev/pts/2
ola para bash 2


dup2 duplica o write no ficheiro;

//importante!
fd= open("teste.txt",O_CREAT|O_WRONLY|O_TRUNC, 0600);
dup2(fd,1);
close(fd);

fork() cria um filho tmb redirecionado para o ficheiro e nao para o terminal

//filho escreve no ficheiro pai no terminal
int main(){
	int fd;
	printf("Antes\n");
    if(fork()==0){
        fd= open("teste.txt",O_CREAT|O_WRONLY|O_TRUNC, 0600);
	    dup2(fd,1);
	    close(fd);
        printf("Depois filho\n");
    }else{
	printf("Depois pai\n");
     }
}


//substituindo (a partir do printf) o filho escreve no ficheiro o resultado de um ls
execlp("ls","ls",NULL);
perror("ls");
_exit(1);
}else{
wait(NULL);


//ver wc

// usar o do lado esquerdo
dup2 (fd,1) <=> close(1); dup(fd);
