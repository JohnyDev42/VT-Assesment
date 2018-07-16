#include<stdio.h>
#include<stdlib.h>
int main()
{
	int *ptr=(int *)malloc(4*sizeof(int));
	printf("%d \n",ptr[4]);
}
