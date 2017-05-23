#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

#define N 100

int readln(int fd, char *buf, int max){
         int n;
         int i=0;

         for(i=0; i<max-1;i++){

         n = read(fd,buf+i,1);
         if(n==0) return 0;
         if(buf[i]=='\n') return i;

         }

         return i;
}


int main (int argc, char** argv){

   int n,i=1,numero=49,p=5;
   char buf[N];

   while(1){
     //Mete nojo***************
     for(int j=0;j<8;j++){
      if(j>p)buf[j]=' ';
      if(i<10){
         if(j<p)buf[j]=' ';
         if(j==p){
                  buf[j]=numero;
                  numero++;}
        }
      else {buf[p-1]=49;
            numero=48;
            buf[p]=numero;
            i=1;}
     }
     //************************
     if(argc == 1){
      n = readln (0,(buf+8),N);

      if(n<=0) return 0;

      write(1,buf,n+9);

      i++;
     }
     else {
       printf("Erro\n");
       return 1;
     }
}
   return 0;
}
