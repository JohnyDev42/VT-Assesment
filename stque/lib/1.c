#include "../inc/templete.h"
struct stack * createStack(unsigned cap)
{
	struct stack * new=(struct stack*)malloc(sizeof(struct stack));
	new->top=-1;
	new->capacity=cap;
	new->arr=(int *)malloc((new->capacity)*sizeof(int));
	return new;
}
int isEmptyS(struct stack *stack)
{
	return stack->top==-1;
}
int isFullS(struct stack *stack1)
{
	return stack1->capacity-1==stack1->top;
}
void push(struct stack * stack1,int data)
{
	if(isFullS(stack1))
	{
		printf("Stack is Full\n");
		return;
	}
	stack1->arr[++stack1->top]=data;	
}
int peek(struct stack * st)
{
	return st->arr[st->top];
}
int pop(struct stack * st)
{
	if(isEmptyS(st))
		return -1;
	return st->arr[st->top--];
}
