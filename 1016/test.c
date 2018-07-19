#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int data;
	struct node *next;
	struct node *next_next;
}node;
node *head = NULL;
node *tail = NULL;
void insert_node(node * ptr)
{
	node * temp,*ptemp;
	if(head==NULL)
	{
		head=ptr;
		return;
	}
	temp=head;
/*	if(temp->next!=NULL){
		ptemp=temp;
		temp=temp->next;
	} */
	while(temp->next !=NULL)
	{
		if(temp->next->next != NULL)
		{
		temp->next_next = temp->next->next;
		}
		temp=temp->next;
	}
	temp->next=ptr;
}

void print_LL(node * root)
{
	node *temp=root;
	while(temp !=NULL)
	{
		printf("%d ",temp->data);
		temp=temp->next;
	}
	printf("\n");
}


void swap_node(node * ptr)
{
	node *temp=head;
	node *tmp = ptr;
	node *ntmp = ptr->next;
	node *nntmp = ptr->next_next;	
	node * nptr;
	node * nnptr;
	printf("nptr=%p\n",ntmp);
	if(ptr->next==NULL)
	{
		printf("Next node not Available\n");
		return;
	}
	if(ptr == head)
	{
		
		ptr->next=ptr->next->next;
		ptr->next_next = head->next->next_next;
		ntmp->next = ptr;
		ntmp->next_next = head->next;
		head = ntmp;
		return;
	}
	
		while(temp->next == ptr)
		{
		temp->next= tmp->next;
		temp->next_next = tmp;
		ptr->next->next = ptr;
		ptr->next->next_next = ptr->next_next;
	//	ptr->next = tmp->next->next;
	//	ptr->next_next = tmp->next->next_next;
		
	//	tmp->next = tmp->next->next;
	//	tmp->next_next = tmp->next->next_next->next;
	//	ntmp->next = tmp;
	//	ntmp->next_next = ntmp->next;
	//	ptr->next_next = ptr->next->next_next;
	//	ptr->next=ptr->next->next;
		
	//	temp=temp->next;
		}
	
	
	
} 
void delete_node(node *ptr)
{
	node * temp=head;
	if(ptr==NULL)
		return;
	if(ptr==head)
	{
		head=ptr->next;
		free(ptr);
	}
	else
	{
		while(temp->next != ptr)
			temp=temp->next;
		temp->next = ptr->next;
		temp->next_next = ptr->next_next;
		free(ptr);
	}
}
	
//Driver Program>>>>>>			
int main()
{
	int n,a,i;
	node *temp=NULL;
	printf("Enter the Number of list elements to be Inserted:");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("Enter data:");
		scanf("%d",&a);
		node *temp =(node *)malloc(sizeof(node));
		temp->data=a;
		temp->next=NULL;
		temp->next_next=NULL;
		insert_node(temp);
	}
	printf("List is:");
	print_LL(head);
	printf("%d\n",head->next_next->next->data);
	printf("After swapping:\n");
	swap_node(head->next);
	print_LL(head);
	printf("Deleting 4th node\n");
	delete_node(head->next->next->next);
	delete_node(head->next_next->next_next);
	print_LL(head);
}



