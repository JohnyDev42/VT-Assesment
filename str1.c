#include<stdio.h>
#include<stdlib.h>
int main()
{
	char c;
	char *str=(char*)malloc(sizeof(char));
	int size=0;
	c=getchar();
	while(c!='\n')
	{
		c++;
		str=(char*)realloc(str,sizeof(char));
		str[size]=c;
		size++;
		c=getchar();
	}
	printf("%s\n",str);

}

