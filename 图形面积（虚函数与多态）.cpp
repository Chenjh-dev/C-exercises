/*
ͼ��������麯�����̬��

��Ŀ����
��дһ�����򣬶���������Shape����Shape���ж����麯��Area()��
����������3�������ࣺCircle(Բ��)��Square(������)��Rectangle(����)��
���麯���ֱ���㼸��ͼ�������
1��Ҫ��������������λС����
2��Ҫ���û���ָ�����飬ʹ��ÿһ��Ԫ��ָ��ÿһ�����������

����
�������ݵ����� t
��һ�����������Բ�İ뾶
��һ�����������������εı߳�
��һ����������о��εĳ�����
.......
�� t �����������Բ�İ뾶
�� t �����������������εı߳�
�� t ����������о��εĳ�����

���
��һ��������Բ�����
��һ�������������ε����
��һ�������о��ε����
......
�� t ��������Բ�����
�� t �������������ε����
�� t �������о��ε����

��������
2
1.2
2.3
1.2 2.3
2.1
3.2
1.23 2.12


�������
4.52
5.29
2.76
13.85
10.24
2.61

����ĿҪ����ɳ������Shape��������Circle��Square��Rectangle�Ķ��塣
�������������ָ�����顢�������ݡ�
�ò�ͬ�Ļ���ָ��ָ��ͬ�Ķ�̬��������������󲢵���Area��Ա������
*/


#include<iostream>
#include<iomanip>
using namespace std;

#define pi 3.14

class Shape
{
	public:
		virtual float Area() = 0;
};

class Circle:public Shape
{
	public:
		Circle(float r):radius(r){}
		float Area(){return pi*radius*radius; }
	private:
		float radius;
};

class Square:public Shape
{
	public:
		Square(float a):L(a){}
		float Area(){ return L*L; }
	private:
		float L;
};

class Rectangle:public Shape
{
	public:
		Rectangle(float a,float b):L(a),W(b){}
		float Area(){ return L*W; }
	private:
		float L,W;
};

void show(Shape *r)
{
	cout<<setiosflags(ios::fixed)<<setprecision(2)<<r->Area() <<endl; 
}

int main()
{
	int t;
	cin>>t;
	Shape *p[3];
	while(t--)
	{
		float r,l,L,W;
		cin>>r>>l>>L>>W;
		p[0] = new Circle(r);
		p[1] = new Square(l);
		p[2] = new Rectangle(L,W);
		show(p[0]);
		show(p[1]);
		show(p[2]);
	}
	for(int i=0;i<3;i++)
	delete p[i];
}


