/*
一只小蜜蜂（递归）

题目描述
有一只经过训练的蜜蜂只能爬向右侧相邻的蜂房，不能反向爬行。请编程计算蜜蜂从蜂房a爬到蜂房b的可能路线数。
其中，蜂房的结构如下所示。
http://172.31.221.11/JudgeOnline/upload/pimg1401_1.jpg
提示：定义函数int  GetPathNumber(int a,int b)计算从a到b的路线数并返回。找出它和a+1到b，a+2到b的路线数关系。

输入
输入数据的第一行是一个整数N,表示测试实例的个数，然后是N 行数据，每行包含两个整数a和b(0<a<b<50)。

输出
对于每个测试实例，请输出蜜蜂从蜂房a爬到蜂房b的可能路线数，每个实例的输出占一行。

样例输入
2
1 2
3 6

样例输出
1
3

*/

#include<stdio.h>

int GetPathNumber(int a,int b)
{
	if(a<b-1){
		return GetPathNumber(a+1,b)+GetPathNumber(a+2,b);
	}
	return 1;
}

int main()
{
	int t,a,b;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&a,&b);
		printf("%d\n",GetPathNumber(a,b));
	}
}
