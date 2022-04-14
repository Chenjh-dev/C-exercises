/*
Բ��Բ������㣨�̳У�

��Ŀ����
����һ��CPoint���࣬�������ݳ�Աx,y������㣩��
��CPointΪ���࣬������һ��Բ����CCircle��
�������ݳ�Աr(�뾶����һ������Բ����ĳ�Ա������
����CCircle��Ϊֱ�ӻ��࣬������һ��Բ������CCylinder��
�������ݳ�Աh(��)��һ����������ĳ�Ա������
����Բ��Բ������󣬵��ó�Ա��������������������������

����
����Բ��Բ��λ�á��뾶
����Բ����Բ��λ�á��뾶����

���
���Բ��Բ��λ�� �뾶
���Բ���
���Բ�����Բ��λ�� �뾶 ��
���Բ�������

��������
0 0 1
1 1 2 3

�������
Circle:(0,0),1
Area:3.14
Cylinder:(1,1),2,3
Volume:37.68

����ĿҪ�����Point�ࡢCCircle���CCylinder��Ķ���,�����඼���붨�幹�캯����
�������������ݡ�����CCircle��CCylinder����󲢵�����Ӧ�ļ������������ĳ�Ա������
*/

#include<iostream>
using namespace std;

class CPoint
{
	public:
		CPoint(int xx,int yy):x(xx),y(yy){}
	protected:
		int x,y;
};

class CCircle:public CPoint
{
	public:
		CCircle(int a,int b,int c):CPoint(a,b){ r=c;}
		float JisuanS(){ return 3.14*r*r; }
		void printS()
		{
			cout<<"Circle:("<<x<<","<<y<<"),"<<r<<endl;
			cout<<"Area:"<<JisuanS() <<endl;
		}
	protected:
		int r;
};

class CCylinder:public CCircle
{
	public:
		CCylinder(int a,int b,int c,int d):CCircle(a,b,c){h=d;}
		float JisuanV(){ return 3.14*r*r*h; }
		void printV()
		{
			cout<<"Cylinder:("<<x<<","<<y<<"),"<<r<<","<<h<<endl;
			cout<<"Volume:"<<JisuanV() <<endl;
		}
	protected:
		int h;
};

int main()
{
	int x,y,r,h;
	cin>>x>>y>>r;
	CCircle h1(x,y,r);
	h1.printS() ;
	cin>>x>>y>>r>>h;
	CCylinder h2(x,y,r,h);
	h2.printV() ;
}
