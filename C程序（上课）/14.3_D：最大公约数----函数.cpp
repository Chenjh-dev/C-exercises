/*

最大公约数----函数
时间限制: 1 Sec  内存限制: 128 MB
提交: 182  解决: 155
[提交][状态][讨论版]
题目描述

写两个函数，分别求两个整数的最大公约数和最小公倍数，用主函数调用这两个函数，并输出结果两个整数由键盘输入。

输入

两个数

输出

最大公约数 最小公倍数

样例输入

6 15

样例输出

3 30
*/

#include<stdio.h>

int findmax(int a,int b)
{
	int i,k,m;
	k=a>b?b:a;
	for(i=1;i<=k;i++){
		if(a%i==0&&b%i==0){
			m=i;
		}
	}
	return m;
}

int findmin(int a,int b)
{
	int i,k;
	k=a>b?a:b;
	for(i=k;i%a!=0||i%b!=0;i++){}
	return i;
}

int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	printf("%d %d\n",findmax(a,b),findmin(a,b));
}
