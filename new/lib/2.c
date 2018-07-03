#include "../inc/templete.h"

struct queue *createQ(unsigned capacity)
{
	struct queue *new=(struct queue *)malloc(sizeof(struct queue));
	new->capacity=capacity;
	new->front=new->size=0;
	new->rear=new->capacity-1;
	new->arr=(int *)malloc(new->capacity*sizeof(int));
	return new;
}
int isFullQ(struct queue * q)
{
	return q->size==q->capacity;
}
void enque(struct queue *q,int data)
{
	if(isFullQ(q))
		return;
	q->rear=(q->rear+1)%q->capacity;
	q->arr[q->rear]=data;
	q->size=q->size+1;
}
