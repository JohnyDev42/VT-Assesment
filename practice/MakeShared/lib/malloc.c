#include<stdio.h>
#include"../include/malloc.h"
void * mymalloc(int size)
{
	printf("My malloc is called\n");
	return NULL;
}

