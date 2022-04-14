/*
圆和圆柱体计算（继承）

题目描述
定义一个CPoint点类，包含数据成员x,y（坐标点）。
以CPoint为基类，派生出一个圆形类CCircle，
增加数据成员r(半径）和一个计算圆面积的成员函数。
再以CCircle做为直接基类，派生出一个圆柱体类CCylinder，
增加数据成员h(高)和一个计算体积的成员函数。
生成圆和圆柱体对象，调用成员函数计算面积或体积并输出结果。

输入
输入圆的圆心位置、半径
输入圆柱体圆心位置、半径、高

输出
输出圆的圆心位置 半径
输出圆面积
输出圆柱体的圆心位置 半径 高
输出圆柱体体积

样例输入
0 0 1
1 1 2 3

样例输出
Circle:(0,0),1
Area:3.14
Cylinder:(1,1),2,3
Volume:37.68

按题目要求完成Point类、CCircle类和CCylinder类的定义,三个类都必须定义构造函数。
主函数输入数据、定义CCircle和CCylinder类对象并调用相应的计算面积和体积的成员函数。
*/

#include<iostream>
using namespace std;

class CPoint
{
	public:
		CPoint(int xx,int yy):x(xx),y(yy){}
	protected:
		int x,y;
};

class CCircle:public CPoint
{
	public:
		CCircle(int a,int b,int c):CPoint(a,b){ r=c;}
		float JisuanS(){ return 3.14*r*r; }
		void printS()
		{
			cout<<"Circle:("<<x<<","<<y<<"),"<<r<<endl;
			cout<<"Area:"<<JisuanS() <<endl;
		}
	protected:
		int r;
};

class CCylinder:public CCircle
{
	public:
		CCylinder(int a,int b,int c,int d):CCircle(a,b,c){h=d;}
		float JisuanV(){ return 3.14*r*r*h; }
		void printV()
		{
			cout<<"Cylinder:("<<x<<","<<y<<"),"<<r<<","<<h<<endl;
			cout<<"Volume:"<<JisuanV() <<endl;
		}
	protected:
		int h;
};

int main()
{
	int x,y,r,h;
	cin>>x>>y>>r;
	CCircle h1(x,y,r);
	h1.printS() ;
	cin>>x>>y>>r>>h;
	CCylinder h2(x,y,r,h);
	h2.printV() ;
}
