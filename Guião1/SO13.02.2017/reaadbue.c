#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <stdio.h>

ssize_t readln(int fildes, char *buf, size_t nbyte){
    int i=0;

    while(i<nbyte-1 &&
         read(fildes, buf+i,1)>0 &&
         buf[i] != '\n'){
         i++;
    }
    if(i>=nbyte)
           buf[i] = 0;
    else
           buf[i+1] = 0;

    return i;
}

int main(){
    int n, i=1;
    char buffer[1000];
    while( (n=readln(0, buffer, 1000))>0)
         printf("%5i %s", i++, buffer);

}
