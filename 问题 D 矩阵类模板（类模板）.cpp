/*
问题 D: 矩阵类模板（类模板）

题目描述
设计一个矩阵类模板Matrix，支持任意数据类型的数据。
要求至少包含2个成员函数：矩阵转置函数transport、以及打印输出函数print
编写main函数进行测试，调用类的成员函数完成转置和输出。

输入
第一行先输入t，表示有t个测试用例
从第二行开始输入每个测试用例的数据。
首先输入数据类型，I表示int，D表示double，C表示char，
接着输入两个参数m和n，分别表示矩阵的行和列
接下来输入矩阵的元素，一共m行，每行n个数据

输出
输出转置后的矩阵

样例输入
2
I 2 3
1 2 3
4 5 6
C 3 3
a b c
d e f
g h i

样例输出
1 4
2 5
3 6
a d g
b e h
c f i

按题目要求定义一个类模板，并在主函数输入数据定义对象并调用相应成员函数实现程序功能。

*/

#include<iostream>
using namespace std;

template <class T>
class Matrix
{
	private:
		int r,c;
		T **p;
	public:
		Matrix(T **k,int a,int b)
		{
			int i,j;
			r=a,c=b;
			p=new T*[a+1];
			for(i=0;i<r;i++)
				p[i]=new T[b+1];
			for(i=0;i<r;i++)
				for(j=0;j<c;j++)
					p[i][j]=k[i][j];
		}
		void transport()
		{
			T **pp;
			int i,j;
			pp=new T*[c+1];
			for(i=0;i<c;i++)
				pp[i]=new T[r+1];
			for(i=0;i<c;i++)
				for(j=0;j<r;j++)
					pp[i][j]=p[j][i];
			for(i=0;i<r;i++)
				delete p[i];
			delete [] p;
			p=pp;
			i=r;
			r=c;
			c=i;
		}
		void print()
		{
			int i,j;
			for(i=0;i<r;i++)
			{
				for(j=0;j<c;j++)
				{
					cout<<p[i][j]<<" ";
				}
				cout<<endl;
			}
		}
		~Matrix()
		{
			for(int i=0;i<r;i++)
				delete p[i];
			delete [] p;
		}
};

int main()
{
	int t,m,n,i,j;
	char judge;
	cin>>t;
	while(t--)
	{
		cin>>judge>>m>>n;
		if(judge=='I')
		{
			int **k;
			k=new int*[m+1];
			for(i=0;i<m;i++)
				k[i]=new int[n+1];
			for(i=0;i<m;i++)
				for(j=0;j<n;j++)
					cin>>k[i][j];
			Matrix<int> h(k,m,n);
			h.transport() ;
			h.print() ;
			for(i=0;i<m;i++)
				delete k[i];
			delete [] k;
		}
		else if(judge=='D')
		{
			double **k;
			k=new double*[m+1];
			for(i=0;i<m;i++)
				k[i]=new double[n+1];
			for(i=0;i<m;i++)
				for(j=0;j<n;j++)
					cin>>k[i][j];
			Matrix<double> h(k,m,n);
			h.transport() ;
			h.print() ;
			for(i=0;i<m;i++)
				delete k[i];
			delete [] k;
		}
		else if(judge=='C')
		{
			char **k;
			k=new char*[m+1];
			for(i=0;i<m;i++)
				k[i]=new char[n+1];
			for(i=0;i<m;i++)
				for(j=0;j<n;j++)
					cin>>k[i][j];
			Matrix<char> h(k,m,n);
			h.transport() ;
			h.print() ;
			for(i=0;i<m;i++)
				delete k[i];
			delete [] k;
		}
		else
			cout<<"error"<<endl;
	}
}
