//Point&Circle(复合类与构造)

//题目描述
//图http://172.31.221.21/JudgeOnline/upload/pimg1063_1.jpg
//类Point是我们写过的一个类，类Circle是一个新的类，Point作为其成员对象，
//请完成类Circle的成员函数的实现。
//在主函数中生成一个圆和若干个点，判断这些点与圆的位置关系，
//如果点在圆内(包括在圆的边上)，输出“inside”，否则输出"outside"；
//然后移动圆心的位置，再次判断这些点与圆的位置关系。

//输入
//圆的x坐标 y坐标 半径
//点的个数n
//第一个点的x坐标 y坐标
//第二个点的x坐标 y坐标
//...... 
//第n个点的x坐标 y坐标
//圆心移动到的新的x坐标 y坐标

//输出
//第一个点与圆的关系
//第二个点与圆的关系
//.......
//第n个点与圆的关系
//after move the centre of circle
//圆心移动后第一个点与圆的关系
//圆心移动后第二个点与圆的关系
//.....
//圆心移动后第n个点与圆的关系

//样例输入
//0 0 5
//4
//1 1
//2 2
//5 0
//-6 0
//-1 0


//样例输出
//inside
//inside
//inside
//outside
//after move the centre of circle:
//inside
//inside
//outside
//inside


//根据题目要求完成Point类和Circle类成员函数的定义(不能在成员函数里用cin输入)。
//主函数实现数据的输入、对象的定义并调用相应成员函数根据点圆关系在主函数输出相应的信息。

#include<iostream>
#include<math.h>
using namespace std;

class Point
{
	private:
		double x,y;
	public:
		Point(){}
		Point(double x_value,double y_value)
		{
			x = x_value;
			y = y_value;
		}
		double GetX(){return x;}
		double GetY(){return y;}
		void setXY(double x1,double y1)
		{
			x = x1;
			y = y1;
		}
		void setX(double x_value){x = x_value;}
		void setY(double y_value){y = y_value;}
		double getDioTo(Point &p)
		{
			double k,n;
			k = (x-p.GetX())*(x-p.GetX())+(y-p.GetY())*(y-p.GetY());
			n = sqrt(k);
			return n;
		}
		~Point(){}
};

class Circle
{
	private:
		Point center;
		double radius;
	public:
		Circle()
		{
			center.setXY(0,0) ;
			radius = 1;
		}
		Circle(double x,double y,double r)
		{
			center.setXY(x,y);
			radius = r; 
		}
		double getArea(){}
		void moveCenterTo(double x1,double y1)
		{
			center.setXY (x1,y1); 
		}
		int contain(Point &p)
		{
			double k;
			k = p.getDioTo (center) ;
			if(k <= radius)
				return 1;
			else
				return 0;
		}
};

int main()
{
	double x1,y1,r1;
	cin>>x1>>y1>>r1;
	Circle a(x1,y1,r1);
	int n;
	cin>>n;
	Point *p;
	p = new Point[n];
	int i;
	for(i=0 ;i<n ;i++ )
	{
		int x2,y2;
		cin>>x2>>y2;
		p[i].setXY(x2,y2);
	}
	for(i=0 ;i<n ;i++ )
	{
		if(a.contain(p[i]))
			cout<<"inside"<<endl;
		else
			cout<<"outside"<<endl;
	}
	cout<<"after move the centre of circle:"<<endl;
	cin>>x1>>y1;
	a.moveCenterTo(x1,y1); 
	for(i=0 ;i<n ;i++ )
	{
		if(a.contain(p[i]))
			cout<<"inside"<<endl;
		else
			cout<<"outside"<<endl;
	}
	delete [] p;
	return 0;
}
