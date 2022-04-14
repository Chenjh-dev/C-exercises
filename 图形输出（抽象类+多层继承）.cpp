/*
图形输出（抽象类+多层继承）

题目描述
定义一个抽象类Shape，包含三个数据成员：名称、x和y坐标
包含五个虚函数分别是：名称以及x和y的get方法，求面积（返回0.0）、求体积（返回0.0）
包含一个纯虚函数shapeName，用于设置名称。
----
定义Point类继承Shape，在构造函数初始化x和y坐标，设置名称为"Point"
定义Circlet类继承Point，新增数据r表示半径，设置名称为"Circle"，
其他函数根据需要自己编写
定义Cylinder类继承Circle，新增数据h表示高度，设置名称为"Cylinder"，
其他函数根据需要自己编写
要求上述派生类的设置名称不是在构造函数，是在........
----
编写一个全局函数Print，无返回值，含单个参数为Shape*类型，功能是输出图形的五个信息：
名称、x和y坐标、面积、体积，要求输出必须使用抽象类的五个虚函数输出五个信息
输出格式看参考样例，面积和体积只需要输出整数部分（非四舍五入），圆周率为3.14159
要求程序中必须使用抽象类的......来创建Point、Circle、Cylinder类对象

输入
第一行输入一个点的X和Y坐标
第二行输入一个圆的X和Y坐标、半径
第三行输入一个柱体的X和Y坐标、半径、高度

输出
要求调用Print方法输出图形的信息，每个图形输出一行。

样例输入
1.1 2.2
3.3 4.4 5.5
6.6 7.7 8.8 9.9

样例输出
Point--(1.1,2.2)--0--0
Circle--(3.3,4.4)--95--0
Cylinder--(6.6,7.7)--1033--2408

根据题目要求完成基类Shape和派生类Point、Circle、Cylinder的定义。
主函数输入数据、根据输入定义对象并调用print全局函数。
*/

#include<iostream>
#include<string>
using namespace std;
#define pi 3.14159

class Shape
{
	protected:
		float x;
		float y;
		string name;
	public:
		Shape(float b,float c)
		{
			x=b;
			y=c;
		}
		virtual string getname(){ return name; }
		virtual float getx(){ return x; }
		virtual float gety(){ return y; }
		virtual float gets(){ return 0; }
		virtual float getv(){ return 0; }
		virtual void shapeName()=0;
};

class Point:public Shape
{
	public:
		Point(float a,float b):Shape(a,b){}
		void shapeName(){ name="Point"; }
};

class Circle:public Shape
{
	private:
		float r;
	public:
		Circle(float a,float b,float c):Shape(a,b){ r=c; }
		void shapeName(){ name="Circle"; }
		float gets(){ return pi*r*r; }
};

class Cylinder:public Shape
{
	private:
		float r;
		float h; 
	public:
		Cylinder(float a,float b,float c,float d):Shape(a,b){ r=c,h=d; }
		void shapeName(){ name="Cylinder"; }
		float gets(){ return 2*pi*r*r+2*pi*r*h; }
		float getv(){ return pi*r*r*h; }
};

void print(Shape *p)
{
	cout<<p->getname() <<"--("<<p->getx() <<","<<p->gety() <<")--"<<int(p->gets())<<"--"<<int(p->getv())<<endl;
}

int main()
{
	float x,y,r,h;
	Shape *p;
	
	cin>>x>>y;
	p=new Point(x,y);
	p->shapeName() ;
	print(p);
	delete p;
	
	cin>>x>>y>>r;
	p=new Circle(x,y,r);
	p->shapeName() ;
	print(p);
	delete p;
	
	cin>>x>>y>>r>>h;
	p=new Cylinder(x,y,r,h);
	p->shapeName() ;
	print(p);
	delete p;
	
}












