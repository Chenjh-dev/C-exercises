/*
部分和问题（数组，函数）

题目描述
给定整数a1、a2、.......an，判断是否可以从中选出若干数，
使它们的和恰好为k。

输入
有多组测试数据。每组测试数据两行：
第一行：正整数n、整数k，n表示数的个数，k表示数的和。
第二行：n个数

输出
每组测试数据，如果和恰好可以为k，输出“YES”，并按输入顺序依次输出是由哪几个数的和组成，否则“NO”

样例输入
5 20
10 2 4 7 1
4 10
1 2 -10 4

样例输出
YES
10 2 7 1
NO

*/

#include<stdio.h>

int a[100];

int find(int n,int now,int k,int total){
	if(now==n){
		if(total==k){
			return 1;
		}
		else{
			return 0;
		}
	}
	else if(find(n,now+1,k,total+a[now])){
		return 1;
	}
	else if(find(n,now+1,k,total)){
		a[now]=0;
		return 1;
	}
	return 0;
}

int main()
{
	int i,j,n,k,total;
	while(scanf("%d",&n)!=EOF){
		scanf("%d",&k);
		for(i=0;i<n;i++){
			scanf("%d",&a[i]);
		}
		total=0;
		if(find(n,0,k,0)){
			printf("YES\n");
			for(i=0;i<n-1;i++){
				if(a[i]!=0){
					printf("%d ",a[i]);
				}
			}
			printf("%d\n",a[i]);
		}
		else{
			printf("NO\n");
		}
	}
}
