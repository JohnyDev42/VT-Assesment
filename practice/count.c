/* Program for counting no. of occurance of same data in a lIst */

#include <stdio.h>
#include <stdlib.h>
struct LL{
	int data;
	struct LL * next;
};

void push(struct LL **,int);
int occur(struct LL *,int);
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
	printf("Enter the Data to Check occuracnce:");
	scanf("%d",&y);
	printf("Occurance:%d\n",occur(head,y));
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
int occur(struct LL * root,int y)
{
	int count=0;
	while(root!=NULL)
	{
		if(root->data==y)
			count++;
		root=root->next;
	}
	return count;
}
