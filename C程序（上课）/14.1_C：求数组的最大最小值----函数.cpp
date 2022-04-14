/*
求数组的最大最小值----函数

题目描述
编制函数，其功能是在float类型一维数组中查找最大值、最小值，
并将它们返回到调用程序。
* 输出保留两位小数

输入
n
n个浮点数

输出
最大值 最小值

样例输入
10
1.0
2.0
3.0
4.0
5.0
6.0
7.0
8.0
9.0
10.0

样例输出
10.00 1.00
*/

#include<stdio.h>
#include<stdlib.h>

float* find(float b[],int n)
{
	int i;
	float *a;
	a=(float *)malloc(sizeof(float)*2);
	a[0]=a[1]=b[0];
	for(i=1;i<n;i++){
		if(a[0]<b[i]){
			a[0]=b[i];
		}
		if(a[1]>b[i]){
			a[1]=b[i];
		}
	}
	return a;
}

int main()
{
	int i,n;
	float *a,b[100];
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%f",&b[i]);
	}
	a=find(b,n);
	printf("%.2f %.2f\n",a[0],a[1]);
}
