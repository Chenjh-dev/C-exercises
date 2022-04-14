/*
求组合数的值----函数

题目描述
编制程序，输入m,n(M>=n>=0)后,计算下列表达式的值并输出：	   m!         
                                                        _________
                                                        n! (m-n)!
要求将计算阶乘运算的函数写为fact(n),函数返回值的类型为float

输入
m n

输出
对应表达式的值

样例输入
2 1

样例输出
2

*/

#include<stdio.h>

float fact(int n)
{
	float a=1;
	int i;
	for(i=2;i<=n;i++){
		a*=i;
	}
	return a;
}

int main()
{
	int m,n,k;
	scanf("%d%d",&m,&n);
	printf("%d",(int)(fact(m)/fact(n)/fact(m-n)));
}
