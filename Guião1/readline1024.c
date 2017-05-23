#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

struct buffer_t{
 char* buf;
 int max, j, n, fd;
};

int creat_buffer (int fd,struct buffer_t* p, int max){
   p->buf = malloc(max);
   p->max=max;
   p->j=0;
   p->fd=fd;
   return 0;
}

int destroy_buffer (struct buffer_t* p){
  free(p->buf);
  return 0;
}

int readln(struct buffer_t* p, char *line, int max){
      int i=0;

      while(i<max-1){
         if(p->j == p->n){
              p->n = read (p->fd,p->buf,p->max);
              p->j = 0;
         }
         if(p->n == 0) break;

         line[i]=p->buf[p->j];
         p->j++;

         if(line[i]=='\n') break;
         i++;
      }
      if (i<max) line[i]=0;
      return p->n;
}




int main (int argc, char** argv){
   int fd,n,k=1;
   char line[100];
   struct buffer_t buff;

   fd = open ("exem.txt",O_RDONLY);

   creat_buffer(fd, &buff, 1024);

   buff.n=read(fd,buff.buf,1024);

   while(readln(&buff,line,100)>0){
   printf("%d |%s| \n",k,line);
   k++;
   }
   destroy_buffer(&buff);
   close(fd);

   return 0;
}
