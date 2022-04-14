/*
求字符串中各种字符的个数（循环）

题目描述
输入一行字符，分别统计出其中英文字母、空格、数字和其他字符的个数。

输入
一行字符

输出
统计值

样例输入
aklsjflj123 sadf918u324 asdf91u32oasdf/.';123

样例输出
23 16 2 4

*/

#include<stdio.h>

int main()
{
	char c;
	int numA=0,numblank=0,num1=0,numother=0;
	c=getchar();
	while(1){
		if(c=='\n')
			break;
		else if((c>='A'&&c<='Z')||(c>='a'&&c<='z'))
			numA++;
		else if((c>='0'&&c<='9'))
			num1++;
		else if(c==' ')
			numblank++;
		else
			numother++;
		c=getchar();
	}
	printf("%d %d %d %d",numA,num1,numblank,numother);	
}
