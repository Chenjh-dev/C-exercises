#include<stdio.h>
int main()
{
	int a,b,main;
	printf("Please input two numbers ");
	scanf("%d%d",&a,&b);
	printf("The bigger of the two numbers is ");
	if (a>b)
	printf("%d",a);
	else printf("%d",b);
	printf("\n");
}
