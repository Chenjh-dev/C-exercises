#include<stdio.h>
#include<string.h>

void sort(char *[],int n);
void output(char *p[],int n);

int main()
{
	char *pcity[] = {"WuHan","ShenZhen","BeiJing","ShangHai","NanJing"};

	int    n;

	n= sizeof(pcity)/sizeof(char *);

	sort(pcity,n);
	output(pcity,n);
}

void sort(char *p[],int n)
{
	int   i,j,flag;
	char   *temp;

	for (flag= 1,i=1;i<n &&flag;i++)
		for(flag=0,j=0;j<n-i;j++)
			if(strcmp(p[j],p[j+1])>0)
			{
				temp = p[j];
				p[j] = p[j+1];
				p[j+1] = temp;
				flag=1;
			}
}

void output(char *p[],int n)
{
	int  i;

	puts("Sort Result:");
	for(i=0;i<n;i++)
		puts(p[i]);
}