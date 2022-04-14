/*
n!（循环）

题目描述
计算n!，就是计算1*2*3*...*n的乘积。注意0！=1。

输入
n的值

输出
n!的值

样例输入
5

样例输出
5!=120

*/


#include<stdio.h>

int main()
{
	int n,i,answer=1;
	scanf("%d",&n);
	if(n==0)
		printf("%d!=1",n);
	else{
		for(i=1;i<=n;i++){
			answer*=i;
		}
		printf("%d!=%d",n,answer);
	}
}
