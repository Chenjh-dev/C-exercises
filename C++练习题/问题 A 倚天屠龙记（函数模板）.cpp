/*
问题 A: 倚天屠龙记（函数模板）

题目描述
江湖中有一个传言，只要倚天剑和屠龙刀中暗藏的秘密拼到一起，就能得到天下无敌的内功秘笈。
设计一个函数模板，完成拼凑的功能（将倚天剑的秘密连接到屠龙刀的后面），并将秘笈输出. 
其中每个秘密由n个元素组成，类型为T。

输入
第一行输入t表示有t个测试实例
第二行先输入一个大写字母表示数据类型，I表示整数类型，D表示双精度数类型，
C表示字符型；然后输入n表示数据个数。
第三行输入倚天剑的n个数据
第四行输入屠龙刀的n个数据
依次输入t个实例

输出
每行输出一个结果

样例输入
2
I 5
5 3 51 27 9
27 0 0 5 1
C 5
kitty
hello

样例输出
2700515351279
hellokitty

按题目要求定义一个函数模板(不能定义多个重载函数)，并在主函数用实际类型参数调用之。
*/

#include<iostream>
using namespace std;

template <class T>
void yitian(T *a,T *b,int n)
{
	T *k;
	int i;
	k=new T[n*2+1];
	for(i=0;i<n;i++)
	{
		k[i]=b[i];
	}
	for(i=0;i<n;i++)
	{
		k[i+n]=a[i];
	}
	for(i=0;i<n*2;i++)
	{
		cout<<k[i];
	}
	cout<<endl;
	delete []k;
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
			int *a,*b;
			a=new int[n+1];
			b=new int[n+1];
			for(i=0;i<n;i++)
			{
				cin>>a[i];
			}
			for(i=0;i<n;i++)
			{
				cin>>b[i];
			}
			yitian(a,b,n);	
			delete []a,b;
		}
		else if(judge=='D')
		{
			double *a,*b;
			a=new double[n+1];
			b=new double[n+1];
			for(i=0;i<n;i++)
			{
				cin>>a[i];
			}
			for(i=0;i<n;i++)
			{
				cin>>b[i];
			}
			yitian(a,b,n);
			delete []a,b;	
		}
		else if(judge=='C')
		{
			char *a,*b;
			a=new char[n+1];
			b=new char[n+1];
			for(i=0;i<n;i++)
			{
				cin>>a[i];
			}
			for(i=0;i<n;i++)
			{
				cin>>b[i];
			}
			yitian(a,b,n);	
			delete []a;
			delete [] b;
		}
		else
			cout<<"error"<<endl;
	}
}
