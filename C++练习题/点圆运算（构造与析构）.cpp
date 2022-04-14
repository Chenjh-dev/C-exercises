//问题 : 点圆运算（构造与析构）

//题目描述
//设计一个点类Point，包含私有属性x坐标和y坐标，操作包括
//1、构造函数，要求满足两个条件：1.能够使用类Point去创建一个对象数组（缺省构造方法！）；2.能够接收外来输入的x和坐标做初始化，提示：构造函数重载
//2、析构函数，把x坐标和y坐标都清0，并输出信息“point clear”
//3、设置(setXY)，接受外来输入，并设置x坐标和y坐标
//4、获取x坐标，直接返回x值
//5、获取y坐标，直接返回y值
//设计一个圆类Circle，包含私有属性：圆心坐标x和y、半径r；操作包括：
//1、构造函数，接受外来输入，设置圆心x坐标、y坐标和半径
//2、析构函数，将圆心坐标x和y以及半径都清零，并输出"circle clear"
//3、包含（Contain），判断一个圆是否包含一个点，计算圆心到这个点的距离，然后和半径做比较，大于则不包含，小于等于则包含。提示：用点对象做参数不一定符合输出


//输入
//第一行输入一个点的x坐标和y坐标，用Point类去创建一个点对象，并且自动通过构造函数来初始化
//第二行输入n，用Point类去创建一个点对象数组，包含n个点
//第三行起输入n行，每行输入一个点的x和y坐标，使用设置(setXY)来设置每个点的x和y坐标
//接着一行输入三个参数，表示一个圆的圆心坐标x和y，以及半径，使用Circle类去创建一个圆对象，并自动通过构造函数来初始化

//输出
//通过调用圆的包含(Contain)方法，判断每个点是否在圆内。
//按照点的输入顺序，每行输出一个点的判断结果，如果包含则输出in，不包含则输出out
//说明：当一个对象数组是动态创建的，那么在程序结束时，这个数组是不会被回收。只有增加代码delete []p，才会回收数组。
//本题不要求收回数组.


//样例输入
//5 2
//3
//4 7
//9 9
//2 4
//3 3 3

//样例输出
//in
//out
//out
//in
//circle clear
//point clear

//按题目要求定义Point类和Circle类。主函数实现数据的输入、对象的定义、并调用contain成员函数输出相关信息。


#include<iostream>
using namespace std;

class Point
{
	public:
		Point(){};
		Point(int x1,int x2)
		{
			x=x1;
			y=x2;
		}
		void setXY(int x1,int x2)
		{
			x=x1;
			y=x2;
		}
		int getx()
		{
			return x;
		}
		int gety()
		{
			return y;
		}
		~Point()
		{
			x=0,y=0;
			cout<<"point clear"<<endl;
		}
		private:
			int x;
			int y;
};

class Circle
{
	public:
		Circle(int a,int b,int c)
		{
			x=a;
			y=b;
			r=c;
		}
		~Circle()
		{
			x=0,y=0,r=0;
			cout<<"circle clear"<<endl;
		}
		int Contain(Point &p);
	private:
		int x;
		int y;
		int r;
};

int Circle::Contain(Point &p)
{
	if(r*r >= (x-p.getx())*(x-p.getx())+(y-p.gety())*(y-p.gety()))
		return 1;
	else return 0;	
}

int main()
{
	int k1,k2;
	cin>>k1>>k2;
	Point s(k1,k2);
	int n,i=0;
	cin>>n;
	Point *p = new Point[n];
	while(n--)
	{
		cin>>k1>>k2;
		p[i].setXY(k1,k2);  
		i++;
	}
	int k3;
	cin>>k1>>k2>>k3;
	Circle c(k1,k2,k3);
	if(c.Contain(s) )
		cout<<"in"<<endl;
	else 
		cout<<"out"<<endl;
	int m;
	for(m=0;m<i;m++)
	{
		if(c.Contain(p[m]))
			cout<<"in"<<endl;
		else 
			cout<<"out"<<endl;
	}
}
