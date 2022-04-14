/*
鞍点（数组）

题目描述
矩阵的鞍点是矩阵的一个元素，该元素是所在行的最大值，所在列的最小值。
输入一个二维数组的行数n，列数m，二维数组的各元素值；
输出矩阵的鞍点，以及鞍点所在的行列号。
测试数据不用考虑存在多个鞍点的情况，如果鞍点存在，则一定唯一。

输入
测试组数
每组测试数据格式如下：
二维数组行数n 列数m( 0<n,m<10)
n行m列数据(整数）

输出
对每组测试数据，如果不存在鞍点，输出null。
如果存在鞍点，鞍点及其行，列位置。具体格式见样例。

样例输入
2
3 4
1 3 5 3
2 3 4 1
3 2 6 1
2 2
10 20
30 15

样例输出
4 2 3
null

*/

#include<stdio.h>

int main()
{
	int t,i,j,k,n,m,p,judge;
	scanf("%d",&t);
	while(t--){
		int a[10][10];
		scanf("%d%d",&n,&m);
		for(i=0;i<n;i++){
			for(j=0;j<m;j++){
				scanf("%d",&a[i][j]);
			}
		}
		for(i=0;i<n;i++){
			p=0;
			for(j=1;j<m;j++){
				if(a[i][p]<a[i][j]){
					p=j;
				}
			}
			judge=0;
			for(j=0;j<n;j++){
				if(a[i][p]>a[j][p]){
					judge=1;
				}
			}
			if(judge==0){
				printf("%d %d %d\n",a[i][p],i+1,p+1);
				break;
			}
		}
		if(judge==1){
			printf("null\n");
		}
	}
}
