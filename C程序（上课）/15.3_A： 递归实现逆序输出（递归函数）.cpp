/*
递归实现逆序输出（递归函数）

题目描述
利用递归函数调用方式，将所输入的任意个字符，以相反顺序打印出来。

输入
字符串长度和该字符串

输出
逆序输出

样例输入
5
12345

样例输出
54321

*/

#include<stdio.h>

int length;

bool print(char a[],int index)
{
	if(index+1==length||print(a,index+1)){
		printf("%c",a[index]);
	}
}

int main()
{
	char a[100];
	scanf("%d\n",&length);
	scanf("%s",&a);
	print(a,0);
}
