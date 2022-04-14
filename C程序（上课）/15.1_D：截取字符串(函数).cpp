/*

截取字符串(函数)
时间限制: 1 Sec  内存限制: 128 MB
提交: 194  解决: 59
[提交][状态][讨论版]
题目描述


编写一个函数int substr(char str1[],char str2[],int index)，其作用是，将从字符串str1 (长度超过30) 的第index个字符开始的所有字符复制，生成新的字符串str2，如果成功生成，函数返回1，如果不能成功生成，返回0

输入


测试数据的组数n

第一组数据

第二组数据

........

输出


成功生成就输出子串，不成功生成，输出"IndexError"

样例输入

3
Zhenshen University
9
www.szu.edu.cn
12
apple
8


样例输出

University
cn
IndexError

*/

#include<stdio.h>
#include<string.h>

int substr(char str1[],char str2[],int index)
{
	int l=strlen(str1),i,j=0;
	if(l<=index||index<0){
		return 0;
	}
	for(i=index;i<l;i++){
		str2[j++]=str1[i];
	}
	str2[j]='\0';
	return 1;
}

int main()
{
	int n,d;
	char c;
	char a[100],b[100];
	scanf("%d\n",&n); 
	while(n--){
		gets(a);
		scanf("%d",&d);
		c=getchar();
		if(substr(a,b,d)){
			puts(b);
		}else{
			printf("IndexError\n");
		}
	}
}
