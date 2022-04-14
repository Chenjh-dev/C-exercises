/*
����ĿҪ����CRectangle�ಢΪ������>��==��*��<<��4��������Լ�����ת����Ա������
������������Ŀ������ʾ����

��Ŀ����
����������ö�άƽ�����ꡣ
�������CPoint����������x,y�����ͣ��������У����ι��캯����
getX��getY�ֱ𷵻ص��x���꣬y���ꡣ
���������CRectangle���������ԣ����ε����Ͻ�����leftPoint��
���½�����rightPoint�����з����У�
1�����ι��캯������ʼ�����ε����Ͻǡ����½�
2������>�����������ΪCPoint����󣬼���Ϊp����p�ھ�����(���߽磩��
����true,���򷵻�false��
3������>���������һ�������������ڶ������Σ����ֱ߽������ȣ���
����true�����򷵻�false����Ҫ��ú�������2��ʵ�֣�
4������==��������ж����������Ƿ�һ�£�����true��false��
5������*��������ж����������Ƿ����ص����֣�����true��false��
6����������ת���������������ε���������أ���������͡�
7�����ء��������������ε����������꣬�����ʽ��������
����2�����Σ�����������жϾ��εĹ�ϵ�����������£������޸ġ�
�ɸ�����Ҫ����ӹ��캯��������������

����
���Դ���
ÿ������������£�
����1�����Ͻǡ����½�����
����2�����Ͻǡ����½�����

*/

#include<iostream>
using namespace std;

class CPoint
{
	private:
		int x,y;
	public:
		CPoint(){}
		CPoint(int xx,int yy)
		{
			x=xx;
			y=yy;
		}
		int getx(){ return x; }
		int gety(){ return y; }	
};

class CRectangle
{
	private:
		CPoint leftPoint;
		CPoint rightPoint;
	public:
		CRectangle(int x1,int y1,int x2,int y2)
		{
			CPoint a(x1,y1),b(x2,y2);
			leftPoint = a;
			rightPoint = b; 
		}
		bool operator > (CPoint &p)
		{
			if(leftPoint.getx()<=p.getx() && leftPoint.gety()>=p.gety() && rightPoint.getx()>=p.getx()&&rightPoint.gety()<=p.gety())
				return true;
			else 
				return false;
		}
		bool operator > (CRectangle &p)
		{
			if(*this>p.leftPoint&&*this>p.rightPoint)
				return true;
			else
				return false;
		}
		bool operator == (CRectangle &p)
		{
			if(*this>p.leftPoint&&*this>p.rightPoint&&p>leftPoint&&p>rightPoint)
				return true;
			else 
				return false;
		}
		bool operator * (CRectangle &p)
		{
			if(leftPoint.gety()<p.rightPoint.gety()||leftPoint.getx()>p.rightPoint.getx()||rightPoint.getx()<p.leftPoint.getx()||rightPoint.gety()>p.leftPoint.gety())
				return false;
			else
				return true;
		}
		operator int()
		{
			return (leftPoint.getx()-rightPoint.getx())*(rightPoint.gety()-leftPoint.gety());
		}
		friend ostream & operator << (ostream &out,CRectangle &p)
		{
			out<<p.leftPoint.getx()<<" "<<p.leftPoint.gety()<<" "<<p.rightPoint.getx()<<" "<<p.rightPoint.gety();
			return out;
		}
};

int main()
{
	int t,x1,x2,y1,y2;
	cin>>t;
	
	while(t--)
	{
		cin>>x1>>y1>>x2>>y2;
		CRectangle rect1(x1,y1,x2,y2);
		cin>>x1>>y1>>x2>>y2;
		CRectangle rect2(x1,y1,x2,y2);
		
		cout<<"����1:"<<rect1<<" "<<(int)rect1<<endl;
		cout<<"����2:"<<rect2<<" "<<(int)rect2<<endl;
		
		if(rect1==rect2)
			cout<<"����1�;���2���"<<endl;
		else if(rect2>rect1)
			cout<<"����2��������1"<<endl;
		else if(rect1>rect2)
			cout<<"����1��������2"<<endl;
		else if(rect1*rect2)
			cout<<"����1�;���2�ཻ"<<endl;
		else 
			cout<<"����1�;���2���ཻ"<<endl;
		cout<<endl; 
	}
	return 0;
}

