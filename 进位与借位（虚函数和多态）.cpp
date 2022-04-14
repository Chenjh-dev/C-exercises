/*
进位与借位（虚函数和多态）

题目描述


某小学二年级的数学老师在教学生整数加减法运算时发现：班上的同学可以分成三类，
第一类可以正确地完成加减法运算(GroupA)；第二类可以正确地完成加法运算，
但对于减法运算来说，总是忘记借位的处理(GroupB)；第三类总是忘记加法的进位，
也总是忘记减法的借位(GroupC)。（提示：小学二年级还没学负数。）
现在请模拟当老师在课堂提问某位同学时，同学会给出的回答。
实现时请基于下面的基类框架：
class Group
{
public:
virtual int add(int x, int y)=0;//输出加法的运算结果
virtual int sub(int x, int y)=0;//输出减法的运算结果
}
构建出GroupA, GroupB和GroupC三个派出类:
并编写主函数，要求主函数中有一个基类Group指针，通过该指针统一地进行add和sub运算。

输入
第一行表示测试次数。从第二行开始，每个测试用例占一行，每行数据意义如下：学生类别（1为第一类学生，2为第二类学生，3为第三类学生）、第一个数、第二个数。

输出
运算后的结果

样例输入
3
1 79+81
2 81-79
3 183+69

样例输出
160
12
142

根据题目要求完成基类Group和派生类GroupA、GroupB、GroupC的定义。
主函数输入数据、用基类对象指针指向动态创建的类对象并调用add或sub成员函数。
*/

#include<iostream>
using namespace std;

class Group
{
	public:
		Group(){}
		virtual int add(int x, int y)=0;
		virtual int sub(int x, int y)=0;
};

class GroupA:public Group
{
	public:
		GroupA(){}
		int add(int x, int y){ return x+y; }
		int sub(int x, int y){ return x-y; }
};

class GroupB:public Group
{
	public:
		GroupB(){}
		int add(int x, int y){ return x+y; }
		int sub(int x, int y)
		{
			int x1,x2,x3,y1,y2,y3,xx,yy,zz;
			x1=x/100;
			x3=x%10;
			x2=(x-x1*100-x3)/10;
			y1=y/100;
			y3=y%10;
			y2=(y-y1*100-y3)/10;
			
			if(x1<y1)
				xx=x1+10-y1;
			else
				xx=x1-y1;
			if(xx<0)
				xx=-1*xx;
			
			if(x2<y2)
				yy=x2+10-y2;
			else
				yy=x2-y2;
			if(yy<0)
				yy=-1*yy;
			
			if(x3<y3)
				zz=x3+10-y3;
			else
				zz=x3-y3;
			if(zz<0)
				zz=-1*zz;
			
			return xx*100+yy*10+zz;
		}
};

class GroupC:public Group
{
	public:
		GroupC(){}
		int add(int x, int y)
		{
			int x1,x2,x3,y1,y2,y3,xx,yy,zz;
			x1=x/100;
			x3=x%10;
			x2=(x-x1*100-x3)/10;
			y1=y/100;
			y3=y%10;
			y2=(y-y1*100-y3)/10;
			xx=x1+y1;
			xx=xx%10;
			yy=x2+y2;
			yy=yy%10;
			zz=x3+y3;
			zz=zz%10;
			return xx*100+yy*10+zz;
		}
		int sub(int x, int y)
		{
			int x1,x2,x3,y1,y2,y3,xx,yy,zz;
			x1=x/100;
			x3=x%10;
			x2=(x-x1*100-x3)/10;
			y1=y/100;
			y3=y%10;
			y2=(y-y1*100-y3)/10;
			
			if(x1<y1)
				xx=x1+10-y1;
			else
				xx=x1-y1;
			if(xx<0)
				xx=-1*xx;
			
			if(x2<y2)
				yy=x2+10-y2;
			else
				yy=x2-y2;
			if(yy<0)
				yy=-1*yy;
			
			if(x3<y3)
				zz=x3+10-y3;
			else
				zz=x3-y3;
			if(zz<0)
				zz=-1*zz;
			
			return xx*100+yy*10+zz;
		}
};

int main()
{
	int t,type,x,y;
	char k;
	Group *p;
	cin>>t;
	while(t--)
	{
		cin>>type>>x>>k>>y;
		if(type==1)
			p=new GroupA();
		else if(type==2)
			p=new GroupB();
		else if(type==3)
			p=new GroupC();
		else 
		{ 	cout<<"error1"<<endl;continue; }
		
		if(k=='+')
			cout<<p->add(x,y)<<endl; 
		else if(k=='-')
			cout<<p->sub(x,y)<<endl;
		else 
			cout<<"error2"<<endl;
		delete p;	
	}

}
