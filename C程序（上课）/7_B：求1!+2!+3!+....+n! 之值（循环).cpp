/*
求1!+2!+3!+....+n! 之值（循环)

题目描述
求Sn=1!+2!+3!+4!+5!+…+n!之值，其中n是一个数字。

输入
n

输出
和

样例输入
5

样例输出
153
*/

#include<stdio.h>

int main()
{
	int n,i,j,k,answer=0;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		k=1;
		for(j=1;j<=i;j++){
			k*=j;
		}
		answer+=k;
	}
	printf("%d",answer);
}
