//���մ��ۣ������๹�죩

//��Ŀ����
//����һ��������Date���������ݳ�Աyear\month\day��
//���������캯������������(������Ҫ�Լ����)
//����һ����Ա��VIP���������ݳ�Աid��birth��
//����id��������ʾ��Ա��ţ�birth��Date���ͱ�ʾ���ա�

//��VIP�������캯��������������������Ҫ�Լ���ӣ���
//������һ���ۿۺ���Discount������Discount���ؽ��Ϊ��������ʾ�ۿۣ�
//��������1������Ϊ�������ͣ������������жϲ��������Ƿ��Ա���գ�
//�����ۿ�Ϊ0.5���������ۿ�Ϊ0.95
//��д����ʵ�������๦�ܲ�ʵ�����������Ҫ��

//����
//��һ�������ꡢ�¡��գ���ʾ��������
//�ڶ�������t��ʾ��t����Ա
//�����������1����Ա��ID�����յ��ꡢ�¡���
//�����������1����Ա�����ѽ��
//��������������һ����Ա����������.....

//���
//���ݻ�Ա�����ѽ�����Discount�����жϽ����Ƿ��Ա���ղ��õ��ۿۣ�
//Ȼ������Ա�����۵����ѽ��
//ÿһ���������Ա��ţ��������Ա�����۵����ѽ����ѽ��ֻ��Ҫ�����������
//��ʾ�Ѹ�����ת����
//double x = 123.456
//cout<<int(x)<<endl;

//��������
//2017 4 20
//2
//1111 2000 4 20
//136
//2222 2000 3 30
//125

//�������
//1111's consumption is 68
//2222's consumption is 118


//����ĿҪ�����Date���VIP��Ķ���(�����ڳ�Ա��������cin����)��
//������ʵ�����ݵ����롢����Ķ��岢���ε���Discount��Ա������
//�������ѽ��ĳ�Ա�����ʹ�ӡ����ĳ�Ա������

#include<iostream>
using namespace std;

class Date
{
	private:
		int year;
		int month;
		int day;
	public:
		Date(){}
		Date(int x1,int x2,int x3)
		{
			year = x1;
			month = x2;
			day = x3;
		}
		int Getyear(){return year;}
		int Getmonth(){return month;}
		int Getday(){return day;}
};

class VIP
{
	private:
		int id;
		Date birth;
		int year;
		int month;
		int day;
		double zhekou;
		double money;
	public:
		VIP(int x4,int x5,int x6)
		{
			year = x4;
			month = x5;
			day = x6;
		}
		void Get(int a,double b)
		{
			id = a;
			money = b;
		}
		void Discount(Date &p)
		{
			birth = p;
			if(birth.Getday() == day && birth.Getmonth() == month )
				zhekou = 0.5;
			else 
				zhekou = 0.95;
		}
		void JIsuan()
		{
			money = money*zhekou;
		}
		void printf()
		{
			cout<<id<<"'s consumption is "<<int(money)<<endl;
		}
};

int main()
{
	int k1,k2,k3;
	cin>>k1>>k2>>k3;
	VIP a(k1,k2,k3);
	int t;
	cin>>t;
	while(t--)
	{
		int ID,k4,k5,k6;
		double money;
		cin>>ID>>k4>>k5>>k6>>money;
		Date b(k4,k5,k6);
		a.Get(ID,money) ;
		a.Discount(b);
		a.JIsuan() ;
		a.printf() ; 
	}
	return 0;
}
