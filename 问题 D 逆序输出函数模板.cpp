/*
逆序输出函数模板

题目描述
编写一个逆序输出数据的函数模板reverse（复数的逆序是实部虚部置换）。

输入
第一行输入测试次数
每次测试输入一行，先输入一个大写字母表示数据类型, I表示整型、
D表示双精度型、S表示string类型字符串、C表示复数类对象，最后输入数据。

输出
每次测试输出一行，逆序排列的数据

样例输入
5
I 123456
D -235.172
S thisisatest
C -123 456
C 123 -456

样例输出
654321
-271.532
tsetasisiht
456-123
-456+123

提示
可用类型转换函数将复数类对象转换为string.
模板函数内采用如下所示的方法可将数值型变量a转换成string型变量s:
#include "sstream"
......
ostringstream os;
string s;
os << a;
s = os.str();

按题目要求定义一个函数模板(不能定义多个重载函数)，并在主函数用实际类型参数调用之。

*/

#include<iostream>
#include<algorithm>
#include "sstream"
using namespace std;

class CC
{
	private:
		int value1;
		int value2;
	public:
		CC(int a,int b)
		{
			value1=a;
			value2=b;
		}
		operator string()
		{
			ostringstream os;
			string s;
			if(value1>0)
			{
				os << value2<<'+'<<value1;
			}
			else	
				os << value2<<value1;
			s = os.str();
			reverse(s.begin(),s.end());
			return s;
		}
};

template <class T>
string reverse(T &k)
{
	int find=0,i;
	ostringstream os;
	string s,m;
	os << k;
	s = os.str();
	if(s[0]!='-')
	{
		reverse(s.begin(),s.end());
		if(s[0]=='0'&&s[1]!='+'&&s[1]!='-')
		{
			for(i=0;i<s.size();i++)
			{
				if(s[i]!='0')
					break;
				else
					find=i;
			}
			s=s.substr(find+1);
		}
	}	
	else
	{
		reverse(s.begin(),s.end());
		s=s.substr(0,s.size()-1);
		if(s[0]=='0'&&s[1]!='+'&&s[1]!='-')
		{
			for(i=0;i<s.size();i++)
			{
				if(s[i]!='0')
					break;
				else
					find=i;
			}
			s=s.substr(find+1);
		}
		s="-"+s; 
	}
	return s;
}

int main()
{
	int t,i;
	char judge;
	cin>>t;
	while(t--)
	{
		cin>>judge;
		if(judge=='I')
		{
			int a;
			cin>>a;
			cout<<reverse(a)<<endl;
		}
		else if(judge=='D')
		{
			double a;
			cin>>a;
			cout<<reverse(a)<<endl;
		}
		else if(judge=='S')
		{
			string a;
			cin>>a;
			cout<<reverse(a)<<endl;
		}
		else if(judge=='C')
		{
			int a,b;
			cin>>a>>b;
			CC k(a,b);
			string h=k;
			cout<<reverse(h)<<endl;
		}
		else
			cout<<"error"<<endl;
	}
}


















