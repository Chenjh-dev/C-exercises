/*
求数列中大于数列平均值的数的个数

题目描述
输入10个数，求它们的平均值，并输出大于平均值的数据的个数。

输入
10个数

输出
大于平均数的个数

样例输入
1 2 3 4 5 6 7 8 9 10

样例输出
5

*/

#include<stdio.h>

int main()
{
	int i,number=0,total=0,aver,k[10];
	for(i=0;i<10;i++){
		scanf("%d",&k[i]);
		total+=k[i];
	}
	aver=total/10;
	for(i=0;i<10;i++){
		if(aver<k[i]){
			number++;
		}
	}
	printf("%d\n",number);
} 
