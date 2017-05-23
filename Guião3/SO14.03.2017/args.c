#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]){
        int i;
        for(i=0;i<argc;i++)
            printf("argv[%d]=%s\n",i,argv[i]);

}
