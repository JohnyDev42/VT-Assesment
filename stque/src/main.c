#include "../inc/templete.h"
int main()
{
	int a;
	printf("Enter the Size of Stack:");
	scanf("%d",&a);
	struct queue * que=createQ(a);
	int x,y;
	struct stack * st1=createStack(5);
/*        push(st1,1);
        push(st1,2);
        push(st1,3);
	push(st1,4);
	push(st1,5);*/
        struct stack * st2=createStack(5);
	

/*	while(isEmptyS(st1)!=1)
	{
		x=peek(st1);
		push(st2,x);
		pop(st1);
	}
	for(x=0;x<5;x++)
		printf("%d ",st2->arr[x]);
	printf("\n"); */
begin:
	printf("Enter Choice:\n1.Push\n2.POP\n3.EXIT\n");
	scanf("%d",&x);
	switch(x)
	{
		case 1:printf("Data?");
			scanf("%d",&a);
			if(isFullS(st1)==1)
				printf("Stack is Full\n");
			push(st1,a);
			goto begin;
		case 2:if((isEmptyS(st2)==1)&&(isEmptyS(st1)==1)){
                                printf("Stack is Empty\n");
				goto begin;
			}
			if(isEmptyS(st2)==1){
			while(isEmptyS(st1)!=1)
			{
			y=peek(st1);
			push(st2,y);
			pop(st1);
			}
			}
			printf("Data:%d\n",peek(st2));
			pop(st2);
		/*	if((isEmptyS(st2)==1)&&(isEmptyS(st1)==1))
				printf("Stack is Empty\n");*/
			goto begin;
		case 3:return 0;
	}
	
}
