/*
模拟时间（继承）

题目描述
基类Time类包含属性时、分、秒。
建立一个派生类Time_12hours类，用于表示十二进制时间，增加以下成员数据：
char interval[5]; //标识为AM或者PM，interval=”AM”或interval=”PM”
增加加一秒和减一秒的函数成员。
生成上述类并编写主函数，根据输入的初始时间信息、
自增或者自减类型、自增或者自减次数，输出其最后时间信息。

输入
测试输入包含多个测试用例，一个测试用例为一行，每行共五个数字，第一个数字为进制，121表示输入为12进制AM时间，122表示输入为12进制PM时间，第二个数字为hour，第三个数字为minute，第四个数字为second，第五个字符为运算类型，+表示自增，-表示自减，第六个数字为运算次数，0表示测试用例结束。

输出
操作完成后的时间

样例输入
121 11 59 59 + 3
122 00 00 00 - 3
0

样例输出
PM 00:00:02
AM 11:59:57

根据题目要求完成基类CTime和派生类CTime12类的定义，
两个类都必须定义构造函数。主函数输入数据、定义CTime12类对象
并调用其自增自减成员函数计算新的时间。
*/

#include<iostream>
#include<string.h>
#include<iomanip>
using namespace std;

class Time
{
	public:
		Time(int a,int b,int c)
		{
			h=a,m=b,s=c;
		}
	protected:
		int h,m,s;
};

class Time_12hours:public Time
{
	public:
		Time_12hours(int a,int b,int c,int d):Time(b,c,d)
		{
			if(a==121)
				strcpy(interval,"AM");
			else if(a==122)
				strcpy(interval,"PM");
			else
				cout<<"error"<<endl;
		}
		void changeinterval()
		{
			if(strcmp(interval,"AM"))
				strcpy(interval,"AM");
			else if(strcmp(interval,"PM"))
				strcpy(interval,"PM");
			else
				cout<<"error"<<endl;
		}
		void add(int n)
		{
			s=s+n;
			while(s>=60)
			{
				s=s-60;
				m=m+1;
				if(m>=60)
				{
					m=m-60;
					h=h+1;
					if(h>=12)
					{
						h=h-12;
						changeinterval() ;
					}
				}
			}
		}
		void min(int n)
		{
			s=s-n;
			while(s<0)
			{
				s=s+60;
				m=m-1;
				if(m<0)
				{
					m=m+60;
					h=h-1;
					if(h<0)
					{
						h=h+12;
						changeinterval() ;
					}	
				}
			}
		}
		void print()
		{
			cout<<interval<<" "<<setfill('0')<<setw(2)<<h<<":"<<setfill('0')<<setw(2)<<m<<":"<<setfill('0')<<setw(2)<<s<<endl;
		}
	private:
		char interval[5];
};

int main()
{
	int a,b,c,d,e;
	char f;
	cin>>a;
	while(a!=0)
	{
		cin>>b>>c>>d>>f>>e;
		Time_12hours hh(a,b,c,d);
		if(f=='+')
			hh.add(e);
		else if(f=='-') 
			hh.min(e);
		hh.print() ;
		cin>>a; 
	}
}
