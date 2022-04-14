/*
问题 E: 有界数组模板类（类模板）

题目描述
编写有界数组模板BoundArray（即检查对数组元素下标引用并在下标越界时终止程序的执行），
能够存储各种类型的数据。要求实现对数组进行排序的方法sort，及对数组进行查找的方法search。

输入
第一行先输入t，表示有t个测试用例
从第二行开始输入每个测试用例的数据。
首先输入数据类型，I表示int，D表示double，C表示char，接着输入数组的元素个数
然后输入每个元素
最后输入要查找的元素

输出
首先输出从小到大排序的元素
然后输出查找元素的结果，找到则输出下标，没找到则输出-1

样例输入
2
I 2
1 2
2
D 3
3.5 6.2 2.9
2.1

样例输出
1 2 
1
2.9 3.5 6.2 
-1

按题目要求定义一个类模板，并在主函数输入数据定义对象并调用相应成员函数实现程序功能。
*/

#include<iostream>
using namespace std;

template <class T>
class BoundArray
{
	private:
		T *value;
		int n;
	public:
		BoundArray(T *a,int b)
		{
			n=b;
			value=new T[n+1];
			for(int i=0;i<n;i++)
				value[i]=a[i];
		}
		void sort()
		{
			T k;
			int i,j;
			for(i=0;i<n-1;i++)
				for(j=0;j<n-1;j++)
					if(value[j]>value[j+1])
					{
						k=value[j];
						value[j]=value[j+1];
						value[j+1]=k;
					}
			for(i=0;i<n;i++)
				cout<<value[i]<<" ";
			cout<<endl;	
		}
		void search(T k)
		{
			int i,find=-1;
			for(i=0;i<n;i++)
				if(value[i]==k)
				{
					find=i;
					break;
				}	
			cout<<find<<endl;
		}
		~BoundArray()
		{
			delete [] value;
		}
};

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
			int *a,find;
			a=new int[n+1];
			for(i=0;i<n;i++)
				cin>>a[i];
			BoundArray<int> h(a,n);
			h.sort() ;
			cin>>find;
			h.search(find); 
			delete [] a;
		}
		else if(judge=='D')
		{
			double *a,find;
			a=new double[n+1];
			for(i=0;i<n;i++)
				cin>>a[i];
			BoundArray<double> h(a,n);
			h.sort() ;
			cin>>find;
			h.search(find); 
			delete [] a;
		}
		else if(judge=='C')
		{
			char *a,find;
			a=new char[n+1];
			for(i=0;i<n;i++)
				cin>>a[i];
			BoundArray<char> h(a,n);
			h.sort() ;
			cin>>find;
			h.search(find); 
			delete [] a;
		}
		else 
			cout<<"error"<<endl;
	}
}
