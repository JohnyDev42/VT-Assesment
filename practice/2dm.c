#include<stdio.h>
#include<stdlib.h>
int main()
{
	int i,j,r=4,c=3,count=0;
	int *ptr[r];
	for(i=0;i<r;i++)
		ptr[i]=(int*)malloc(sizeof(int)*c);
	for(i=0;i<r;i++)
		for(j=0;j<c;j++)
			ptr[i][j]=count++;
	for(i=0;i<r;i++)
		for(j=0;j<c;j++)
			printf("%d ",ptr[i][j]);
	
	printf("ptr[0]=%p\n",ptr[0]);
	for(i=0;i<r;i++)
		free(ptr[i]);
	free(ptr[0]);
	ptr[1][3];
	printf("%d\n",ptr[1][3]);
	printf("ptr[0]=%p\n",ptr[0]);
	return 0;
}
