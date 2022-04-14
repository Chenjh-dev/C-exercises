/*

复制字符串

题目描述
实现strcpy函数的功能，将字符串S2复制给字符串S1，输出S1，
不可以直接将S2输出或调用库函数的strcpy，否则不给分(S1与S2不包含空格)

输入
输入测试组数t
对于每组测试，输入字符串S1  S2（长度<20）

输出
对于每组测试，输出字符串S1

样例输入
3
shenzhen
guangzhou
yellow
red
morning
night

样例输出
guangzhou
red
night

*/

#include<stdio.h>

int main()
{
	int t,i,j,L;
	char a[21],b[21];
	scanf("%d\n",&t);
	while(t--){
		i=0;
		do{
			scanf("%c",&a[i]);
			i++;
		}while(a[i-1]!='\n');
		L=i;
		i=0;
		do{
			scanf("%c",&b[i]);
			i++;
		}while(b[i-1]!='\n');
		for(j=0;j<i;j++){
			a[j]=b[j];
		}
		for(;j<L;j++){
			a[j]=' ';
		}
		for(j=0;j<i;j++){
			printf("%c",a[j]);
		}
	}
} 
