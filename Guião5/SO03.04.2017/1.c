#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>


int main(int argc, char* argv[]){
        int pd[2];
        //nao perserva fronteiras
        char* msg1 = "mensagem  ";
        char* msg2 = "qualquer\n";
        pipe(pd);
        if(fork()==0){
            char buffer[1024];
            int n;
            close(pd[1]);
            while(1){
                close(pd[1]);
                n=read(pd[0],buffer,sizeof(buffer));
                if(n<=0) break;
                write(1,buffer,n);
            }
            close(pd[0]);
            _exit(0);
        }
        close(pd[0]);
        sleep(5); //bloqueia o read até ter sido escrita no pipe
        write(pd[1],msg1,strlen(msg1));
        //sleep(5);
        write(pd[1],msg2,strlen(msg2));
        close(pd[1]);
        return 0;
}
