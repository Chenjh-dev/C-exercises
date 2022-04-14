/*
���������ÿ����̳У�

��Ŀ����
����һ��������CAccount������������ʺţ�account, long����
������name,char[10])����balance,float�������ݳ�Ա��
����ʵ�ִ�deposit,�����ɹ���ʾ��saving ok!��)��
ȡ�withdraw�������ɹ���ʾ��withdraw ok!�����Ͳ�ѯ��check���Ĳ�����
ȡ�����������Χ�ڣ�������ʾ��sorry! over balance!����
�Ӵ��������������ÿ���CCreditcard�����ÿ���������͸֧�޶limit,float��
һ�����ݳ�Ա����ȡ����������޸ģ��������޶Χ��͸֧��
������Χȡ����ʾ��sorry! over limit!����
��д��������������������Ķ��󲢲���֮��
1.���ڴ����࣬�����˺š����������󣬰��ղ�ѯ����
��ѯ��ȡ���ѯ����˳������෽���������
2.�������ÿ��࣬�����˺š���������͸֧�޶��
���ղ�ѯ������ѯ��ȡ���ѯ����˳������෽���������

����
�˺� ���� ���
�����
ȡ����
�˺� ���� ��� ͸֧�޶�
�����
ȡ����

���
�˻����
���������
�˻���� 
ȡ��������
�˻����
�˻����
���������
�˻����
ȡ��������
�˻����

��������
1000 Tom 1000
500
1000
2000 John 500 500
500
1501

�������
balance is 1000
saving ok!
balance is 1500
withdraw ok!
balance is 500
balance is 500
saving ok!
balance is 1000
sorry! over limit!
balance is 1000

����ĿҪ����ɻ���CAccount��������CCreditcard,�����඼���붨�幹�캯����
�������������ݡ��ֱ�����󲢰�����ĿҪ�������Ӧ�ĳ�Ա����
����������ڳ�Ա������ֱ�������ʾ��Ϣ����
*/
#include<iostream>
#include<cstring>
using namespace std;

class CAccount
{
	protected:
		long account;
		char name[10];
		float balance;
	public:
		CAccount(long a,char b[10],float c)
		{
			account = a;
			strcpy(name,b);
			balance = c; 
		}
		void deposit(int a)
		{
			balance = balance+a;
			cout<<"saving ok!"<<endl;
		}
		void withdraw(int a)
		{
			if(balance-a<0)
			{
				cout<<"sorry! over balance!"<<endl;
			}
			else
			{
				balance=balance-a;
				cout<<"withdraw ok!"<<endl;	
			}	
		}
		void check()
		{
			cout<<"balance is "<<balance<<endl;
		}
};

class CCreditcard:public CAccount
{
	private:
		float limit;
	public:
		CCreditcard(long a,char b[10],float c,float d):CAccount(a,b,c),limit(d){}
		void withdraw(int a)
		{
			if(balance+limit-a<0)
			{
				cout<<"sorry! over limit!"<<endl;
			}
			else
			{
				balance=balance-a;
				cout<<"withdraw ok!"<<endl;
			}
		}
};

int main()
{
	long a;
	char b[10];
	float c,limit;
	int x1,x2;
	
	cin>>a>>b>>c;
	CAccount h1(a,b,c);
	h1.check() ;
	cin>>x1;
	h1.deposit(x1);
	h1.check() ;
	cin>>x2;
	h1.withdraw(x2);
	h1.check() ;
	
	cin>>a>>b>>c>>limit;
	CCreditcard h2(a,b,c,limit);
	h2.check() ;
	cin>>x1;
	h2.deposit(x1);
	h2.check() ;
	cin>>x2;
	h2.withdraw(x2);
	h2.check() ;
}




