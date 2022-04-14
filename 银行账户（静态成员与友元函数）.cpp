/*

�����˻�����̬��Ա����Ԫ������

��Ŀ����
�����˻���Ļ����������£�
Ҫ�����£�
ʵ�ָ������˻���
Ϊ�˻���Account����һ����Ԫ������ʵ���˻���Ϣ��Ҫ�������Ϣ������
����Ϣ���=�˻����+�˻����*���ʣ�����Ԫ����������ʽΪ friend void Update(Account& a);
��main�����У�����һ��Account���͵�ָ�����飬��ÿ��ָ��ָ��̬�����Account����
�����ó�Ա�������Դ�ȡ���ʾ�Ⱥ������ٵ�����Ԫ�������Խ��н�Ϣ�� 
��ҿ��Ը���ʵ�������������������������Ҳ�����޸ĳ�Ա�����Ĳ�������

����
��1�У�����
��2�У��˻���Ŀn
��3�п�ʼ��ÿ����������һ���˻��ġ��˺š��������������������������ȡ������

���
��1�п�ʼ��ÿ�����һ���˻��������Ϣ�������˺š��������������
�����Ϣ��ȡ�����
���һ����������˻�����

��������
0.01
3
201501 ���� 10000 1000 2000
201502 ���� 20000 2000 4000
201503 ���� 80000 4000 6000

�������
201501 ���� 11000 11110 9110
201502 ���� 22000 22220 18220
201503 ���� 84000 84840 78840
106170

����ĿҪ�����Account���updateȫ�ֺ����Ķ��塣����������Account�����ָ�����顢
�������ݡ��������ʡ���̬�������󲢵�����صĺ��������������̬�����Ķ���
*/

#include<iostream>
#include<string.h>
using namespace std;

class Account
{
	public:
		Account(){}
		Account(string accno,string name,float balance);
		~Account(){}
		static void Set(float a ,int b);
		void Deposit(float amount);  //��� 
		void changebalance(float a){_balance = a;}
		void withdraw(float  amonut);//ȡ�� 
		float GetBalance(){return _balance; }          // ��ȡ�˻���� 
		void Show();                 //��ʾ�˻����л�����Ϣ 
		static int GetCount(){return  Account::count;}       //��ȡ�˻��� 
		static float GetInterestRate(){return Account::InteresRate;}//��ȡ���� 
		friend void Update(Account& a);  //��Ԫ���� 
	private:
		static int count;             //�����˻����� 
		static float InteresRate;     //���� 
		string _accno,_accname;       //�˻��뻧�� 
		float _balance;               //�˻���� 
};

int Account::count = 0;
float Account::InteresRate = 0;

Account::Account(string accno,string name,float balance)
{

	_accno = accno ;
	_accname = name ;
	_balance = balance ;
}

void Account::Set(float a ,int b)
{
	Account::InteresRate = a;
	Account::count = b;
} 

void Account::Deposit(float amonut)
{
	_balance += amonut;
} 

void Account::withdraw(float amonut)
{
	_balance = _balance - amonut ;
} 

void Account::Show ()
{
	cout<<_accno<<" "<<_accname<<" "<<_balance<<" ";
}

void Update(Account *a)
{
	float k;
	k = a->GetBalance() + a->GetBalance() * a->GetInterestRate() ; 
	a->changebalance(k); 
	cout<<a->GetBalance()<<" ";
}

int main()
{
	float lilv;
	int n,i;
	string x1,x2;
	float x3,x4,x5,zz;
	cin>>lilv>>n;
	Account* a[20];
	Account::Set(lilv,n);
	for(i=0;i<n;i++)
	{
		cin>>x1>>x2>>x3>>x4>>x5;
		a[i] = new Account(x1,x2,x3);
		a[i]->Deposit(x4);
		a[i]->Show();
		Update(a[i]);
		a[i]->withdraw(x5);
		cout<<a[i]->GetBalance()<<endl;
		zz = zz + a[i]->GetBalance() ;
	} 
	cout<<zz;
	for(i=0;i<n;i++)
		delete a[i];
}






























