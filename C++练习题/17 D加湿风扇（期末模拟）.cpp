#include<iostream>
using namespace std;

class jiadian
{
	protected:
		int No;
		int power;
	public:
		jiadian(){}
		jiadian(int a,int b)
		{
			No=a;
			power=b;
		}
		virtual void print()=0;
};

class efan:virtual public jiadian
{
	protected:
		int direction;
		int force;
	public:
		efan(int c,int d)
		{
			direction=c;
			force=d;
		}
		void controldir(int a){direction=a;}
		void controlfor(int a){force=a;}
};

class jiashiqi:virtual public jiadian
{
	protected:
		float actualv;
		float maxv;
	public:
		jiashiqi(float c,float d)
		{
			actualv=c;
			maxv=d;
		} 
		int warning()
		{
			if(actualv>=maxv/2)
				return 1;
			else if(actualv>=maxv/10)
				return 2;
			else
				return 3;
		}
};

class jiashifan:public jiashiqi,public efan
{
	private:
		int dangwei;
	public:
		jiashifan(int a,int b,int c,int d,float e,float f,int g):efan(c,d),jiashiqi(e,f),jiadian(a,b)
		{
			dangwei=g;
		}
		void changedang(int k)
		{
			dangwei=k;
			if(dangwei==1)
			{
				controldir(0);
				controlfor(1); 
			}
			else if(dangwei==2)
			{
				controldir(1);
				controlfor(2); 
			}
			else if(dangwei==3)
			{
				controldir(1);
				controlfor(3); 
			}
		}
		void print()
		{
			cout<<"��ʪ����--��λ"<<dangwei<<endl;
			cout<<"���"<<No<<"--����"<<power<<"W"<<endl;
			if(direction==0)
				cout<<"���򴵷�--����";
			else if(direction==1)
				cout<<"��ת����--����";
			cout<<force<<"��"<<endl;
			cout<<"ʵ��ˮ����"<<actualv<<"��--ˮ��";
			if(warning()==1)
				cout<<"����";
			else if(warning()==2)
				cout<<"ƫ��";
			else if(warning()==3)
				cout<<"����";
			cout<<endl;
		}
};

int main()
{
	int t,x1,x2,x3,x4,dang,change;
	float v1,v2;
	cin>>t;
	while(t--)
	{
		cin>>x1>>x2>>x3>>x4>>v1>>v2>>dang;
		jiashifan h(x1,x2,x3,x4,v1,v2,dang);
		cin>>change;
		h.changedang(change);
		h.print(); 
	}
} 







