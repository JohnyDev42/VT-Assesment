#include<stdio.h>
#include<stdlib.h>
#include"../include/malloc.h"
#include"../include/calloc.h"
int main()
{
	int *p=malloc(4);
	int *q=calloc(2,sizeof(int));
	printf("Hello World!!!\n");
}
