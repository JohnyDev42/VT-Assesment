#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
	int data;
	struct Node *pre,*next;
}List;
struct Node * swap(struct Node * p,struct Node *q)
{
/*if(i->pre)  i->pre->next = j;
    if(j->pre)  j->pre->next = i;
    if(i->next) i->next->pre= j;
    if(j->next) j->next->pre= i;
    List* temp;
    temp = i->pre;
    i->pre = j->pre;    
    j->pre = temp;
    temp = i->next;
    i->next= j->next;    
    j->next= temp;
*/

/*	int temp=p->data;
	p->data=q->data;
	q->data=temp; 
	p->pre=q; */
	printf("p:%p q:%p\n",p,q);
	struct Node *temp = p->pre;
	p->pre = q;
	q->pre = temp;
	temp=p->next;
	p->next=q->next;
	q->next=p;
	printf("%d %d\n",p->data,q->data);

		
	
}
	
struct Node *bubbleSort(struct Node **head)
{
	int changed=1,i=0;
	struct Node *p,*q=NULL;
	List * temp=(struct Node*)malloc(sizeof(struct Node));
	if(temp==NULL)
		printf("fail");
	temp->next=*head;
	printf("Inside");
	printf("%d\n",(*head)->data);
	do{
		changed=0;
		p=(*head);
		while(p->next!=q)
		{
			if(p->data > p->next->data)
			{
				swap(p,p->next);
				changed=1;
			}
			p=p->next;
		}
		q=p->next;
	}while(changed);
} 
/*	if((*head)!=NULL && (*head)->next!=NULL)
	{

		while(changed)
		{
			printf("%d",i++);
			changed=0;
			q=temp;
			p=temp->next;
			while(q->next!=NULL)
			{
				if(p->data>p->next->data)
				{
					q->next=swap(p,p->next);
					changed=1;
				}
				q=p;
				if(p->next!=NULL)
					p=p->next;
			}
		}
	}
	p=temp->next;
	free(temp);
	return p;

	
}
		
*/
void print(struct Node *head)
{
	struct Node *temp=head;
	printf("\nList from Front\n");
	while(head!=NULL)
	{
		printf("%d ",head->data);
		temp=head;
		head=head->next;
	}
	printf("\nList from Back\n");
	while(temp!=NULL)
	{
		printf("%d ",temp->data);
		temp=temp->pre;
	}
	printf("\n");
}

void insert(struct Node **head,int data)
{
	struct Node *new=(struct Node *)malloc(sizeof(struct Node));
	new->data=data;
	new->pre=new->next=NULL;
	if(*head==NULL)
		*head=new;
	else
	{
		(*head)->pre=new;
		new->next=*head;
		*head=new;
	}
}
		
int main()
{
	struct Node * head=NULL;
	insert(&head,5);
	insert(&head,2);
	insert(&head,7);
	insert(&head,3);
	insert(&head,9);
	bubbleSort(&head);
	print(head);
}
