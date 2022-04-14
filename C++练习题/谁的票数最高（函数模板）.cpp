/*
谁的票数最高（函数模板）

题目描述
某小镇要票选镇长，得票最高者当选。但由于投票机制不健全，
导致每届投票时，候选人在投票系统的识别码类型不一致。
请编写函数模板，能针对多种类型的数据，查找出得票最高的元素。
其中，每届投票的选票有n张，识别码类型为T
注意：必须使用模板函数

输入
第一行输入t表示有t个测试实例
第二行先输入一个大写字母表示识别码类型，I表示整数类型，
C表示字符型，S表示字符串型；然后输入n表示数组长度。
第三行输入n个数据
依次输入t个实例

输出
每行输出一个结果，分别输出当选者的识别码和得票数，以空格分开。

样例输入
3
I 10
5 3 5 2 9 7 3 7 2 3
C 8
a b a e b e e q
S 5
sandy david eason cindy cindy

样例输出
3 3
e 3
cindy 2

按题目要求定义一个函数模板(不能定义多个重载函数)，并在主函数用实际类型参数调用之。
*/

#include<iostream>
using namespace std;

template <class T>
void find(T *a,int n)
{
	int i,j,judge=0,k=0,max=0,*h2;
	T *h1;
	h1 = new T[n+1];
	h2 = new int[n+1];
	for(i=0;i<n;i++)
	{
		for(j=0;j<k;j++)
		{
			if(a[i]==h1[j])
			{
				h2[j]++;
				judge=1;
				break;
			}
		}
		if(judge==0)
		{
			h1[k]=a[i];
			h2[k]=1;
			k++;
		}
		judge=0;
	}
	for(i=0;i<k-1;i++)
	{
		if(h2[max] < h2[i+1])
		{
			max=i+1;
		}
	}
	cout<<h1[max]<<" "<<h2[max]<<endl;
	delete [] h1;
	delete [] h2;
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
			int *a;
			a=new int[n+1];
			for(i=0;i<n;i++)
			{
				cin>>a[i];
			}
			find(a,n);
			delete [] a;
		}
		else if(judge=='C')
		{
			char *a;
			a=new char[n+1];
			for(i=0;i<n;i++)
			{
				cin>>a[i];
			}
			find(a,n);
			delete [] a;
		}
		else if(judge=='S')
		{
			string *a;
			a=new string[n+1];
			for(i=0;i<n;i++)
			{
				cin>>a[i];
			}
			find(a,n);
			delete [] a;
		}
		else
			cout<<"error"<<endl;
	}
}


















