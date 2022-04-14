/*
三维空间的点（继承）

题目描述
定义一个平面上的点C2D类，它含有一个getDistance()的成员函数，
计算该点到原点的距离；从C2D类派生出三维空间的点C3D类，
它的getDistance()成员函数计算该点到原点的距离。
试分别生成一个C2D和C3D的对象，计算它们到原点的距离。
三维空间的两点（x, y, z）和（x1, y1, z1）的距离公式如下
[(x-x1)^2+(y-y1)^2+(z-z1)^2]^(1/2) 

输入
第一行二维坐标点位置
第二行三维坐标点位置1
第三行三维坐标点位置2

输出
第一行二维坐标点位置到原点的距离
第二行三维坐标点位置1到原点的距离
第三行三维坐标点位置2到原点的距离
第四行三维坐标点位置2赋值给二维坐标点变量后，二维坐标点到原点的距离

样例输入
3 4
3 4 5
6 8 8

样例输出
5
7.07107
12.8062
10

按题目要求完成基类C2D和派生类C3D的定义,两个类都必须定义构造函数。
主函数输入数据、定义C2D和C3D类对象并调用相应的getDistance成员函数。
*/

#include<iostream>
#include<math.h>
using namespace std;

class C2D
{
	public:
		C2D(int xx,int yy):x(xx),y(yy){}
		float d2getDistance(){ return sqrt(x*x+y*y); }
	protected:
		int x,y;
};

class C3D:public C2D
{
	public:
		C3D(int xx,int yy,int zz):C2D(xx,yy){ x=xx,y=yy,z=zz; }
		float d3getDistance(){ return sqrt(x*x+y*y+z*z); }
	protected:
		int z;
};

int main()
{
	int x,y,x1,x2,y1,y2,z1,z2;
	cin>>x>>y;
	C2D k1(x,y);
	cout<<k1.d2getDistance() <<endl;
	cin>>x1>>y1>>z1;
	C3D k2(x1,y1,z1);
	cout<<k2.d3getDistance() <<endl;
	cin>>x2>>y2>>z2;
	C3D k3(x2,y2,z2);
	cout<<k3.d3getDistance() <<endl;
	cout<<k3.d2getDistance() <<endl;
}



