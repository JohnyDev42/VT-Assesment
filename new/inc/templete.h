#include<stdio.h>
#include<stdlib.h>

struct queue
{
        int front,rear,size;
        unsigned capacity;
        int * arr;
};
struct stack
{
        int top; 
        unsigned capacity;
        int * arr;
};
struct queue *createQ(unsigned capacity);
int isFullQ(struct queue * q);
void enque(struct queue *q,int data);
struct stack * createStack(unsigned cap);
int isEmptyS(struct stack *stack2);
int isFullS(struct stack *stack1);
int peek(struct stack * st);
int pop(struct stack * st);
void push(struct stack * stack1,int data);
