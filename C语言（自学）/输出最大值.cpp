#include <stdio.h>
int main()
{
int a,b,max;
printf("input two numbers:");
scanf("%d%d",&a,&b);
max=a;
if(max<b)
max=b;
printf("max=%d\n",max);
}
