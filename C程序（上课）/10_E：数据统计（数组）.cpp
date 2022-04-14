/*
数据统计（数组）

题目描述
输入n，输入n个整数，完成以下信息的计算：
1）统计大于平均数的数字个数和小于平均数的数字个数； 
2）统计正整数的数字个数； 
3）统计负整数的数字个数； 
4）计算n个数的最大值、最小值。

输入
测试次数T
每组测试数据一行，数字个数n(1<n<31)，后跟n个整数

输出
对每组测试数据，输出三行：
第一行输出：平均数（保留两位小数）  大于平均数的数字个数  小于平均数的数字个数
第二行输出：正整数个数 负整数个数
第三行输出：最大值 最小值。
每组数据的输出以空行分隔，具体输出格式见样例。

样例输入
2
10 -10 20 67 2 0 12 56 1 9 8
5 -1 -2 1 2 5

样例输出
16.50 3 7
8 1
max=67 min=-10

1.00 2 2
3 2
max=5 min=-2

*/

#include<stdio.h>

int main()
{
	int total,bignum,smallnum,posnum,negnum,max,min,i,j,k,T,n,a[30];
	float aver;
	scanf("%d",&T);
	while(T--){
	
		total=0,bignum=0,smallnum=0,posnum=0,negnum=0;
		
		scanf("%d",&n);
		for(i=0;i<n;i++){
			scanf("%d",&a[i]);
			total+=a[i];
			if(a[i]>0){
				posnum++;
			}
			else if(a[i]<0){
				negnum++;
			}
		}
		aver=total*1.0/n;
		max=a[0],min=a[0];
		
		for(i=0;i<n;i++){
			if(a[i]*n>total){
				bignum++;
			}
			else if(a[i]*n<total){
				smallnum++;
			}
			if(a[i]>max){
				max=a[i];
			}
			if(a[i]<min){
				min=a[i];
			}
		}
		printf("%.2f %d %d\n",aver,bignum,smallnum);
		printf("%d %d\n",posnum,negnum);
		printf("max=%d min=%d\n\n",max,min);
	}
}
