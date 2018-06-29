#include<stdio.h>
int gcd(int a,int b)
{
	static int i=1;
	if(a==b)
		return a;
	if(a<b && (b%a==0))
		return a;
	else
		if(a>b && (a%b==0))
			return b;
	if(a<b)
		x=a/i++;
	else
		y=b/i++;
	gcd(a,b);
	return i;
}
	
	
int main()
{
	int a,b;
	printf("Enter the two Numbers:");
	scanf("%d%d",&a,&b);
	printf("G.C.D=%d\n",gcd(a,b));
}

