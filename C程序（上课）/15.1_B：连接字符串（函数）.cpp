/*

连接字符串（函数）
时间限制: 1 Sec  内存限制: 128 MB
提交: 32  解决: 28
[提交][状态][讨论版]
题目描述


写一函数，将两个字符串连接

输入


两行字符串

输出


链接后的字符串

样例输入

123
abc

样例输出

123abc
*/

#include<stdio.h>
#include<string.h>

void run(char a[],char b[],char c[])
{
	int i;
	for(i=0;i<strlen(a);i++){
		c[i]=a[i];
	}
	for(;i<strlen(a)+strlen(b);i++){
		c[i]=b[i-strlen(a)];
	}
	c[i]='\0';
}

int main()
{
	char a[30],b[30],c[30];
	scanf("%s%s",&a,&b);
	run(a,b,c);
	printf("%s",c);
}
