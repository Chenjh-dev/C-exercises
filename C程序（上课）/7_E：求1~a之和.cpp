/*
求1~a之和

题目描述
求以下三数的和,保留2位小数 1~a之和 1~b的平方和 1~c的倒数和

输入
a b c

输出
1+2+...+a + 1^2+2^2+...+b^2 + 1/1+1/2+...+1/c

样例输入
100 50 10

样例输出
47977.93

*/

#include<stdio.h>

int main()
{
	int a,b,c,i;
	float answer=0.0;
	scanf("%d %d %d",&a,&b,&c);
	for(i=1;i<=a;i++){
		answer+=i;
	}
	for(i=1;i<=b;i++){
		answer+=i*i;
	}
	for(i=1;i<=c;i++){
		answer+=1.0/i;
	}
	printf("%.2f\n",answer);
}
