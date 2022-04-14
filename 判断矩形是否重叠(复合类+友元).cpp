/*

�жϾ����Ƿ��ص�(������+��Ԫ)

��Ŀ����
��CPoint��ʾ�㣬������CPoint�����ʾ������CRect�ĶԽ������㡣
�ֱ�ʵ��CPoint���CRect�࣬��������������������궨��4��CPoint�����
ÿ2��CPoint�����ٹ���1��CRect����Ȼ��д����Ԫ�������ж�2�������Ƿ��ص���

����
�жϴ���
����1�ĶԽ��߶�������x1, y1, x2, y2
����2�ĶԽ��߶�������x1, y1, x2, y2
......

���
�Ƿ��ص�

��������
3
1 5 2 9
1 3 2 4
5 6 7 8
5 7 7 7
2 5 1 0
9 4 2 9

�������
not overlapped
overlapped
overlapped

����ĿҪ����CPoint��͸�����CRect���Լ�overlapȫ�ֺ�����
������ʵ�����ݵ����롢CRect����Ķ��壬������overlap�����ж����������Ƿ��ص���

*/

#include<iostream>
using namespace std;

class CPoint 
{
	public:
		CPoint(){};
		CPoint(int xx,int yy){x=xx,y=yy;}
		void set(int xx,int yy){x=xx,y=yy;}
		int getx(){return x;}
		int gety(){return y;}
	private:
		int x;
		int y;
};

class CRect
{
	public:
		CRect(){};
		CRect(CPoint a,CPoint b)
		{
			p1.set(a.getx() ,a.gety() ) ;
			p2.set(b.getx() ,b.gety() ) ;
		}
		friend int overlap(CRect &a,CRect &b);
	private:
		CPoint p1;
		CPoint p2;
};

int overlap(CRect &a,CRect &b)
{
	int x1max,x1min,x2max,x2min,y1max,y1min,y2max,y2min;
	
	if(a.p1.getx() >a.p2.getx() )
	{
		x1max=a.p1.getx() ;
		x1min=a.p2.getx() ;
	}
	else
	{
		x1max=a.p2.getx() ;
		x1min=a.p1.getx() ;
	} 
		
	if(b.p1.getx() >b.p2.getx() )
	{
		x2max=b.p1.getx() ;
		x2min=b.p2.getx() ;
	}		
	else
	{
		x2max=b.p2.getx() ;
		x2min=b.p1.getx() ;
	}
	if(a.p1.gety() >a.p2.gety() )
	{
		y1max=a.p1.gety() ;
		y1min=a.p2.gety() ;
	}		
	else 
	{
		y1max=a.p2.gety() ;
		y1min=a.p1.gety() ;
	}		
	if(b.p1.gety() >b.p2.gety() )
	{
		y2max=b.p1.gety() ;
		y2min=b.p2.gety() ;
	}	
	else
	{
		y2max=b.p2.gety() ;
		y2min=b.p1.gety() ;
	}

	if(y1max<y2min ||y1min>y2max ||x1max<x2min || x1min>x2max)
		return 1;
	else	
		return 0;
}

int main()
{
	int t,x1,y1;
	cin>>t;
	while(t--)
	{
		cin>>x1>>y1;
		CPoint k1(x1,y1);
		cin>>x1>>y1;
		CPoint k2(x1,y1);
		cin>>x1>>y1;
		CPoint k3(x1,y1);
		cin>>x1>>y1;
		CPoint k4(x1,y1);
		CRect h1(k1,k2);
		CRect h2(k3,k4);
		if( overlap(h1,h2) )
			cout<<"not overlapped"<<endl;
		else
			cout<<"overlapped"<<endl;
	}
}
