#include <stdio.h>
#include <sys/wait.h>
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>

static int conta;
static int tempo;

void my_alarm(int n){
	tempo++;
	alarm(1);
}

void print_quit(){
	printf("\t%d\n",conta);
	_exit(0);
}

void nada(){
	conta++;
	printf("\t%d\n",tempo);
}

int main(){
	int n;
	conta = 0;
	tempo = 0;

	signal(SIGALRM,my_alarm);
	signal(SIGINT,nada);
	signal(SIGQUIT,print_quit);
	alarm(1);
	while(1){pause();}
	return 0;
}
