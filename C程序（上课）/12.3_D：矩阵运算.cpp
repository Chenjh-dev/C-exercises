/*
矩阵运算

题目描述
两个m×n矩阵A和B的加，标记为A+B，一样是个m×n矩阵，
其内的各元素为A、B相对应元素相加后的值。例如：
设A为的矩阵，B为的矩阵，那么称的矩阵C为矩阵A与B的乘积，记作，
其中矩阵C中的第行第列元素可以表示为A的第i行与B的第j列对应元素乘积和，
即：

例如：


输入
测试次数t
每组测试数据格式如下：
矩阵阶数n（0<n<10)
n*n矩阵A
n*n矩阵B

输出
对每组测试数据，输出A+B、AB

样例输入
1
2
1 2
3 4
1 2
3 4

样例输出
2 4
6 8
7 10
15 22

*/

#include<stdio.h>

int main()
{
	int i,j,k,n,t;
	scanf("%d",&t);
	while(t--){
		int a[10][10],b[10][10],c[10][10],d[10][10];
		scanf("%d",&n);
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				scanf("%d",&a[i][j]);
				d[i][j]=0;
			}
		}
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				scanf("%d",&b[i][j]);
				c[i][j]=a[i][j]+b[i][j];
			}
		}
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				for(k=0;k<n;k++){
					d[i][j]+=a[i][k]*b[k][j];
				}
			}
		}
		for(i=0;i<n;i++){
			for(j=0;j<n-1;j++){
				printf("%d ",c[i][j]);
			}
			printf("%d\n",c[i][j]);
		}
		for(i=0;i<n;i++){
			for(j=0;j<n-1;j++){
				printf("%d ",d[i][j]);
			}
			printf("%d\n",d[i][j]);
		}
	}
} 
