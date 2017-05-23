#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void f(){
    write(1,"Ha ha!\n",7);
}

void g(){
    write(1,"ALARM!\n",7);
    alarm(1);
}

int main(){
    int i=0;
    signal(SIGINT,f);
    //signal(SIGTERM,f);
    signal(SIGALRM,g);
    alarm(1);
    while(1){
        pause();
    }
}
