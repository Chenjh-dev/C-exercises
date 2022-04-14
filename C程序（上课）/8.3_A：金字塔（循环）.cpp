/*
金字塔（循环）

题目描述
输入n和字符ch，输出n行由字符ch组成的金字塔图案。
例如，若n=6，ch='*',则输出6行金字塔图案。详见样例。


输入
测试次数t
每组测试数据一行，正整数n 字符ch

输出
对每组测试数据，输出n行金字塔图案。每组测试数据间，以空行分隔。

样例输入
3
1 5
6 *
3 A

样例输出
5

          *
        ***
      *****
    *******
  *********
***********

    A
  AAA
AAAAA

*/

#include<stdio.h>

int main()
{
	int n,t,k,i,j;
	char ch;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %c",&n,&ch);
		k=2*n-1;//输出的每行长度
		for(i=1;i<=k;i+=2){
			for(j=0;j<k-i;j++){
				printf(" ");
			}
			for(j=0;j<i;j++){
				printf("%c",ch);
			}
			printf("\n");
		} 
		printf("\n");
	}
}
