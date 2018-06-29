#include<stdio.h>
#include<stdbool.h>
#include<math.h>
bool isPrime(int a,int b)
{
	if(a==1||a==0)
		return 0;
	if(b==1)
		return 1;
	else{	
		if(a%b==0)
			return 0;
		else
			return isPrime(a,b-1);
	}
}
void printPrime(int m,int n)
{
	int i,t;
	if(m>n)
	{	i=m;
		m=n;
		n=i;
	}
	for(i=m;i<=n;i++)
	{
		t=i;
		if(i<0)
			t=-i;
		if(isPrime(t,t/2)==1)
		printf("%d ",i);
	}
	printf("\n");
}
int main()
{
	int m,n;
	printf("Enter the range:");
	scanf("%d%d",&m,&n);
	printf("Prime Numbers in range %d & %d are:\n",m,n);
	printPrime(m,n);
}
