#include <stdio.h>
#include <unistd.h>

int main(){
    printf("Filho - %d\n",getpid());
    printf("Pai   - %d\n",getppid());
    return 0;
}
