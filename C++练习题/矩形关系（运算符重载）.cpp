/*
按题目要求定义CRectangle类并为其重载>、==、*和<<共4个运算符以及类型转换成员函数。
主函数参照题目给出的示例。

题目描述
假设坐标采用二维平面坐标。
定义点类CPoint，包含属性x,y（整型）。方法有：带参构造函数，
getX，getY分别返回点的x坐标，y坐标。
定义矩形类CRectangle，包含属性：矩形的左上角坐标leftPoint，
右下角坐标rightPoint。类中方法有：
1）带参构造函数，初始化矩形的左上角、右下角
2）重载>运算符，参数为CPoint点对象，假设为p，若p在矩形内(含边界），
返回true,否则返回false。
3）重载>运算符，第一个矩形若包含第二个矩形（部分边界可以相等），
返回true，否则返回false。（要求该函数调用2）实现）
4）重载==运算符，判断两个矩形是否一致，返回true或false。
5）重载*运算符，判断两个矩形是否有重叠部分，返回true或false。
6）重载类型转换运算符，计算矩形的面积并返回，面积是整型。
7）重载《运算符，输出矩形的两个角坐标，具体格式见样例。
输入2个矩形，计算面积，判断矩形的关系。主函数如下，不可修改。
可根据需要，添加构造函数和析构函数。

输入
测试次数
每组测试数据如下：
矩形1的左上角、右下角坐标
矩形2的左上角、右下角坐标

*/

#include<iostream>
using namespace std;

class CPoint
{
	private:
		int x,y;
	public:
		CPoint(){}
		CPoint(int xx,int yy)
		{
			x=xx;
			y=yy;
		}
		int getx(){ return x; }
		int gety(){ return y; }	
};

class CRectangle
{
	private:
		CPoint leftPoint;
		CPoint rightPoint;
	public:
		CRectangle(int x1,int y1,int x2,int y2)
		{
			CPoint a(x1,y1),b(x2,y2);
			leftPoint = a;
			rightPoint = b; 
		}
		bool operator > (CPoint &p)
		{
			if(leftPoint.getx()<=p.getx() && leftPoint.gety()>=p.gety() && rightPoint.getx()>=p.getx()&&rightPoint.gety()<=p.gety())
				return true;
			else 
				return false;
		}
		bool operator > (CRectangle &p)
		{
			if(*this>p.leftPoint&&*this>p.rightPoint)
				return true;
			else
				return false;
		}
		bool operator == (CRectangle &p)
		{
			if(*this>p.leftPoint&&*this>p.rightPoint&&p>leftPoint&&p>rightPoint)
				return true;
			else 
				return false;
		}
		bool operator * (CRectangle &p)
		{
			if(leftPoint.gety()<p.rightPoint.gety()||leftPoint.getx()>p.rightPoint.getx()||rightPoint.getx()<p.leftPoint.getx()||rightPoint.gety()>p.leftPoint.gety())
				return false;
			else
				return true;
		}
		operator int()
		{
			return (leftPoint.getx()-rightPoint.getx())*(rightPoint.gety()-leftPoint.gety());
		}
		friend ostream & operator << (ostream &out,CRectangle &p)
		{
			out<<p.leftPoint.getx()<<" "<<p.leftPoint.gety()<<" "<<p.rightPoint.getx()<<" "<<p.rightPoint.gety();
			return out;
		}
};

int main()
{
	int t,x1,x2,y1,y2;
	cin>>t;
	
	while(t--)
	{
		cin>>x1>>y1>>x2>>y2;
		CRectangle rect1(x1,y1,x2,y2);
		cin>>x1>>y1>>x2>>y2;
		CRectangle rect2(x1,y1,x2,y2);
		
		cout<<"矩形1:"<<rect1<<" "<<(int)rect1<<endl;
		cout<<"矩形2:"<<rect2<<" "<<(int)rect2<<endl;
		
		if(rect1==rect2)
			cout<<"矩形1和矩形2相等"<<endl;
		else if(rect2>rect1)
			cout<<"矩形2包含矩形1"<<endl;
		else if(rect1>rect2)
			cout<<"矩形1包含矩形2"<<endl;
		else if(rect1*rect2)
			cout<<"矩形1和矩形2相交"<<endl;
		else 
			cout<<"矩形1和矩形2不相交"<<endl;
		cout<<endl; 
	}
	return 0;
}

