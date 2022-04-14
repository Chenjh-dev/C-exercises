/*

求m到n之间的素数和----函数
时间限制: 1 Sec  内存限制: 128 MB
提交: 918  解决: 416
[提交][状态][讨论版]
题目描述


输入两个正整数m和n(m<n)，求m到n之间(包括m和n)所有素数的和，要求定义并调用函数isprime(x)来判断x是否为素数(素数是除1以外只能被自身整除的自然数)。



输入


m n

输出


素数和

样例输入

2 3

样例输出

5
*/

#include<stdio.h>
#include<math.h>

bool isprime(int a)
{
	int i;
	if(a<=1){
		return false;
	}
	if(a==2){
		return true;
	}
	for(i=2;i<=sqrt(a);i++){
		if(a%i==0){
			return false;
		}
	}
	return true;
}

int main()
{
	int i,total=0,m,n;
	scanf("%d%d",&m,&n);
	for(i=m;i<=n;i++){
		if(isprime(i)){
			total+=i;
		}
	}
	printf("%d\n",total);
}
