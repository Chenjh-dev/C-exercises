/*
集合（运算符重载）

题目描述
集合是由一个或多个确定的元素所构成的整体。集合的运算有并、交、相对补等。
集合A和集合B的交集：由属于A且属于B的相同元素组成的集合。
集合A和集合B的并集：由所有属于集合A或属于集合B的元素所组成的集合。
集合B关于集合A的相对补集，记做A-B：由属于A而不属于B的元素组成的集合。
假设集合A={10，20，30}，集合B={1，10，50，8}。则A与B的并是{10，20，30,1,50,8}，
A与B的交是{10}，B关于A的相对补集是{20,30}。
定义整数集合类CSet，属性包括：集合中的元素个数n，整型指针data存储集合中的元素。
方法有：重载输出，按样例格式输出集合中的元素。
        重载+运算符，求集合A和集合B的并集，并返回结果集合。
        重载-运算符，求集合B关于集合A的相对补集，并返回结果集合。
        重载*运算符，求集合A和集合B的交集，并返回结果集合。
主函数输入集合A、B的数据，计算集合的并、交、相对补。
可根据题目，为CSet类添加需要的成员函数。

输入
测试次数
每组测试数据两行，格式如下：
第一行：集合A的元素个数和元素
第二行：集合B的元素个数和元素

输出
每组测试数据输出如下：
第一行：集合A
第二行：集合B
第三行：A和B的并
第四行：A和B的交
第五行：B关于A的相对补集 与 A关于B的相对补集的并，即(A-B)+(B-A)
每组测试数据间以空行分隔。

样例输入
2
3 10 20 30
4 10 1 2 3
5 100 2 3 4 -10
6 -34 12 2 4 90 100

样例输出
A:10 20 30
B:10 1 2 3
A+B:10 20 30 1 2 3
A*B:10
(A-B)+(B-A):20 30 1 2 3

A:100 2 3 4 -10
B:-34 12 2 4 90 100
A+B:100 2 3 4 -10 -34 12 90
A*B:100 2 4
(A-B)+(B-A):3 -10 -34 12 90

按题目要求定义CSet类并重载+、-和*运算符。
主函数输入数据，定义2个CSet对象并完成这两个对象的并和交等集合运算。

*/

#include<iostream>
#include<string.h>
using namespace std;

class CSet
{
	private:
		int n;
		int *data;
	public:
		CSet(){n=0,data=NULL;}
		void set(int a,int *b)
		{
			n=a;
			data = new int[n+1];
			for(int i=0;i<n;i++)
			{
				data[i]=b[i];
			}
		}
		friend ostream & operator << (ostream &out,const CSet &h)
		{
			for(int i=0;i<h.n;i++)
			{
				out<<h.data[i]<<" ";
			}
			return out;
		}
		CSet operator * (const CSet &h)
		{
			CSet C;
			int k=0,*p;
			p=new int[n];
			for(int i=0;i<n;i++)
			{
				for(int j=0;j<h.n;j++)
				{
					if(data[i]==h.data[j])
					{
						p[k]=data[i];
						k++;
					}
				}
			}
			C.set(k,p);
			return C;
		}
		CSet operator - (const CSet &h)
		{
			CSet K;
			int *p,i,j,k=0,judge=1;
			p=new int[n+1];
			for(i=0;i<n;i++)
			{
				for(j=0;j<h.n;j++)
				{
					if(data[i]==h.data[j])
						judge=0;
				}
				if(judge==1)
				{
					p[k]=data[i];
					k++;
				}
				judge=1;
			}
			K.set(k,p); 
			return K;
		}
		
		CSet operator + (const CSet &h)
		{
			CSet C;
			int *p,i,j,judge=1,k=n;
			p=new int[n+h.n+1];
			for(i=0;i<n;i++)
			{
				p[i]=data[i];
			}
			for(i=0;i<h.n;i++)
			{
				for(j=0;j<n;j++)
				{
					if(h.data[i]==data[j])
						judge=0;
				}
				if(judge==1)
				{
					p[k]=h.data[i];
					k++;
				}	
				judge=1;	
			}
			C.set(k,p);
			return C; 
		}
		~CSet()
		{
			if(data!=NULL)
				delete [] data;
		}
};

int main()
{
	int t,n,i;
	CSet A,B;
	int *a,*b;
	cin>>t;
	while(t--)
	{
		cin>>n;
		a=new int[n+1];
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		A.set(n,a); 
		
		cin>>n;
		b=new int[n+1];
		for(i=0;i<n;i++)
		{
			cin>>b[i];
		}
		B.set(n,b);
		cout<<"A:"<<A<<endl;
		cout<<"B:"<<B<<endl;
		cout<<"A+B:"<<A+B<<endl;
		cout<<"A*B:"<<A*B<<endl;
		cout<<"(A-B)+(B-A):"<<(A-B)+(B-A)<<endl;
		cout<<endl;
		delete []a;
		delete []b;
	}
}















