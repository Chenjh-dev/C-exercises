/*
立方体碰撞检测（复合类+动态对象数组+析构）

题目描述
假设坐标系采用下图中的三维坐标系(x,y,z)，圆点为（0,0,0）。
定义点类CPoint，包含数据成员x坐标，y坐标，z坐标。方法有：带参构造函数，析构函数等。
假设立方体的边与坐标轴平行。定义立方体类CCube，包含数据成员：CPoint *point。方法有：
http://172.31.221.21/JudgeOnline/upload/pimg1211_1.jpg
带参构造函数动态生成点对象数组，数组大小为2。并根据参数设置立方体的坐标点1，坐标点2，如上图所示。 
int collide(CCube r);  判定与r立方体是否发生碰撞。碰撞返回1，否则返回0。
析构函数，释放分配的空间。
可根据需要，为CPoint和CCube添加需要的方法。

输入
测试次数t
每组测试数据两行：
第一行：第一个立方体的坐标点1、坐标点2
第二行：第二个立方体的坐标点1、坐标点2

输出
对每组测试数据，输出结果：
碰撞输出：collide; 否则输出：have distance

样例输入
2
7 7 10 10 10 7
7 8 12 11 12 8
-1 -1 8 6 6 1
-10 -10 10 -8 -8 8

样例输出
collide
have distance

按题目要求定义CPoint(含三个坐标数据成员和构造函数析构函数)
和CCube类(含表示坐标点1和坐标点2的两个CPoint对象指针数据成员，
以及构造析构和collide成员函数),为CPoint和CCube添加其它必要的成员函数。
主函数输入数据、定义两个CPoint对象，
再定义两个立方体CCube对象并判断这两个立方体是否发生碰撞。
*/

#include<iostream>
using namespace std;

class CPoint 
{
	public:
		CPoint(){}
		CPoint(int xx,int yy,int zz)
		{
			x=xx;
			y=yy;
			z=zz;
		}
		int getx(){return x;}
		int gety(){return y;}
		int getz(){return z;}
		~CPoint(){}
	private:
		int x;
		int y;
		int z;
};

class CCube
{
	public:
		CCube(CPoint k1,CPoint k2)
		{
			point = new CPoint[2];
			point[0] = k1;
			point[1] = k2;
		}
		~CCube()
		{
			delete [] point;
		}
		int collide(CCube &b); 
	private:
		CPoint *point;
};

int CCube::collide(CCube &b)
{
	int x1max,x1min,x2max,x2min,y1max,y1min,y2max,y2min,z1max,z1min,z2max,z2min;

	if(point[0].getx() >point[1].getx() )
	{
		x1max=point[0].getx() ;
		x1min=point[1].getx() ;
	}
	else
	{
		x1max=point[1].getx() ;
		x1min=point[0].getx() ;
	} 	
	if(point[0].gety() >point[1].gety() )
	{
		y1max=point[0].gety() ;
		y1min=point[1].gety() ;
	}
	else
	{
		y1max=point[1].gety() ;
		y1min=point[0].gety() ;
	}
	if(point[0].getz() >point[1].getz() )
	{
		z1max=point[0].getz() ;
		z1min=point[1].getz() ;
	}
	else
	{
		z1max=point[1].getz() ;
		z1min=point[0].getz() ;
	}
	if(b.point[0].getx() >b.point[1].getx() )
	{
		x2max=b.point[0].getx() ;
		x2min=b.point[1].getx() ;
	}
	else
	{
		x2max=b.point[1].getx() ;
		x2min=b.point[0].getx() ;
	} 	
	if(b.point[0].gety() >b.point[1].gety() )
	{
		y2max=b.point[0].gety() ;
		y2min=b.point[1].gety() ;
	}
	else
	{
		y2max=b.point[1].gety() ;
		y2min=b.point[0].gety() ;
	}
	if(b.point[0].getz() >b.point[1].getz() )
	{
		z2max=b.point[0].getz() ;
		z2min=b.point[1].getz() ;
	}
	else
	{
		z2max=b.point[1].getz() ;
		z2min=b.point[0].getz() ;
	}
	if(y1max<y2min ||y1min>y2max ||x1max<x2min || x1min>x2max||z1max<z2min || z1min>z2max)
		return 1;
	else	
		return 0;
} 

int main()
{
	int t,x1,y1,z1,x2,y2,z2;
	cin>>t;
	while(t--)
	{
		cin>>x1>>y1>>z1>>x2>>y2>>z2;
		CPoint k1(x1,y1,z1),k2(x2,y2,z2);
		CCube h1(k1,k2);
		cin>>x1>>y1>>z1>>x2>>y2>>z2;
		CPoint k3(x1,y1,z1),k4(x2,y2,z2);
		CCube h2(k3,k4);
		if( h1.collide(h2) )
			cout<<"have distance"<<endl;
		else
			cout<<"collide"<<endl;
	}
}






