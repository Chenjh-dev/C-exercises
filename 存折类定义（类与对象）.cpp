//���� : �����ඨ�壨�������

//��Ŀ����
//����һ��������CAccount������������ʺţ�account, long����������name,char[10])����balance,float�������ݳ�Ա��
//����ʵ�ִ�deposit,�����ɹ���ʾ��saving ok!��)��ȡ�withdraw�������ɹ���ʾ��withdraw ok!�����Ͳ�ѯ��check���Ĳ�����
//ȡ�����������Χ�ڣ�������ʾ��sorry! over limit!����
//��д�����������������Ķ��󲢲��ԣ������˺š����������󣬰��ղ�ѯ������ѯ��ȡ���ѯ����˳������෽���������


//����
//��һ�����۵��˺š����������
//�����
//ȡ����
//�ڶ������۵��˺š����������
//�����
//ȡ����

//���
//��һ�����۵��˻����
//���������
//�˻����
//ȡ��������
//�˻����
//�ڶ������۵��˻����
//���������
//�˻����
//ȡ��������
//�˻����


//��������
//9111 Tom 1000
//500
//1000
//92220 John 500
//500
//1500

//�������
//Tom's balance is 1000
//saving ok!
//Tom's balance is 1500
//withdraw ok!
//Tom's balance is 500
//John's balance is 500
//saving ok!
//John's balance is 1000
//sorry! over limit!
//John's balance is 1000


#include<iostream>
using namespace std;

class CAccount
{
	public:
		CAccount(long x1,string x2,float x3)
		{
			account =x1;
			name =x2;
			balance =x3;
			cout<<name<<"'s balance is "<<balance<<endl;
		}
		void deposit(int cun);
		void withdraw(int qu);
		void check();
	private:
		long account;
		string name;
		float balance;
		
};

void CAccount::deposit(int cun) 
{
	balance =balance+cun;
	cout<<"saving ok!"<<endl;
	cout<<name<<"'s balance is "<<balance<<endl;

}

void CAccount::withdraw(int qu) 
{
	if(balance >=qu)
	{
		balance=balance-qu;
		cout<<"withdraw ok!"<<endl;
	}
	else 
		cout<<"sorry! over limit!"<<endl;
}

void CAccount::check() 
{
	cout<<name<<"'s balance is "<<balance<<endl;
}


int main()
{
	int t=2;
	while(t--)
	{
		long a;
		string n;
		float b;
		cin>>a>>n>>b;
		CAccount s(a,n,b);
		int cun;
		cin>>cun;
		s.deposit(cun);
		int qu;
		cin>>qu;
		s.withdraw(qu) ;
		s.check() ;
	}
}
