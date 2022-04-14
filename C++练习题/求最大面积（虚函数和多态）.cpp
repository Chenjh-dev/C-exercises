/*
�����������麯���Ͷ�̬��

��Ŀ����
���д���򣬴�ͼ���������ҳ���������������������ʾ��
class Geometry{
	public:
   		virtual double getArea()=0; //����������������С�������λ
};
��GeometryΪ���࣬������Rect�����Σ����ݳ�ԱΪ���Ϳ���Circle��Բ�����ݳ�ԱΪ�뾶��
�����࣬��дgetArea()��������������������Ҫ���⡣
дһ��TotalArea�࣬����ṹ���£�
class TotalArea{
	public:
  		static void computerTotalArea(Geometry** t,int n)��//tΪ�������ָ�룬ָ��һ�����ද̬���飬�����ÿ��Ԫ��ָ��һ������ͼ�Σ�nΪ����Ĵ�С
};
���������ĸ��ಢ��д�����������������λС����

����
��һ�б�ʾ���Դ������ӵڶ��п�ʼ��ÿ����������ռһ�У�ÿ�������������£�
ͼ�����ͣ�1ΪRect(����)��2ΪCircle(Բ)����������Ϣ��Rect�ǳ��Ϳ�Circle�ǰ뾶����

���
���ͼ�ε����

��������
3
1 3 4
2 5
2 6

�������
������=113.04

����ĿҪ����TotalArea�࣬�Լ�����Geometry��������CRect��Circle�Ķ��塣
����������������ָ�����顢�������ݲ��ò�ͬ�Ļ���ָ��ָ��̬�����Ķ���
�����þ�̬��Ա����computeTotalArea������������

*/

#include<iostream>
#include<iomanip>
using namespace std;
#define pi 3.14

class Geometry
{
	public:
		Geometry(){}
 		virtual double getArea()=0; //����������������С�������λ
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
			cout<<"������="<<fixed<<setprecision(2)<<setfill('0')<<k<<endl;
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

