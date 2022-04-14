
//问题 : 线段相交----结构体

//每个线段是用平面上的两个点来描述，用结构体实现对于任意输入的2个线段，判断其是否相交。

//提示：两点(x1,y1), (x2,y2) 间直线斜率是k=(y2-y1)/(x2-x1).


//输入

//判断次数和2条线段的x1、y1、x2、y2

//输出

//是否相交

//样例输入

//3
//1 5 2 9
//1 3 2 4
//5 6 7 8
//5 7 7 7
//2 5 1 0
//9 4 2 9

//样例输出

//disjoint
//intersect
//disjoint


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
int Judge(const SLine &a,const SLine &b);

int main()
{
	int t,m=1;
	cin>>t;
	SLine a;
	SLine b;
	while(t--)
	{
		cin>>a.p1.x >>a.p1.y >>a.p2.x >>a.p2.y ;
		cin>>b.p1.x >>b.p1.y >>b.p2.x >>b.p2.y ;
		m=Judge(a,b);
		if(m==1)
			cout<<"intersect"<<endl;
		else
			cout<<"disjoint"<<endl;
	} 
	return 0;
}

int Judge(const SLine &a,const SLine &b)
{
	if((a.p1.x == b.p1.x &&a.p1.y == b.p1.y )|| (a.p1.x == b.p2.x &&a.p1.y == b.p2.y )|| (a.p2.x == b.p1.x &&a.p2.y == b.p1.y )|| (a.p2.x == b.p2.x &&a.p2.y == b.p2.y ))
		return 1;
	else
	{
		int n1,n2,n3,n4;
		n1 =(a.p1.x -a.p2.x )*(a.p1.y -b.p1.y )-(a.p1.y -a.p2.y )*(a.p1.x -b.p1.x );
		n2 =(a.p1.x -a.p2.x )*(a.p1.y -b.p2.y )-(a.p1.y -a.p2.y )*(a.p1.x -b.p2.x );
		n3 =(b.p1.x -b.p2.x )*(b.p1.y -a.p1.y )-(b.p1.y -b.p2.y )*(b.p1.x -a.p1.x );
		n4 =(b.p1.x -b.p2.x )*(b.p1.y -a.p2.y )-(b.p1.y -b.p2.y )*(b.p1.x -a.p2.x );
		if(n1*n2<0 && n3*n4<0)
			return 1;
		else if(n1*n2 == 0 || n3*n4 == 0)
		{
			int amax,amin,bmax,bmin;
			amax=a.p1.x >=a.p2.x ?a.p1.x :a.p2.x ;
			amin=a.p1.x >=a.p2.x ?a.p2.x :a.p1.x ;
			bmax=b.p1.x >=b.p2.x ?b.p1.x :b.p2.x ;
			bmin=b.p1.x >=b.p2.x ?b.p2.x :b.p1.x ;
			if((amax>bmax && amin<bmax ) || (bmax>amax && bmin<amax))
				return 1;
			else 
				return 0;
		}
		else
			return 0;
	}
}
	
 
