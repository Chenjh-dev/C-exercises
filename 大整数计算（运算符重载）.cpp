/*
大整数计算（运算符重载）

题目描述
定义大整数类CBigInteger（假设最长支持1000位），数据成员为一个字符指针。
成员函数或友元函数包括：
1）带参构造函数，为字符指针动态分配1001个字符空间。根据参数初始化大整数。
2)  无参构造函数，为字符指针动态分配1001个字符空间。
3）重载运算符+，实现两个大整数的加法。
4）重载运算符-，实现两个大整数的减法。
5）重载运算符*，实现两个大整数的乘法。
6）重载输入，输入大整数。
7）重载输出，输出大整数。
8）析构函数，释放分配的空间。该函数不可屏蔽。
主函数输入大整数，完成大整数的加、减、乘。主函数代码如下，不可修改。

输入
测试次数
每组测试数据一行： 大整数1 运算符 大整数2

输出
对每组测试数据输出表达式和计算结果，具体格式见样例。

样例输入
3
100 * -100
-123456789 + 123456
0001 - -123

样例输出
100 * (-100) = (-10000)
(-123456789) + 123456 = (-123333333)
1 - (-123) = 124

按题目要求定义大整数类CBigInteger（用字符数组的数组元素表示大整数的每一位）
并重载+、-、*、<<和>>运算符。主函数参照题目给出的示例。

*/

#include<iostream>
#include<cstring>
#include<stdio.h>
#include<math.h>
using namespace std;

class CBigInteger
{
	private:
		char *p;
	public:
		CBigInteger(char *h)
		{
			p=new char[strlen(h)+1];
			strcpy(p,h);
		}
		CBigInteger(){p=new char[1001];}
		long long changenum(char *h)
		{
			int i,l=strlen(h);
			long long a=0;
			if(h[0]!='-')
			{
				for(i=0;i<l;i++)
				{
					a+=(h[i]-'0')*pow(10,l-i-1); 
				}
			}
			else
			{
				for(i=1;i<l;i++)
				{
					a+=(h[i]-'0')*pow(10,l-i-1); 
				}
				a*=-1;
			}
			return a;
		}
		char* changechar(long long a)
		{
			char *b;
			b=new char[1001];
			sprintf(b,"%lld",a);
			return b;
		}
		CBigInteger operator + (CBigInteger &h)
		{
			char *a;
			long long x1,x2,xx;
			x1=changenum(p);
			x2=changenum(h.p);
			xx=x1+x2;
			a = changechar(xx);
			CBigInteger k(a);
			return k;
		}
		CBigInteger operator - (CBigInteger &h)
		{
			char *a;
			long long x1,x2,xx;
			x1=changenum(p);
			x2=changenum(h.p);
			xx=x1-x2;
			a = changechar(xx);
			CBigInteger k(a);
			return k;
		}
		CBigInteger operator * (CBigInteger &h)
		{
			char *a;
			long long x1,x2,xx;
			x1=changenum(p);
			x2=changenum(h.p);
			xx=x1*x2;
			a = changechar(xx);
			CBigInteger k(a);
			return k;
		}
		friend istream & operator >> (istream &in,CBigInteger &h )
		{
			in>>h.p ;
			return in;
		}
		friend ostream & operator << (ostream & out,const CBigInteger &h )
		{
			int i,l=strlen(h.p),k=0;
			if(h.p[0]!='-')
				for(i=0;i<l;i++)
				{
					if(k==0&&i!=l-1)
					{
						if(h.p[i]!='0')
						{
							k=1;
							cout<<h.p[i];
						}
					}
					else
					{
						cout<<h.p[i];
					}
				}
			else
			{
				cout<<"(";
				for(i=0;i<l;i++)
				{
					if(k==0&&i!=l-1)
					{
						if(h.p[i]!='0')
						{
							k=1;
							cout<<h.p[i];
						}
					}
					else
					{
						cout<<h.p[i];
					}
				}
				cout<<")";
			}	
			return out;
		}
		~CBigInteger()
		{
			if(p!=NULL)
				delete [] p;
		}
};

int main()
{
	int t;
	char op;
	CBigInteger bigNum1;
	CBigInteger bigNum2;
	
	cin>>t;
	while(t--)
	{
		cin>>bigNum1>>op>>bigNum2;
		cout<<bigNum1<<" "<<op<<" "<<bigNum2<<" = ";
		if(op=='+')
			cout<<bigNum1+bigNum2<<endl;
		else if(op=='-')
			cout<<bigNum1-bigNum2<<endl;	
		else if(op=='*')
			cout<<bigNum1*bigNum2<<endl;
	}
	return 0;
}



















