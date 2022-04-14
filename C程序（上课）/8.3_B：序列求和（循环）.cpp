/*
序列求和（循环）

题目描述
有一分数序列： 2/1 3/2 5/3 8/5 13/8 21/13...... 
求出这个数列的前N项之和，保留两位小数。

输入
N

输出
数列前N项和

样例输入
10

样例输出
16.48

*/

#include<stdio.h>

int main()
{
	float fz=2,fm=1,answer=0,k;
	int N;
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		answer+=fz/fm;
		k=fm;
		fm=fz;
		fz+=k;
	}
	printf("%.2f",answer);
}
