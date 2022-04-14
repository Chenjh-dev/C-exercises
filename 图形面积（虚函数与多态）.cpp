/*
图形面积（虚函数与多态）

题目描述
编写一个程序，定义抽象基类Shape，在Shape类中定义虚函数Area()；
由它派生出3个派生类：Circle(圆形)、Square(正方形)、Rectangle(矩形)。
用虚函数分别计算几种图形面积。
1、要求输出结果保留两位小数。
2、要求用基类指针数组，使它每一个元素指向每一个派生类对象。

输入
测试数据的组数 t
第一组测试数据中圆的半径
第一组测测试数据中正方形的边长
第一组测试数据中矩形的长、宽
.......
第 t 组测试数据中圆的半径
第 t 组测测试数据中正方形的边长
第 t 组测试数据中矩形的长、宽

输出
第一组数据中圆的面积
第一组数据中正方形的面积
第一组数据中矩形的面积
......
第 t 组数据中圆的面积
第 t 组数据中正方形的面积
第 t 组数据中矩形的面积

样例输入
2
1.2
2.3
1.2 2.3
2.1
3.2
1.23 2.12


样例输出
4.52
5.29
2.76
13.85
10.24
2.61

按题目要求完成抽象基类Shape和派生类Circle、Square、Rectangle的定义。
主函数定义基类指针数组、输入数据、
用不同的基类指针指向不同的动态创建的派生类对象并调用Area成员函数。
*/


#include<iostream>
#include<iomanip>
using namespace std;

#define pi 3.14

class Shape
{
	public:
		virtual float Area() = 0;
};

class Circle:public Shape
{
	public:
		Circle(float r):radius(r){}
		float Area(){return pi*radius*radius; }
	private:
		float radius;
};

class Square:public Shape
{
	public:
		Square(float a):L(a){}
		float Area(){ return L*L; }
	private:
		float L;
};

class Rectangle:public Shape
{
	public:
		Rectangle(float a,float b):L(a),W(b){}
		float Area(){ return L*W; }
	private:
		float L,W;
};

void show(Shape *r)
{
	cout<<setiosflags(ios::fixed)<<setprecision(2)<<r->Area() <<endl; 
}

int main()
{
	int t;
	cin>>t;
	Shape *p[3];
	while(t--)
	{
		float r,l,L,W;
		cin>>r>>l>>L>>W;
		p[0] = new Circle(r);
		p[1] = new Square(l);
		p[2] = new Rectangle(L,W);
		show(p[0]);
		show(p[1]);
		show(p[2]);
	}
	for(int i=0;i<3;i++)
	delete p[i];
}


