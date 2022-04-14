/*
�ù��ÿ͹�����̬��Ա��

��Ŀ����


��д����ʵ��ĳ�ùݵĿ���ס�޼�¼���ܡ�
����һ��Customer�࣬Ҫ��������˵�����������һ��Customer�������������£�
http://172.31.221.21/JudgeOnline/upload/pimg1101_1.jpg
�������Display�����������ID�����˳���ռ4λ�����1λΪ0001����2λΪ0002���������ƣ���
���������������������Ϳ�������þ�̬��Ա���������Բ�����ͨ�����ݳ�Ա��

����
������Դ���t
����ÿ�β��ԣ��������뵱ǰ��ݣ�
��������������˿�������0��ʾ���������

���
ÿ����������˿���Ϣ���ù���Ϣ�������˿��������˿ͱ�ţ��ù���ס���������ùݵ�ǰ�����롣

��������
2
2014
���� ���� ���� 0
2015
Cindy David 0

�������
���� 20140001 1 150
���� 20140002 2 300
���� 20140003 3 450
Cindy 20150004 4 600
David 20150005 5 750

������ĿҪ�����Customer��Ķ��塣����������Customer�����ָ�����顢
�������ݡ�������ݡ���̬�������󲢵��ô�ӡ��Ա���������Ӧ����Ϣ�����������̬�����Ķ���
*/

#include<iostream>
#include<string.h>
using namespace std;

class Customer
{
	public:
		Customer(){}
		Customer(char* name);
		~Customer();
		static void changeYear(int r);
		void Display();
	private:
		static int TotalCustNum;
		static int Rent;
		static int Year;
		int CustID;
		char* CustName;
};

int Customer::TotalCustNum = 0;
int Customer::Rent = 0;
int Customer::Year = 2014;

Customer::Customer(char* name)
{
	CustName = new char[strlen(name)];
	strcpy(CustName,name);
	Customer::TotalCustNum ++;
	Customer::Rent += 150;
	CustID = Customer::Year * 10000 + Customer::TotalCustNum ;
} 

void Customer::changeYear(int r)
{
	Customer::Year = r ;
}

void Customer::Display() 
{
	cout<<CustName<<' '<<CustID<<' '<<Customer::TotalCustNum <<' '<<Customer::Rent <<endl; 
}

Customer::~Customer() 
{
	delete [] CustName;
}

int main()
{
	int t,y,i,j;
	cin>>t;
	char a[50];
	Customer* b[50];
	while(t--)
	{
		cin>>y;
		Customer::changeYear(y);
		cin>>a;
		for(i=0 ;a[0] != '0' ;i++ )
		{
			b[i] = new Customer(a);
			b[i]->Display() ;
			cin>>a;
		} 	
	}
	for(j=0;j<i;j++)
		delete b[j];
}
