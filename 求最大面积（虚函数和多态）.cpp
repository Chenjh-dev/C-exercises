/*
求最大面积（虚函数和多态）

题目描述
请编写程序，从图形数组中找出最大面积。基类框架如下所示：
class Geometry{
	public:
   		virtual double getArea()=0; //计算面积，结果保留小数点后两位
};
以Geometry为基类，构建出Rect（矩形，数据成员为长和宽）和Circle（圆，数据成员为半径）
两个类，重写getArea()方法，其他方法根据需要自拟。
写一个TotalArea类，该类结构如下：
class TotalArea{
	public:
  		static void computerTotalArea(Geometry** t,int n)；//t为基类二级指针，指向一个基类动态数组，数组的每个元素指向一个子类图形，n为数组的大小
};
生成上述四个类并编写主函数，结果保留两位小数。

输入
第一行表示测试次数。从第二行开始，每个测试用例占一行，每行数据意义如下：
图形类型（1为Rect(矩形)，2为Circle(圆)）、基本信息（Rect是长和宽，Circle是半径）。

输出
最大图形的面积

样例输入
3
1 3 4
2 5
2 6

样例输出
最大面积=113.04

按题目要求定义TotalArea类，以及基类Geometry和派生类CRect、Circle的定义。
主函数定义基类对象指针数组、输入数据并用不同的基类指针指向动态创建的对象、
最后调用静态成员函数computeTotalArea计算最大面积。

*/

#include<iostream>
#include<iomanip>
using namespace std;
#define pi 3.14

class Geometry
{
	public:
		Geometry(){}
 		virtual double getArea()=0; //计算面积，结果保留小数点后两位
};

class Rect:public Geometry
{
	private:
		int l;
		int w;
	public:
		Rect(int a,int b){ l=a,w=b; }
		double getArea(){ return l*w; }
};

class Circle:public Geometry
{
	private:
		int r;
	public:
		Circle(int a){ r=a; }
		double getArea(){ return pi*r*r; }
};

class TotalArea
{
	public:
		TotalArea(){}
 		static void computerTotalArea(Geometry ** t,int n)
 		{
 			int i;
 			double k;
 			k=t[0]->getArea() ;
 			for(i=1;i<n;i++)
 			{
 				if( t[i]->getArea() > k )
 					k=t[i]->getArea() ;
			}
			cout<<"最大面积="<<fixed<<setprecision(2)<<setfill('0')<<k<<endl;
		}
};

int main()
{
	int t,type,l,w,r,i;
	cin>>t;
	Geometry **p;
	p=new Geometry*[t];
	for(i=0;i<t;i++)
	{
		cin>>type;
		if(type==1)
		{
			cin>>l>>w;
			p[i]=new Rect(l,w);
		}
		else if(type==2)
		{
			cin>>r;
			p[i]=new Circle(r);
		}
		else 
		{ cout<<"error1"<<endl;continue; }
	}
	TotalArea::computerTotalArea(p,t) ;
	for(i=0;i<t;i++)
		delete [] p[i];
	delete [] p;
}

