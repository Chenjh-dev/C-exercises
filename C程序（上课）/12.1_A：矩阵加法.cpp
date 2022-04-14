/*

矩阵加法
时间限制: 1 Sec  内存限制: 128 MB
提交: 590  解决: 322
[提交][状态][讨论版]
题目描述


给出两个矩阵A和B，输出A和B相加之后的矩阵


输入


第一行输入n,m分别表示矩阵的行和列

接下来输入n行，每行输入m个数（n<10,m<10）


输出


输出n行，每行m个数


样例输入

2 2
1 2
3 4
1 2
3 4

样例输出

2 4
6 8

*/

#include<stdio.h>

int main()
{
	int i,j,m,n,a[10][10],b[10][10];
	scanf("%d %d",&n,&m);
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			scanf("%d",&a[i][j]);
		}
	}
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			scanf("%d",&b[i][j]);
		}
	}
	
	for(i=0;i<n;i++){
		for(j=0;j<m-1;j++){
			printf("%d ",a[i][j]+b[i][j]);
		}
		printf("%d\n",a[i][j]+b[i][j]);
	}
}
