/* Program for counting no. of occurance of same data in a lIst */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <signal.h>
#include <unistd.h>
struct LL{
	int data;
	struct LL * next;
};
sigset_t set;
int avail=1;
int sig;

pthread_mutex_t mtx=PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond=PTHREAD_COND_INITIALIZER;
int *sigptr=&sig;
void push(struct LL **,int);
void reverse(struct LL **);
void printLL(struct LL*);

void * odd(void *);

void * even(void *);
pthread_t p1,p2;
void handler(int sig)
{
	printf("Recieved %d",sig);

}
int main()
{
	int i,n,x,y;
	struct LL * head=NULL;


//	signal(SIGINT,handler);
//	pthread_mutex_init(&mtx,NULL);
//	signal(SIGUSR2,handler);
//	pthread_t p1,p2;
//	sigaddset(&set,SIGINT);
//	sigaddset(&set,SIGUSR1);
//	sigprocmask(SIG_BLOCK, &set, NULL);
	pthread_create(&p1,NULL,&odd,&head);
	pthread_create(&p2,NULL,&even,&head);	
//	pthread_kill(p1,2);
//	sigprocmask(SIG_UNBLOCK, &set, NULL);
//	while(1){
//		pthread_kill(p1,SIGINT);
//		sleep(1);
//		pthread_kill(p2,SIGINT);
//		sleep(1);
//	}
	pthread_join(p1,NULL);
	pthread_join(p2,NULL);
	printLL(head);
}

void push(struct LL **root,int data)
{
	struct LL * temp=(struct LL *)malloc(sizeof(struct LL));
	temp->data=data;
	temp->next=NULL;
	if(*root==NULL)
	{
		*root=temp;
		return;
	}
	temp->next=*root;
	*root=temp;
}
void printLL(struct LL * root)
{
	while(root!=NULL)
	{
		printf("%d ",root->data);
		root=root->next;
	}
	printf("\n");
}


void * odd(void *head)
{
	int i=1,sig;
	sleep(2);
	
	signal(SIGINT,handler);
	while(1){
//		if(sigaddset(&set,SIGUSR2)==-1)
//			printf("sigadd1 fail\n");
		push((struct LL**)head,i);
			i+=2;
			pthread_kill(p2,SIGINT);

			if(i>10)
			pthread_exit(0);

			pause();
		}
	
//		if(sigwait(&set,sigptr)!=0)
//			printf("wait1 fail\n");
	//	raise(10);
	
}
void *even(void * head)
{
	int i=2,sig;
	sigset_t set1;

	(void)signal(SIGINT,handler);
	while(1){
//		if(sigaddset(&set1,SIGUSR1)==-1)
//			printf("sigadd1 fail\n");
//		if(sigwait(&set1,&sig)!=0)
//			printf("wait2 fail\n");
			push((struct LL **)head,i);
		i+=2;

		pthread_kill(p1,SIGINT);
		
		if(i>10)
			pthread_exit(0);
		sigwait()
	//	sleep(1);


//		raise(2);
	}
}
