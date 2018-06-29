#include<stdio.h>
int gcd(int a,int b)
{
	static int i=2;
//	int x,y;
//	x=a;y=b;
	if(a%b==0)
		return b;
	if(b%a==0)
		return a;
	if(a<b && (a%i==0))
		i=a/i;
	else
		if(a>b && (b%i==0))
			y=b/i;
	i++;
	gcd(,y);
//	return i;
}
	
	
int main()
{
	int a,b;
	printf("Enter the two Numbers:");
	scanf("%d%d",&a,&b);
	printf("G.C.D=%d\n",gcd(a,b));
}

