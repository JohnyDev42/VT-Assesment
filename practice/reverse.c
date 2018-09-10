/* Program for counting no. of occurance of same data in a lIst */

#include <stdio.h>
#include <stdlib.h>
struct LL{
	int data;
	struct LL * next;
};

void push(struct LL **,int);
void reverse(struct LL **);
void printLL(struct LL*);
int main()
{
	int i,n,x,y;
	struct LL * head=NULL;
	printf("Enter the List length:");
	scanf("%d",&n);
	printf("Enter data:");

	for(i=0;i<n;i++)
	{
		
		scanf("%d",&x);
		push(&head,x);
	}	
	printf("before reverse List:");
	printLL(head);
	reverse(&head);
	printf("After Reverse List:");
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
void reverse(struct LL ** root)
{
	struct LL* curr,*next,*prev;
	next=prev=NULL;
	curr=*root;
	while(curr!=NULL)
	{
		next=curr->next;
		curr->next=prev;
		prev=curr;
		curr=next;
	}
	*root=prev;
}
