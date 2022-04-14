/*
迭代法求平方根（循环）

题目描述
用迭代法求 。求a的平方根的迭代公式为： X[n+1]=1/2(X[n]+a/X[n]) 
要求前后两次求出的得差的绝对值少于0.00001。 输出保留3位小数

输入
X

输出
X的平方根

样例输入
4

样例输出
2.000

*/

#include<stdio.h>

int main()
{
	double x,xx,judge=1;
	scanf("%lf",&x);
	xx=x;
	while(judge>=0.00001||judge<=-0.00001){
		judge=(xx+x/xx)/2-xx;
		xx=(xx+x/xx)/2;
	}
	printf("%.3lf",xx);
}
