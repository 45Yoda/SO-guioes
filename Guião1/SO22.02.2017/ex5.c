#include <unistd.h>

//ssize_t (inteiros com sinal)
//typedef int ssize_t;
//typedef unsigned size_t;

/* versao 1
ssize_t readln(int fd, void* buf, size_t nbyte){
    int n = 0, r;
    while(n<nbyte && (r=read(fd, ((char*)buf)+n, 1))==1 && *((char*)buf+n) != '\n')
         n++;
    return r ==-1 ? -1 : n;
}
*/
//versao 2
ssize_t readln(int fd, void* buf, size_t nbyte){
    int n = 0, r;
    char* p = (char*)buf;
    while(n<nbyte && (r=read(fd, p+n, 1))==1 && p[n] != '\n')
         n++;
    return r ==-1 ? -1 : (p != 0 && p[n] == '\n' ? n+1 : n);
}

#ifdef __TEST
int main(){
    char linha[512];
    int n;
    n=readln(0,linha,sizeof(linha));
    write(1,linha,n);
    return 0; //EXIT_SUCCESS
}
#endif
