/*
���п�����̬+�̳У�

��Ŀ����
ĳ���п���Ϊ��ͨ������ͨ������������֣�������ͨ������򵥵Ŀ���
�������԰������ţ�ID����������CName������Counter��������������
��ʼ����initial������save����ȡ�take������ѯ��info����
��ͨ�������Ժͷ���˵������:
1.������һ�����֣������õ�����ĸ��ʾ�������һ���Ǹ�����
2.���������������һ�ʿ����������������������Ϸ�����ֱ�ӷ���-1��ִ�гɹ��򷵻�1
3.ȡ�������������һ�ʿ������������������Ҳ��ܳ�����
���Ϸ�����ֱ�ӷ���-1��ִ�гɹ��򷵻�1
4.��ѯ������������������Ϣ���������š�����������Ϣ֮���õ����̻�������
��ͨ������ͨ���������棬�������������ǽ�ͨ��Tcounter����
ʹ�ý�ͨ���ܹ���������ͨʹ�ã��������ⷽ����ת�ʣ�transfer����
�����п���Ǯת�뽻ͨ����У�ע��ת�ʽ��ܳ����˻�ԭ����
���Ϸ�����ֱ�ӷ���-1��ִ�гɹ��򷵻�1
���������ͨ���������棬�����������������ö�ȣ�Credit����
ʹ�ù�����ܹ�͸֧����ȡ����������Ǯ�������Ķ��ⷽ����͸֧��over����
��ִ��͸֧�����������0���������Ĳ��������ö�����ۼ���
ע��͸֧�������ܳ������+���ö�ȣ����Ϸ�����ֱ�ӷ���-1��ִ�гɹ��򷵻�1
ʹ��c++���Ժ���̳з���ʵ���������п��Ĺ���
ע�⣬�����ύ�������ֳ��ඨ�塢��ʵ�֡��������������򣬲���ע�ͱ���
��̬���������������˵���ο����£�

����
��һ������һ����ͨ�������ݣ��ֱ�������š����������
�ڶ�������һ�Ž�ͨ�������ݣ��ֱ�������š�����������ͨ���
����������һ�Ź���������ݣ��ֱ�������š������������ö��
�����������ĸ���������ʾ����ͨ����˳����ִ��2�δ�2��ȡ��
�����������ĸ���������ʾ�Խ�ͨ����˳��ִ��1�δ�1��ȡ�2��ת��
�����������ĸ���������ʾ�Թ������˳��ִ��1�δ�1��ȡ�2��͸֧

���
���ö�̬���������ſ�ִ�в�ѯ����ʾִ����ǰ�����в�����ĸ�������Ϣ��
��ͨ����Ϣ��ʽ������-����-���
����Ϣ��ʽ������-����-���-��ͨ���
�������Ϣ��ʽ������-����-���-͸֧���
ע�⣺��������������ֱ�ӵ������info����������ʹ�ö�̬���������á�

��������
1111 A 100
2222 B 200 0
3333 C 300 3000
49 -51 -100 50
100 150 500 55
300 200 2000 5000

�������
1111-A-99
2222-B-95-55
3333-C-0-1400

������ĿҪ�������ͨ��CCard��������Ľ�ͨ��CGuest�ࡢ�����CVip��Ķ��壬
������5��ʵ�ִ��(deposit)��ȡ��(withdraw)��ת��(transfer)��͸֧(overdraft)��
��ӡ(show)���ܵ�ȫ�ֺ���,����Щȫ�ֺ����������ĳ�Ա����ʵ����Ӧ�Ĺ��ܡ�
�������������ݡ�������ָ��ָ��̬�����������������󲢷ֱ�����Ϊʵ�ε���deposit��
withdraw��transfer��overdraft��show������ʵ�ֳ����ܡ�

*/

#include<iostream>
using namespace std;

class CCard
{
	protected:
		int ID;
		char CName;
		int balance;
	public:
		CCard(){}
		virtual void initial(int a,char b,int c)
		{
			ID=a;
			CName=b;
			balance=c;
		}
		int deposit(int a)
		{
			if(a>0)
			{
				balance+=a;
				return 1;
			}	
			else
				return -1;
		}
		int withdraw(int a)
		{
			if(a>0 && a<balance )
			{
				balance-=a;
				return 1;
			}
			else
				return -1;
		}
		virtual void show(){ cout<<ID<<"-"<<CName<<"-"<<balance<<endl; }
};

class CGuest:public CCard
{
	private:
		int Tcounter;
	public:
		CGuest(){}
		void initial(int a,char b,int c,int d)
		{ 
			ID=a;
			CName=b;
			balance=c;
			Tcounter = d; 
		}
		int transfer(int a)
		{
			if(a>balance)
				return -1;
			else
			{
				Tcounter+=a;
				balance-=a;
				return 1;
			}
		}
		void show(){ cout<<ID<<"-"<<CName<<"-"<<balance<<"-"<<Tcounter<<endl; }
};

class CVip:public CCard
{
	private:
		int Credit;
	public:
		CVip():CCard(){}
		void initial(int a,char b,int c,int d)
		{ 
			ID=a;
			CName=b;
			balance=c;
			Credit=d; 
		}
		int overdraft(int a)
		{
			if(a>balance+Credit)
				return -1;
			else
			{
				if(balance>0)
				{
					Credit=Credit+balance-a;
					balance=0;
				}
				else
				{
					Credit-=a;
				}
			}
		}
		void show(){ cout<<ID<<"-"<<CName<<"-"<<balance<<"-"<<Credit<<endl; }
};

void Show(CCard *p)
{
	p->show() ;
}

int main()
{
	int a,c,d;
	int k1,k2,k3,k4;
	char b;
	CCard *p1;
	p1=new CCard();
	CGuest *p2;
	p2=new CGuest();
	CVip *p3;
	p3=new CVip();
 
	cin>>a>>b>>c;
	p1->initial(a,b,c);
	cin>>a>>b>>c>>d;
	p2->initial(a,b,c,d);
	cin>>a>>b>>c>>d;
	p3->initial(a,b,c,d);
	
	cin>>k1>>k2>>k3>>k4;
	p1->deposit(k1);
	p1->deposit(k2);
	p1->withdraw(k3);
	p1->withdraw(k4); 
	
	cin>>k1>>k2>>k3>>k4;
	p2->deposit(k1);
	p2->withdraw(k2);
	p2->transfer(k3);
	p2->transfer(k4);
	
	cin>>k1>>k2>>k3>>k4;
	p3->deposit(k1);
	p3->withdraw(k2);
	p3->overdraft(k3);
	p3->overdraft(k4);
	
	Show(p1);
	Show(p2);
	Show(p3);
	
	delete p1,p2,p3;
}
