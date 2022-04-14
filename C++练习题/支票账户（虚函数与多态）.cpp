/*
֧Ʊ�˻����麯�����̬��

��Ŀ����
ĳ���е�֧Ʊ�˻���Ϊ���࣬һ��Ϊ����֧Ʊ�˻�BaseAccount��
��һ��Ϊ����͸֧�������Ե�BasePlus֧Ʊ�˻���
BaseAccount֧Ʊ�˻�����Ϣ�������ͻ�����(name)���˻�(account)��
��ǰ����(balance)��BaseAccount֧Ʊ�˻�����ִ�еĲ������������(deposit)��
ȡ��(withdraw)����ʾ�˻���Ϣ(display)��ע�⣺ȡ�����͸֧��
������ʽ������Ϣ��insufficient����
BasePlus֧Ʊ�˻�������BaseAccount��������Ϣ�⣬������������Ϣ��
͸֧����(limit��Ĭ��Ϊ5000)����ǰ͸֧�ܶ�(limit_sum)��
BasePlus֧Ʊ�˻���ִ�еĲ�����BaseAccount��ͬ���������ֲ�����ʵ�ֲ�ͬ��
(1)����ȡ�������������͸֧���޷�Χ��͸֧����������ʾ������Ϣ��insufficient����
(2)������ʾ������������ʾBasePlus��������Ϣ��
��ʵ��BaseAccount���BasePlus�࣬����BasePlus��̳���BaseAccount�࣬
ע��BaseAccount�˻�������BA��ͷ��BasePlus�˻�������BP��ͷ��
Ҫ��ֻʹ��һ������ָ�룬ָ���������Ķ���Ȼ��ʹ��ָ��������еķ�����

����
���԰������� t
��һ��������ݣ�
��һ�������˻���Ϣ������ �ʺ� ��ǰ���
�ڶ��������ĸ���������ʾ���˻���˳���ȡ���ȡ��
�ڶ���������ݣ�
.........

���
���BaseAccount����Ϣ
���BasePlus����Ϣ

��������
4
Tom BA008 1000
1000 2000 1000 1200
Bob BP009 1000
1000 2000 1000 7000
May BA001 2000
500 1000 500 1000
Lily BP002 1000
500 2000 500 3000

�������
insufficient
Tom BA008 Balance:1000
insufficient
Bob BP009 Balance:1000 limit:5000
May BA001 Balance:1000
Lily BP002 Balance:0 limit:2000

����ĿҪ����ɻ���BaseAccount��������BasePlus�Ķ��塣�������������ݡ�
�û���ָ��ָ��̬�����Ķ��󲢵�����Ӧ�ĳ�Ա����ʵ�ֳ����ܡ�

*/

#include<iostream>
#include<cstring>
using namespace std;

class BaseAccount
{
	protected:
		string name;
		char account[10];
		int balance; 
	public:
		BaseAccount(string a,char b[10],int c)
		{
			name = a;
			strcpy(account,b);
			balance = c;
		}
		void deposit(int a){ balance += a; }
		virtual int withdraw(int a)
		{
			if(balance-a<0)
				return 0;
			else 
				balance-=a;
		}
		virtual void display(){ cout<<name<<" "<<account<<" Balance:"<<balance<<endl; }
};

class BasePlus:public BaseAccount
{
	private:
		int limit;
		int limit_sum;
	public:
		BasePlus(string a,char b[10],int c):BaseAccount(a,b,c){ limit=5000,limit_sum=5000;}
		int withdraw(int a)
		{
			if(balance-a < -1*limit)
				return 0;
			else if(balance-a<0)
			{
				limit_sum=limit+balance-a;
				balance-=a;
				return 1;
			}
			else 
			{
				balance-=a;
				return 1;
			}	
		}
		void display()
		{ 
			cout<<name<<" "<<account<<" Balance:";
			if(balance<0)
				cout<<"0";
			else
				cout<<balance;
			cout<<" limit:"<<limit_sum<<endl; 
		}
};

void show(BaseAccount *r)
{
	r->display() ;
}
int main()
{
	int t,k;
	string a;
	char b[10];
	int c,d1,d2,d3,d4;
	BaseAccount *p;
	cin>>t;
	while(t--)
	{
		cin>>a>>b>>c;
		cin>>d1>>d2>>d3>>d4;
		if(b[1]=='A')
		{
			p = new BaseAccount(a,b,c);
		}
		else if(b[1]=='P')
		{
			p = new BasePlus(a,b,c);
		}
		p->deposit(d1);
		if(!p->withdraw (d2)) 
		{
			cout<<"insufficient"<<endl;
			p->display() ;
		}
		p->deposit(d3);
		if(!p->withdraw (d4)) 
		{
			cout<<"insufficient"<<endl;
		}
		show(p) ; 
		delete p;
	}
}

