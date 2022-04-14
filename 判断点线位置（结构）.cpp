//问题 : 判断点线位置(结构)

//题目描述

//用具有x,y两个整型变量成员的结构类型SPoint来表示坐标点。用SLine结构类型来描述线段，其中包含p1和p2两个SPoint成员。
//编写函数direction(const SLine &ab, const SPoint &c)，利用向量ab与ac叉乘的值判断点c与直线ab的位置关系。
//输入

//判断次数

//线的两点坐标x1、y1、x2、y2

//点坐标x、y

//......

//输出


//位置关系

//样例输入

//3
//1 5 2 9
//1 3
//5 6 7 8
//6 7
//2 3 1 0
//3 3

//样例输出

//clockwise
//intersect
//anti clockwise

#include<iostream>
using namespace std;


struct SPoint
{
	int x;
	int y;
};
struct SLine
{
	SPoint p1;
	SPoint p2;	
};
int direction(const SLine &ab,const SPoint &c);

int main()
{
	int t,i,m;
	SPoint c;
	SLine ab;
	cin>>t;
	while(t--)
	{
		cin>>ab.p1.x>>ab.p1.y >>ab.p2.x >>ab.p2.y >>c.x >>c.y ;
		m=direction(ab,c);
		if(m>0)
		cout<<"anti clockwise"<<endl;
		else if(m==0)
		cout<<"intersect"<<endl;
		else if(m<0)
		cout<<"clockwise"<<endl;
	}
	return 0;
}

int direction(const SLine &ab,const SPoint &c)
{
	int m;
	m=(ab.p1.x -ab.p2.x )*(ab.p1.y -c.y )-(ab.p1.y -ab.p2.y )*(ab.p1.x -c.x );
	return m;
}




