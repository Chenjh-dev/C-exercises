//���� : ��Բ���㣨������������

//��Ŀ����
//���һ������Point������˽������x�����y���꣬��������
//1�����캯����Ҫ����������������1.�ܹ�ʹ����Pointȥ����һ���������飨ȱʡ���췽��������2.�ܹ��������������x����������ʼ������ʾ�����캯������
//2��������������x�����y���궼��0���������Ϣ��point clear��
//3������(setXY)�������������룬������x�����y����
//4����ȡx���ֱ꣬�ӷ���xֵ
//5����ȡy���ֱ꣬�ӷ���yֵ
//���һ��Բ��Circle������˽�����ԣ�Բ������x��y���뾶r������������
//1�����캯���������������룬����Բ��x���ꡢy����Ͱ뾶
//2��������������Բ������x��y�Լ��뾶�����㣬�����"circle clear"
//3��������Contain�����ж�һ��Բ�Ƿ����һ���㣬����Բ�ĵ������ľ��룬Ȼ��Ͱ뾶���Ƚϣ������򲻰�����С�ڵ������������ʾ���õ������������һ���������


//����
//��һ������һ�����x�����y���꣬��Point��ȥ����һ������󣬲����Զ�ͨ�����캯������ʼ��
//�ڶ�������n����Point��ȥ����һ����������飬����n����
//������������n�У�ÿ������һ�����x��y���꣬ʹ������(setXY)������ÿ�����x��y����
//����һ������������������ʾһ��Բ��Բ������x��y���Լ��뾶��ʹ��Circle��ȥ����һ��Բ���󣬲��Զ�ͨ�����캯������ʼ��

//���
//ͨ������Բ�İ���(Contain)�������ж�ÿ�����Ƿ���Բ�ڡ�
//���յ������˳��ÿ�����һ������жϽ����������������in�������������out
//˵������һ�����������Ƕ�̬�����ģ���ô�ڳ������ʱ����������ǲ��ᱻ���ա�ֻ�����Ӵ���delete []p���Ż�������顣
//���ⲻҪ���ջ�����.


//��������
//5 2
//3
//4 7
//9 9
//2 4
//3 3 3

//�������
//in
//out
//out
//in
//circle clear
//point clear

//����ĿҪ����Point���Circle�ࡣ������ʵ�����ݵ����롢����Ķ��塢������contain��Ա������������Ϣ��


#include<iostream>
using namespace std;

class Point
{
	public:
		Point(){};
		Point(int x1,int x2)
		{
			x=x1;
			y=x2;
		}
		void setXY(int x1,int x2)
		{
			x=x1;
			y=x2;
		}
		int getx()
		{
			return x;
		}
		int gety()
		{
			return y;
		}
		~Point()
		{
			x=0,y=0;
			cout<<"point clear"<<endl;
		}
		private:
			int x;
			int y;
};

class Circle
{
	public:
		Circle(int a,int b,int c)
		{
			x=a;
			y=b;
			r=c;
		}
		~Circle()
		{
			x=0,y=0,r=0;
			cout<<"circle clear"<<endl;
		}
		int Contain(Point &p);
	private:
		int x;
		int y;
		int r;
};

int Circle::Contain(Point &p)
{
	if(r*r >= (x-p.getx())*(x-p.getx())+(y-p.gety())*(y-p.gety()))
		return 1;
	else return 0;	
}

int main()
{
	int k1,k2;
	cin>>k1>>k2;
	Point s(k1,k2);
	int n,i=0;
	cin>>n;
	Point *p = new Point[n];
	while(n--)
	{
		cin>>k1>>k2;
		p[i].setXY(k1,k2);  
		i++;
	}
	int k3;
	cin>>k1>>k2>>k3;
	Circle c(k1,k2,k3);
	if(c.Contain(s) )
		cout<<"in"<<endl;
	else 
		cout<<"out"<<endl;
	int m;
	for(m=0;m<i;m++)
	{
		if(c.Contain(p[m]))
			cout<<"in"<<endl;
		else 
			cout<<"out"<<endl;
	}
}
