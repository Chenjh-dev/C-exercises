/*
判断素数（函数）

题目描述
写一个判断素数的函数，在主函数输入一个整数，输出是否素数的信息。

输入
判断次数和每次输入的任意整数 　

输出
每次的输入是否为素数

样例输入
4
17
5
6
19

样例输出
prime
prime
not prime
prime

*/

#include<stdio.h>
#include<math.h> 

bool judge(int a)
{
	int i,j;
	for(i=2;i<=sqrt(a);i++){
		if(a%i==0){
			return true;
		}
	}
	return false;
}

int main()
{
	int t,a;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&a);
		if(judge(a)){
			printf("not prime\n");
		}
		else{
			printf("prime\n");
		}
	}
}






