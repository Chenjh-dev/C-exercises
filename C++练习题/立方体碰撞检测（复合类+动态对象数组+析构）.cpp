/*
��������ײ��⣨������+��̬��������+������

��Ŀ����
��������ϵ������ͼ�е���ά����ϵ(x,y,z)��Բ��Ϊ��0,0,0����
�������CPoint���������ݳ�Աx���꣬y���꣬z���ꡣ�����У����ι��캯�������������ȡ�
����������ı���������ƽ�С�������������CCube���������ݳ�Ա��CPoint *point�������У�
http://172.31.221.21/JudgeOnline/upload/pimg1211_1.jpg
���ι��캯����̬���ɵ�������飬�����СΪ2�������ݲ�������������������1�������2������ͼ��ʾ�� 
int collide(CCube r);  �ж���r�������Ƿ�����ײ����ײ����1�����򷵻�0��
�����������ͷŷ���Ŀռ䡣
�ɸ�����Ҫ��ΪCPoint��CCube�����Ҫ�ķ�����

����
���Դ���t
ÿ������������У�
��һ�У���һ��������������1�������2
�ڶ��У��ڶ���������������1�������2

���
��ÿ��������ݣ���������
��ײ�����collide; ���������have distance

��������
2
7 7 10 10 10 7
7 8 12 11 12 8
-1 -1 8 6 6 1
-10 -10 10 -8 -8 8

�������
collide
have distance

����ĿҪ����CPoint(�������������ݳ�Ա�͹��캯����������)
��CCube��(����ʾ�����1�������2������CPoint����ָ�����ݳ�Ա��
�Լ�����������collide��Ա����),ΪCPoint��CCube���������Ҫ�ĳ�Ա������
�������������ݡ���������CPoint����
�ٶ�������������CCube�����ж��������������Ƿ�����ײ��
*/

#include<iostream>
using namespace std;

class CPoint 
{
	public:
		CPoint(){}
		CPoint(int xx,int yy,int zz)
		{
			x=xx;
			y=yy;
			z=zz;
		}
		int getx(){return x;}
		int gety(){return y;}
		int getz(){return z;}
		~CPoint(){}
	private:
		int x;
		int y;
		int z;
};

class CCube
{
	public:
		CCube(CPoint k1,CPoint k2)
		{
			point = new CPoint[2];
			point[0] = k1;
			point[1] = k2;
		}
		~CCube()
		{
			delete [] point;
		}
		int collide(CCube &b); 
	private:
		CPoint *point;
};

int CCube::collide(CCube &b)
{
	int x1max,x1min,x2max,x2min,y1max,y1min,y2max,y2min,z1max,z1min,z2max,z2min;

	if(point[0].getx() >point[1].getx() )
	{
		x1max=point[0].getx() ;
		x1min=point[1].getx() ;
	}
	else
	{
		x1max=point[1].getx() ;
		x1min=point[0].getx() ;
	} 	
	if(point[0].gety() >point[1].gety() )
	{
		y1max=point[0].gety() ;
		y1min=point[1].gety() ;
	}
	else
	{
		y1max=point[1].gety() ;
		y1min=point[0].gety() ;
	}
	if(point[0].getz() >point[1].getz() )
	{
		z1max=point[0].getz() ;
		z1min=point[1].getz() ;
	}
	else
	{
		z1max=point[1].getz() ;
		z1min=point[0].getz() ;
	}
	if(b.point[0].getx() >b.point[1].getx() )
	{
		x2max=b.point[0].getx() ;
		x2min=b.point[1].getx() ;
	}
	else
	{
		x2max=b.point[1].getx() ;
		x2min=b.point[0].getx() ;
	} 	
	if(b.point[0].gety() >b.point[1].gety() )
	{
		y2max=b.point[0].gety() ;
		y2min=b.point[1].gety() ;
	}
	else
	{
		y2max=b.point[1].gety() ;
		y2min=b.point[0].gety() ;
	}
	if(b.point[0].getz() >b.point[1].getz() )
	{
		z2max=b.point[0].getz() ;
		z2min=b.point[1].getz() ;
	}
	else
	{
		z2max=b.point[1].getz() ;
		z2min=b.point[0].getz() ;
	}
	if(y1max<y2min ||y1min>y2max ||x1max<x2min || x1min>x2max||z1max<z2min || z1min>z2max)
		return 1;
	else	
		return 0;
} 

int main()
{
	int t,x1,y1,z1,x2,y2,z2;
	cin>>t;
	while(t--)
	{
		cin>>x1>>y1>>z1>>x2>>y2>>z2;
		CPoint k1(x1,y1,z1),k2(x2,y2,z2);
		CCube h1(k1,k2);
		cin>>x1>>y1>>z1>>x2>>y2>>z2;
		CPoint k3(x1,y1,z1),k4(x2,y2,z2);
		CCube h2(k3,k4);
		if( h1.collide(h2) )
			cout<<"have distance"<<endl;
		else
			cout<<"collide"<<endl;
	}
}






