/*
对象相加函数模板

题目描述
时钟类CClock有时、分、秒；人民币类CRmb有元、角、分三个数据成员。
试为这种类型的类对象定义一个两两相加的函数模板add，包括三个参数：
2个对象和一个int表示进制。(要求不能用函数重载的方法）
主函数如下所示：
...
CClock c1(...), c2(...), c;
c = add(c1, c2, 60);
cout << c << endl;
CRmb r1(...), r2(...), r;
r = add(r1, r2, 10);
cout << r << endl;

输入
第一个时钟对象的时分秒
第二个时钟对象的时分秒
第一个人民币对象的元角分
第二个人民币对象的元角分

输出
两个时钟对象相加的结果
两个人民币对象相加的结果

样例输入
15 34 25
7 25 36
5 6 7
3 4 5

样例输出
23 0 1
9 1 2

按题目要求定义一个函数模板(不能定义多个重载函数)，并在主函数用实际类型参数调用之。
*/

#include<iostream>
using namespace std;

class CClock
{
	private:
		int h;
		int m;
		int s;
	public:
		CClock(){h=0,m=0,s=0;}
		CClock(int a,int b,int c)
		{
			h=a;
			m=b;
			s=c;
		}
		CClock operator + (const CClock &p)
		{
			int p1,p2,p3;
			p1=h+p.h;
			p2=m+p.m;
			p3=s+p.s;
			if(p3>=60)
			{
				p3-=60;
				p2++;
			}
			if(p2>=60)
			{
				p2-=60;
				p1++;
			}
			CClock A(p1,p2,p3);
			return A;
		}
		friend ostream & operator << (ostream &out,const CClock &p)
		{
			out<<p.h<<" "<<p.m<<" "<<p.s;
			return out;
		}
};

class CRmb
{
	private:
		int y;
		int j;
		int f;
	public:
		CRmb(){y=0,j=0,f=0;}
		CRmb(int a,int b,int c)
		{
			y=a;
			j=b;
			f=c;
		}
		CRmb operator + (const CRmb &p)
		{
			int p1,p2,p3;
			p1=y+p.y;
			p2=j+p.j;
			p3=f+p.f;
			if(p3>=10)
			{
				p3-=10;
				p2++;
			}
			if(p2>=10)
			{
				p2-=10;
				p1++;
			}
			CRmb A(p1,p2,p3);
			return A;
		}
		friend ostream & operator << (ostream &out,const CRmb &p)
		{
			out<<p.y<<" "<<p.j<<" "<<p.f;
			return out;
		}
};

template <class T>
T add(T &a,T &b,int k)
{
	return a+b;
}

int main()
{
	int h1,h2,h3,h4,h5,h6,k1,k2,k3,k4,k5,k6;
	cin>>h1>>h2>>h3>>h4>>h5>>h6>>k1>>k2>>k3>>k4>>k5>>k6;
	CClock c1(h1,h2,h3),c2(h4,h5,h6),c;
	c=add(c1,c2,60);
	cout<<c<<endl;
	CRmb r1(k1,k2,k3),r2(k4,k5,k6),r;
	r=add(r1,r2,10);
	cout<<r<<endl;
}
