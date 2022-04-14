//Point&Circle(�������빹��)

//��Ŀ����
//ͼhttp://172.31.221.21/JudgeOnline/upload/pimg1063_1.jpg
//��Point������д����һ���࣬��Circle��һ���µ��࣬Point��Ϊ���Ա����
//�������Circle�ĳ�Ա������ʵ�֡�
//��������������һ��Բ�����ɸ��㣬�ж���Щ����Բ��λ�ù�ϵ��
//�������Բ��(������Բ�ı���)�������inside�����������"outside"��
//Ȼ���ƶ�Բ�ĵ�λ�ã��ٴ��ж���Щ����Բ��λ�ù�ϵ��

//����
//Բ��x���� y���� �뾶
//��ĸ���n
//��һ�����x���� y����
//�ڶ������x���� y����
//...... 
//��n�����x���� y����
//Բ���ƶ������µ�x���� y����

//���
//��һ������Բ�Ĺ�ϵ
//�ڶ�������Բ�Ĺ�ϵ
//.......
//��n������Բ�Ĺ�ϵ
//after move the centre of circle
//Բ���ƶ����һ������Բ�Ĺ�ϵ
//Բ���ƶ���ڶ�������Բ�Ĺ�ϵ
//.....
//Բ���ƶ����n������Բ�Ĺ�ϵ

//��������
//0 0 5
//4
//1 1
//2 2
//5 0
//-6 0
//-1 0


//�������
//inside
//inside
//inside
//outside
//after move the centre of circle:
//inside
//inside
//outside
//inside


//������ĿҪ�����Point���Circle���Ա�����Ķ���(�����ڳ�Ա��������cin����)��
//������ʵ�����ݵ����롢����Ķ��岢������Ӧ��Ա�������ݵ�Բ��ϵ�������������Ӧ����Ϣ��

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
