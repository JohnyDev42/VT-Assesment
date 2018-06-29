#include<stdio.h>
#include<stdlib.h>
struct node 
{
	int data;
	struct node * next;
};
struct node * tail;
void swapLL(struct node **head_ref,int x)
{
	int i=1;
	struct node *p,*c,*n;
	c=*head_ref;
	p=NULL;
	n=c->next;
	if(x==1)
	{
		(*head_ref)->next=n->next;
		n->next=(*head_ref);
		*head_ref=n;
		return;
	}

	while(i<x)
	{
		p=c;
		c=c->next;
		n=c->next;
		i++;
		if(c==NULL || c->next==NULL){
			printf("Not possible:Next node not exist\n");
			return;
		}
	}
	p->next=n;
	c->next=n->next;
	n->next=c;
}

void push(struct node **head_ref,int data)
{
	struct node * new;
	new=(struct node *)malloc(sizeof(struct node));
	new->data=data;
	new->next=NULL;
	if(*head_ref==NULL){
		*head_ref=new;
		tail=*head_ref;
		return;}
	tail->next=new;
}
void print(struct node *head)
{
	struct node *temp=head;
	if(head==NULL)
		printf("Empty");
	while(temp!=NULL)
	{
		printf("%d ",temp->data);
		temp=temp->next;
	}
	printf("\n");
}
int main()
{
	struct node * head=NULL;
	int n,a,x,i;
	printf("How many Numbers");
	scanf("%d",&x);
	for(i=0;i<x;i++)
	{
		printf("Enter the list data:");
		scanf("%d",&a);
		push(&head,a);
	}
//	push(&head,1);
//	push(&head,2);
//	push(&head,3);
//	push(&head,4);
//	push(&head,5);
	print(head);
	printf("Enter the node number to swap with next node:");
	scanf("%d",&n);
	
	swapLL(&head,n);
	print(head);
}
	

