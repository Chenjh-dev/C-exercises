/*
������㣨��Ԫ������

��Ŀ����
Point��Ļ�����ʽ���£�
http://172.31.221.21/JudgeOnline/upload/pimg1096_1.png
���������Ҫ��
1.ʵ��Point�ࣻ
2.ΪPoint������һ����Ԫ����double Distance(Point &a, Point &b),
���ڼ�������֮��ľ��롣ֱ�ӷ���Point�����˽�����ݽ��м��㡣
3.��дmain������������������ֵ����������֮��ľ��롣

����
��1�У�������������ĵ�Ե���Ŀ
��2�п�ʼ��ÿ�����������������x��y����

���
ÿ���������һ����֮��ľ��루���ֱ��ȡ��������,���������� ��

��������
2
1 0 2 1
2 3 2 4

�������
1
1

����ĿҪ�����Point���Distance�����Ķ��塣
�������������ݡ�����Point���󲢵���Distance������������

*/




#include<iostream>
#include<math.h>
using namespace std;

class Point 
{
	public:
		Point(double xx,double yy){x=xx,y=yy;}
		friend int Distance(Point &a, Point &b);
	private:
		double x,y;
};

int Distance(Point &a, Point &b)
{
	int k;
	double h;
	h = (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y);
	h = sqrt(h);
	k = int(h);
	return k;
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int x1,x2,y1,y2;
		cin>>x1>>y1>>x2>>y2;
		Point a(x1,y1);
		Point b(x2,y2);
		cout<< Distance(a,b) <<endl;
	}
}
