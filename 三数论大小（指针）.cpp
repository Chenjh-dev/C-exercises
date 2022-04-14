#include <stdio.h>
int paixu(int *p1,int *p2,int *p3);



int main()
{
	int a,b,c,d,i,*p1,*p2,*p3;
	scanf("%d",&d);
	for(i=1;i<=d;i++)
	{
		scanf("%d %d %d",&a,&b,&c);
		p1=&a,p2=&b,p3=&c;
		paixu(p1,p2,p3);
		printf("%d %d %d\n",*p1,*p2,*p3);
	}
	return 0;
}



int paixu(int *p1,int *p2,int *p3)
{
	int n;

	if(*p1<=*p2)
		n=*p1,*p1=*p2,*p2=n;
	if(*p1<=*p3)
		n=*p1,*p1=*p3,*p3=n;
	if(*p2<=*p3)
		n=*p2,*p2=*p3,*p3=n;
	return 0;
}



