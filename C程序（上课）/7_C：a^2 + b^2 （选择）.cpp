#include<stdio.h>

int main()
{
	int x,y,a;
	scanf("%d %d",&x,&y);
	a=x*x+y*y;
	if(a>100){
		printf("%d",a/100);
	}
	else{
		printf("%d",a);
	}
}
