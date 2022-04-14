#include<stdio.h>
void main()
{
	int i,k,p;
	int a[20]={1,1};
	printf("         1=%d     ",a[0]);
	printf("     2=%d  ",a[1]);
	for(i=2;i<20;i++)
	{a[i]=a[i-1]+a[i-2];
	k=i+1;
	printf("%10d=%d",k,a[i]);
	if(k%5==0)
		printf("\n");
	}
}
