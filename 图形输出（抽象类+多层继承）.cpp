/*
ͼ�������������+���̳У�

��Ŀ����
����һ��������Shape�������������ݳ�Ա�����ơ�x��y����
��������麯���ֱ��ǣ������Լ�x��y��get�����������������0.0���������������0.0��
����һ�����麯��shapeName�������������ơ�
----
����Point��̳�Shape���ڹ��캯����ʼ��x��y���꣬��������Ϊ"Point"
����Circlet��̳�Point����������r��ʾ�뾶����������Ϊ"Circle"��
��������������Ҫ�Լ���д
����Cylinder��̳�Circle����������h��ʾ�߶ȣ���������Ϊ"Cylinder"��
��������������Ҫ�Լ���д
Ҫ��������������������Ʋ����ڹ��캯��������........
----
��дһ��ȫ�ֺ���Print���޷���ֵ������������ΪShape*���ͣ����������ͼ�ε������Ϣ��
���ơ�x��y���ꡢ����������Ҫ���������ʹ�ó����������麯����������Ϣ
�����ʽ���ο���������������ֻ��Ҫ����������֣����������룩��Բ����Ϊ3.14159
Ҫ������б���ʹ�ó������......������Point��Circle��Cylinder�����

����
��һ������һ�����X��Y����
�ڶ�������һ��Բ��X��Y���ꡢ�뾶
����������һ�������X��Y���ꡢ�뾶���߶�

���
Ҫ�����Print�������ͼ�ε���Ϣ��ÿ��ͼ�����һ�С�

��������
1.1 2.2
3.3 4.4 5.5
6.6 7.7 8.8 9.9

�������
Point--(1.1,2.2)--0--0
Circle--(3.3,4.4)--95--0
Cylinder--(6.6,7.7)--1033--2408

������ĿҪ����ɻ���Shape��������Point��Circle��Cylinder�Ķ��塣
�������������ݡ��������붨����󲢵���printȫ�ֺ�����
*/

#include<iostream>
#include<string>
using namespace std;
#define pi 3.14159

class Shape
{
	protected:
		float x;
		float y;
		string name;
	public:
		Shape(float b,float c)
		{
			x=b;
			y=c;
		}
		virtual string getname(){ return name; }
		virtual float getx(){ return x; }
		virtual float gety(){ return y; }
		virtual float gets(){ return 0; }
		virtual float getv(){ return 0; }
		virtual void shapeName()=0;
};

class Point:public Shape
{
	public:
		Point(float a,float b):Shape(a,b){}
		void shapeName(){ name="Point"; }
};

class Circle:public Shape
{
	private:
		float r;
	public:
		Circle(float a,float b,float c):Shape(a,b){ r=c; }
		void shapeName(){ name="Circle"; }
		float gets(){ return pi*r*r; }
};

class Cylinder:public Shape
{
	private:
		float r;
		float h; 
	public:
		Cylinder(float a,float b,float c,float d):Shape(a,b){ r=c,h=d; }
		void shapeName(){ name="Cylinder"; }
		float gets(){ return 2*pi*r*r+2*pi*r*h; }
		float getv(){ return pi*r*r*h; }
};

void print(Shape *p)
{
	cout<<p->getname() <<"--("<<p->getx() <<","<<p->gety() <<")--"<<int(p->gets())<<"--"<<int(p->getv())<<endl;
}

int main()
{
	float x,y,r,h;
	Shape *p;
	
	cin>>x>>y;
	p=new Point(x,y);
	p->shapeName() ;
	print(p);
	delete p;
	
	cin>>x>>y>>r;
	p=new Circle(x,y,r);
	p->shapeName() ;
	print(p);
	delete p;
	
	cin>>x>>y>>r>>h;
	p=new Cylinder(x,y,r,h);
	p->shapeName() ;
	print(p);
	delete p;
	
}












