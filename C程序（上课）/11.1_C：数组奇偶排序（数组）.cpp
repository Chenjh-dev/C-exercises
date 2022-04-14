/*
数组奇偶排序（数组）

题目描述
输入n，输入n个整数。调整数字位置使得偶数在序列的前半部分，
奇数在序列的后半部分。
注：自己根据样例输入、输出找到算法。

输入
测试次数t
每组测试数据格式如下：
整数个数n，后跟n个整数

输出
对每组测试数据，输出整数个数和调整后的整数序列

样例输入
3
4 1 2 3 4
8 12 32 67 13 1 9 4 97
6 1 32 9 43 12 0

样例输出
4 4 2 3 1
8 12 32 4 13 1 9 67 97
6 0 32 12 43 9 1

*/

#include<stdio.h>

int main()
{
	int i,j,n,t,k1,k2,a[50],m;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(i=0;i<n;i++){
			scanf("%d",&a[i]);
		}
		k1=-1,k2=n;
		while(k1<=k2){
			for(i=k1+1;i<k2;i++){
				if(a[i]%2==1){
					k1=i;
					break;
				}
			}
			for(j=k2-1;j>k1-1;j--){
				if(a[j]%2==0){
					k2=j;
					break;
				}
			}
			if(i<j){
				m=a[i];
				a[i]=a[j];
				a[j]=m;
			}
			else{
				break;
			}
		}
		
		printf("%d",n);
		for(i=0;i<n;i++){
			printf(" %d",a[i]);
		}
		printf("\n");
	}
}
