/*
矩阵转置

题目描述
给出矩阵A，输出A的转置矩阵

输入
输入n,m表示矩阵A有n行，m列
接下来输入n行，每行m个数（n<10,m<10）

输出
输出m行，每行n个数

样例输入
2 2
1 2
2 1

样例输出
1 2
2 1

*/

#include<stdio.h>

int main()
{
	int i,j,n,m,a[20][20];
	scanf("%d %d",&n,&m);
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			scanf("%d",&a[i][j]);
		}
	}
	for(i=0;i<m;i++){
		for(j=0;j<n-1;j++){
			printf("%d ",a[j][i]);
		}
		printf("%d\n",a[j][i]);
	}
}


