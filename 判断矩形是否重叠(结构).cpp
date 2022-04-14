//判断矩形是否重叠(结构)

//用具有x,y两个整型变量成员的结构类型SPoint来表示坐标点。用SRect结构类型来描述矩形，其中包含p1和p2两个SPoint成员分别表示矩形对角线上的两个点。

//编写判断两个矩形是否重叠的函数。

//输入


//判断次数

//矩形1的对角线顶点坐标x1、y1、x2、y2

//矩形2的对角线顶点坐标x1、y1、x2、y2

//......

//输出


//是否重叠

//样例输入

//3
//1 5 2 9
//1 3 2 4
//5 6 7 8
//5 7 7 7
//2 5 1 0
//9 4 2 9

//样例输出

//not overlapped
//overlapped
//overlapped)



#include <iostream>
using namespace std;

struct SPoint
{
	int x;
	int y;
};
struct SRect
{
	SPoint p1;
	SPoint p2;
};
int Judge(const SRect &a,const SRect &b);

int main()
{
	int t,m,n;
	cin>>t;
	while(t--)
	{
		m=1;
		SRect a;
		SRect b;
		cin>>a.p1.x >>a.p1.y >>a.p2.x >>a.p2.y ;
		cin>>b.p1.x >>b.p1.y >>b.p2.x >>b.p2.y ;
		if((a.p1.x -a.p2.x )*(b.p1.x -b.p2.x )<0)
		{
			n=a.p1.x ;
			a.p1.x =a.p2.x ;
			a.p2.x =n;
		}	
		if((a.p1.y -a.p2.y )*(b.p1.y -b.p2.y )<0)
		{
			n=a.p1.y ;
			a.p1.y =a.p2.y ;
			a.p2.y =n;
		}	
		m=Judge(a,b);
		if(m == 1)
			cout<<"overlapped"<<endl;
		else 
			cout<<"not overlapped"<<endl;
	}
	return 0;
}

int Judge(const SRect &a,const SRect &b)
{
	int m,x1max,x1min,x2max,x2min,y1max,y1min,y2max,y2min;
	if(a.p1.x >a.p2.x )
	{
		x1max=a.p1.x ;
		x1min=a.p2.x ;
	}
	else
	{
		x1max=a.p2.x ;
		x1min=a.p1.x ;
	} 
		
	if(b.p1.x >b.p2.x )
	{
		x2max=b.p1.x ;
		x2min=b.p2.x ;
	}		
	else
	{
		x2max=b.p2.x ;
		x2min=b.p1.x ;
	}		
	if(a.p1.y >a.p2.y )
	{
		y1max=a.p1.y ;
		y1min=a.p2.y ;
	}		
	else 
	{
		y1max=a.p2.y ;
		y1min=a.p1.y ;
	}		
	if(b.p1.y >b.p2.y )
	{
		y2max=b.p1.y ;
		y2min=b.p2.y ;
	}	
	else
	{
		y2max=b.p2.y ;
		y2min=b.p1.y ;
	}

	if(y1max<y2min ||y1min>y2max ||x1max<x2min || x1min>x2max)
		m=0;
	else	
		m=1;
			
	return m;
}


