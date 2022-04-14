/*
数塔（数组）

题目描述
在讲述DP算法的时候，一个经典的例子就是数塔问题，它是这样描述的： 
有如下所示的数塔，要求从顶层走到底层，若每一步只能走到相邻的结点，则经过的结点的数字之和最大是多少？

输入
输入数据首先包括一个整数C,表示测试实例的个数，每个测试实例的第一行是一个整数N(1 <= N <= 100)，
表示数塔的高度，接下来用N行数字表示数塔，其中第i行有个i个整数，且所有的整数均在区间[0,99]内。

输出
对于每个测试实例，输出可能得到的最大和，每个实例的输出占一行。 ?

样例输入
1
5
7
3 8
8 1 0
2 7 4 4
4 5 2 6 5

样例输出
30
*/

#include<stdio.h>

int add(int n,int now,int level,int a[])
{
	if(level==n){
		return a[now];
	}
	return a[now]+(add(n,now+level,level+1,a)>add(n,now+level+1,level+1,a)?
				  add(n,now+level,level+1,a):add(n,now+level+1,level+1,a));
}

int main()
{
	int c,n,i,j,a[5050],max;
	scanf("%d",&c);
	while(c--){
		max=0;
		scanf("%d",&n);
		for(i=1;i<=n*(1+n)/2;i++){
			scanf("%d",&a[i]);
		}
		max=add(n,1,1,a);
		printf("%d\n",max);
	}
}
