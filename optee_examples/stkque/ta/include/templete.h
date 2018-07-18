#include<stdio.h>
#include<stdlib.h>


struct stack
{
        int top; 
        unsigned capacity;
        int * arr;
};

struct stack * createStack(unsigned cap);
int isEmptyS(struct stack *stack2);
int isFullS(struct stack *stack1);
int peekS(struct stack * st);
int popS(struct stack * st);
void pushS(struct stack * stack1,int data);
