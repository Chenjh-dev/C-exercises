/*
�����շѣ��麯���Ͷ�̬��

��Ŀ����
����Ҫ����һ��ϵͳ��ʵ�ֶԶ����������շѹ����� ����������������ʾ��
class Vehicle
{ protected:
string no;//���
public:
virtual void display()=0;//Ӧ�շ���
}
��VehicleΪ���࣬������Car��Truck��Bus�����ࡣ
Car���շѹ�ʽΪ�� �ؿ���*8+����*2
Truck���շѹ�ʽΪ������*5
Bus���շѹ�ʽΪ�� �ؿ���*3
���������ಢ��д��������Ҫ������������һ������ָ��Vehicle *pv;�����������á�
�����������������Ϣ����Ӧ����Car,Truck��Bus����󣬶���Car�����ؿ�����������
Truck����������Bus�����ؿ����������ؿ�����������Ϊ������

����
��һ�б�ʾ���Դ������ӵڶ��п�ʼ��ÿ����������ռһ�У�ÿ�������������£�
�������ͣ�1Ϊcar��2ΪTruck��3ΪBus������š�������Ϣ
��Car���ؿ�����������Truck����������Bus�����ؿ�������

��� 
���ı�š�Ӧ�ɷ���

��������
4
1 002 20 5
3 009 30
2 003 50
1 010 17 6

�������
002 170
009 90
003 250
010 148

����ĿҪ����ɳ������Vehicle��������Car��Truck��Bus�Ķ��塣
�������������ݡ��û���ָ��ָ��ͬ�Ķ�̬��������������󲢵��ü����շѵĳ�Ա������

*/

#include<iostream>
#include<cstring>
using namespace std;

class Vehicle
{ 
	protected:
		string no;
	public:
		Vehicle(string a):no(a){}
		virtual void display()=0;
};

class Car:public Vehicle
{
	private:
		int number;
		int weight;
	public:
		Car(string a,int b,int c):Vehicle(a)
		{
			number = b;
			weight = c;
		}
		void display(){ int a=number*8+weight*2; cout<<no<<" "<<a<<endl; }
};

class Truck:public Vehicle
{
	private:
		int weight;
	public:
		Truck(string a,int b):Vehicle(a)
		{
			weight = b;
		}
		void display(){ int a=weight*5; cout<<no<<" "<<a<<endl; }
};

class Bus:public Vehicle
{
	private:
		int number;
	public:
		Bus(string a,int b):Vehicle(a)
		{
			number = b;
		}
		void display(){ int a=number*3; cout<<no<<" "<<a<<endl; }
};

void show(Vehicle *r)
{
	r->display() ;
}

int main()
{
	int t,judge,n,w;
	string no;
	Vehicle *h;
	cin>>t;
	while(t--)
	{
		cin>>judge;
		switch(judge)
		{
			case 1:
			{
				cin>>no>>n>>w;
				h=new Car(no,n,w);
				show(h);
				break;
			}
			case 2:
			{
				cin>>no>>w;
				h=new Truck(no,w);
				show(h);
				break;
			}
			case 3:
			{
				cin>>no>>n;
				h=new Bus(no,n);
				show(h);
				break;
			}
			default:cout<<"error"<<endl;break;
		}
		delete h;		
	}
}















