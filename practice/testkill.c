#include <stdio.h>
#include <pthread.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

void handle_sigint(int arg){

	sleep(1);
}
void * th1(void * arg){


	pause();
	printf("Hi");
}
int main()
{
	pthread_t p1;
	
	signal(SIGINT,handle_sigint);
	pthread_create(&p1,NULL,th1,NULL);
	while(1){
		pthread_kill(p1,SIGINT);

	}
	pthread_join(p1,NULL);
}

