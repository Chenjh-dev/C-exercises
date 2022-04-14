/*

按题目要求定义四进制类CQuad(其数据成员是int表示的四进制数)
并按逢四进一运算法则重载+运算符。定义一个全局函数实现所有CQuad类对象的求和。
主函数定义对象指针数组，输入数据，动态创建对象。最后调用全局函数求出结果。

题目描述
定义一个四进制的类，重定义“+”号实现四进制数的累加。

输入
第一行输入所需要的四进制数的个数
第二行开始，依次输入四进制数

输出
所有输入四进制数累加的和

样例输入
3
13
2
21

样例输出
102
*/

#include<iostream>
using namespace std;

class CQuad
{
	private:
		int n;
	public:
		CQuad(){n=0;}
		void set(int a){n=a;}
		int getn(){return n;}
		CQuad operator + (CQuad &p)
		{
			CQuad a;
			int x1,x2,x3,x4,h1,h2,h;
			x1=n/100;
			x3=n%10;
			x2=(n-x1*100-x3)/10;
			h1=x1*16+x2*4+x3;
			x1=p.n/100;
			x3=p.n%10;
			x2=(p.n-x1*100-x3)/10;
			h2=x1*16+x2*4+x3;
			h=h1+h2;
			x1=h/64;
			h=h%64;
			x2=h/16;
			h=h%16;
			x3=h/4;
			x4=h%4;
			a.set(x1*1000+x2*100+x3*10+x4);
			return a;
		}
};

int find(CQuad *p,int t)
{
	int i;
	CQuad sum;
	for(i=0;i<t;i++)
	{
		sum = sum + p[i];
	}
	return sum.getn();
}

int main()
{
	int i,t,n;
	CQuad *p;
	cin>>t;
	p = new CQuad[t];
	for(i=0;i<t;i++)
	{
		cin>>n;
		p[i].set(n); 
	}
	cout<<find(p,t)<<endl;
	delete [] p;
}
