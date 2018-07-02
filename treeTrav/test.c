#include<stdio.h>
typedef union test{
	double dl;
	char ch;
	int in;
}tst;

int main()
{
	tst a;
	 a.dl=5.3;
	a.ch='a';
	a.in=1;
	printf("%lf %c %d\n",a.dl,a.ch,a.in);
}	
