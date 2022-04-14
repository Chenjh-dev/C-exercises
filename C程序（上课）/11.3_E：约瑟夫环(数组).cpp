/*
约瑟夫环(数组)

题目描述
有n个人围成一个圈，从第一个人开始顺序报号1，2，3。
凡是报到3退出圈子中的人原来的序号。要求打印出退出人的序号。
以及找出最后留在圈子中的人原来的序号。

输入
输入n

输出
退出人的序号，并找出最后留在圈子里的人原来的序号

样例输入
13

样例输出
3 6 9 12 2 7 11 4 10 5 1 8 
13

*/

#include<stdio.h>

int main()
{
	int n,i=1,j,a[50],k=0,m;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		a[i]=i;
	}
	i=0; 
	while(1){
		m=3;
		while(m--){
			i++;
			if(i>n)
				i-=n;
			while(a[i]==0){
				i++;
				if(i>n)
					i-=n;
			}
		}
		if(k!=n-1){
			printf("%d ",a[i]);
			a[i]=0;
			k++;
		}
		else{
			printf("\n");
			printf("%d\n",a[i]);
			break;
		}
	}
}
