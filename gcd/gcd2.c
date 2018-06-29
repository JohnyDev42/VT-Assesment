#include<stdio.h>
int gcd(int a,int b)
{
//	int x,y;
//	x=a;y=b;
	
	if(b!=0)
		gcd(b,a%b);
	else 
		{
		if(a<0)
			a=-a;
		return a;
		}	
//	return i;
}
	
	
int main()
{
	int a,b;
	printf("Enter the two Numbers:");
	scanf("%d%d",&a,&b);
	printf("G.C.D=%d\n",gcd(a,b));
}

