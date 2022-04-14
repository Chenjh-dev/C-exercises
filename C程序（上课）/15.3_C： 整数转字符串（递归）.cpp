/*
整数转字符串（递归）

题目描述
写递归函数void itostr(int num,char str[])，函数功能是将一个整数num转换为字符串str，如整数135，转换为字符串“135”。主函数如下，不可修改。
itostr每次独立调用。不可以为实现itostr的递归定义全局变量。
http://172.31.221.11/JudgeOnline/upload/pimg1411_1.jpg

输入
测试次数t
t个整数

输出
每个整数，输出转换后的数字字符串

样例输入
5
135
0
78934012
-1110
1323

样例输出
135
0
78934012
-1110
1323

*/

#include<stdio.h>

void itostr(int num,char str[])
{
	if(num==0){
		str[0]='0';
		str[1]='\0';
		return;
	}
	int len=1,k=num;
	while(k/10!=0){
		k/=10;
		len++;
	}
	if(num<0){
		str[0]='-';
		str[len+1]='\0';
		if(len==1){
			str[len]=-1*num+'0';
			return ;
		}
		itostr(num/10,str);
		str[len]=-1*num%10+'0';
	}else if(num>0){
		str[len]='\0';
		if(len==1){
			str[len-1]=num+'0';
			return ;
		}
		itostr(num/10,str);
		str[len-1]=num%10+'0';
	}
}

int main()
{
	const int SIZE = 20;
	int t,num;
	char str[SIZE];
	
	scanf("%d",&t);
	while(t--){
		scanf("%d",&num);
		itostr(num,str);
		printf("%s\n",str);
	}
	return 0;
}

