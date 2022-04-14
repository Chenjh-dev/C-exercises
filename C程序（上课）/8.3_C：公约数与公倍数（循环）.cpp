/*
公约数与公倍数（循环）

题目描述
输入两个正整数m和n，求其最大公约数和最小公倍数。

输入
两个整数

输出
最大公约数，最小公倍数

样例输入
5 7

样例输出
1 35

*/

#include<stdio.h>

int main()
{
	int m,n,i,k,a1=1,a2;
	scanf("%d%d",&m,&n);
	if(m<n){
		k=m;
		m=n;
		n=k;
	}
	for(i=1;i<=n;i++){
		if(m%i==0&&n%i==0){
			a1=i;
		}
	}
	for(i=m;;i++){
		if(i%m==0&&i%n==0){
			a2=i;
			break;
		}
	}
	printf("%d %d",a1,a2);
}
