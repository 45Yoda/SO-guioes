#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>

int mysystem(char* cmd){

}


int main(){
    printf("Antes \n");
    mysystem("ls -la"); // -> segmentation fault(bus arror)
    mysystem(cmd);
    //mysystem("ls -la *-c"); -> man glob

    printf("Depois\n");
}
