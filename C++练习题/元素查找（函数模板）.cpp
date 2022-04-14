/*
元素查找（函数模板）

题目描述
编写一个在数组中进行查找的函数模板，其中数组为具有n个元素，类型为T，要查找的元素为key。
注意：必须使用模板函数

输入
第一行输入t表示有t个测试实例
第二行先输入一个大写字母表示数组类型，I表示整数类型，D表示双精度数类型，
C表示字符型，S表示字符串型；然后输入n表示数组长度。
第三行输入n个数据
第四行输入key
依次输入t个实例


输出
每行输出一个结果，找到输出key是数组中的第几个元素（从1开始），找不到输出0

样例输入
4
I 5
5 3 51 27 9
27
D 3
-11.3 25.42 13.2
2.7
C 6
a b g e u q
a
S 4
sandy david eason cindy
cindy

样例输出
4
0
1
4

按题目要求定义一个函数模板(不能定义多个重载函数)，并在主函数用实际类型参数调用之。

*/

#include<iostream>
using namespace std;

template <class T>
int find(T *a,int n,T c)
{
	int i,judge=0;
	for(i=0;i<n;i++)
	{
		if(a[i]==c)
		{
			judge=1;
			i++;
			break;
		}
	}
	if(judge==1)
		return i;
	else
		return 0; 
}

int main()
{
	int t,n,i;
	char judge;
	cin>>t;
	while(t--)
	{
		cin>>judge>>n;
		if(judge=='I')
		{
			int *k,thefind;
			k=new int[n+1];
			for(i=0;i<n;i++)
			{
				cin>>k[i];
			}
			cin>>thefind;
			cout<<find(k,n,thefind)<<endl;
			delete [] k;
		}
		else if(judge=='D')
		{
			double *k,thefind;
			k=new double[n+1];
			for(i=0;i<n;i++)
			{
				cin>>k[i];
			}
			cin>>thefind;
			cout<<find(k,n,thefind)<<endl;	
			delete [] k;
		}
		else if(judge=='C')
		{
			char *k,thefind;
			k=new char[n+1];
			for(i=0;i<n;i++)
			{
				cin>>k[i];
			}
			cin>>thefind;
			cout<<find(k,n,thefind)<<endl;
			delete [] k;	
		}
		else if(judge=='S')
		{
			string *k,thefind;
			k=new string[n+1];
			for(i=0;i<n;i++)
			{
				cin>>k[i];
			}
			cin>>thefind;
			cout<<find(k,n,thefind)<<endl;
			delete [] k;	
		}	
		else 
			cout<<"error"<<endl;
	}
}




















