#include  "ex5.c"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <fcntl.h>

int main(int argc, char* argv[]){
    int i = 1;
    while (i!= argc){
        int fd = open(argv[i],O_RDONLY);
        int n, l = 0;
        char linha[512], prefixo[16];
        i++;
        if (fd == -1){
                perror(argv[i]);
                continue;
        }
        while((n= readln(fd,linha,sizeof(linha))) >0){
                sprintf(prefixo, "%8d",++l);
                write(1, prefixo, strlen(prefixo));
                write(1,linha,n);
            }
        close(fd);

    }

}
