/*
�������ÿ�(���ؼ̳�)

��Ŀ����
�ó̻�Ա�����л�Ա���ţ�int�����ó̻��֣�int����ͨ����Ա���¶���������������ۼ��ó̻��֡�
���ÿ����п��ţ�int����������string)����ȣ�int)���˵���float)�����ÿ����֣�int��------��ע����������
���ÿ��˿�m���˵����-m�����ÿ����ּ�ȥ�˿��
��ʼ�������ÿ����֡��ó̻��֡��˵����Ϊ0��
�����ó����ÿ��������뿨��Ϣ�����ö����Ա��������ó����µ������ÿ�ˢ����
���ÿ��˿���ÿ����ֶһ�Ϊ�ó̻��ֵȲ�����
�����������ݣ������ó̻�Ա���ࡢ���ÿ��࣬�������������ó����ÿ���
������������Ĺ��캯�����������躯����
ͨ���ó����ÿ����ó����µ����ó̻��ֺ����ÿ�����˫�ػ���
�����ó̻��ֺ����ÿ�����ͬʱ���ӣ���
�ó����ÿ����԰�      �ó̻��֣����ÿ�����= 1��2    �ı��������ÿ����ֶһ�Ϊ�ó̻��֡�
���ÿ����ѽ��m�����������˵�����ȣ����������������˵����+m��
���ÿ����ְ����ѽ���ۼӡ�
ĳ������վ�������ó�������ĳ�����Ƴ������ۺϷ������������ó����ÿ���
����ó̻�Ա�����������ÿ����ܡ�

����
��һ�У������ó̻�Ա���� ���ÿ��� ���� ���
�ڶ��У����Դ���n
�����е���n+2�У�ÿ�У����� �������
o   m���ó����¶������������m�� 
c   m�����ÿ����ѣ����ѽ��m��
q   m (���ÿ��˿�˿���m��
t    m�����ֶһ���m���ÿ����ֶһ�Ϊ�ó̻��֣�

���
������в������ó����ÿ�����Ϣ��
�ó̺�   �ó̻���
���ÿ���  ����   �˵����   ���ÿ�����

��������
1000 2002  lili  3000
4
o 212.5
c 300
q 117.4
t 200

�������
1000 312
2002 lili 395.1 195

����ĿҪ�����ó̻�Ա����CVip�����ÿ���CCredit������ؼ̳��������ó����ÿ���CVipCredit,
�������캯�����¶��������ÿ����ѡ����ÿ��˿���ÿ����ֶһ��ȳ�Ա������
�������������ݡ�������������󲢵�����Ӧ�ĳ�Ա����ʵ�ֳ���Ĺ��ܡ�

*/

#include<iostream>
#include<cstring>
using namespace std;

class CVip
{
	protected:
		int cardnum1;
		int jifen1;
	public:
		CVip(int a)
		{
			cardnum1 = a;
			jifen1 = 0;
		}
		void print()
		{
			cout<<cardnum1<<" "<<jifen1<<endl;
		}
};

class CCredit
{
	protected:
		int cardnum2;
		string name;
		int limit;
		float money;
		int jifen2;
	public:
	CCredit(int a,string b,int c)
	{
		cardnum2 = a;
		name = b;
		limit = c;
		money = 0;
		jifen2 = 0;
	}
	void print()
	{
		cout<<cardnum2<<" "<<name<<" "<<money<<" "<<jifen2<<endl;
	}
};

class CVipCredit:public CVip,public CCredit
{
	public:
		CVipCredit(int a,int b,string c,int d):CVip(a),CCredit(b,c,d){}
		void order(float a)
		{
			money += a;
			jifen1 += (int)a;
			jifen2 += (int)a;
		}
		void expense(float a)
		{
			if(a+money<=limit)
			{
				money += a;
				jifen2 += (int)a;
			}
		}
		void refund(float a)
		{
			money -= a;
			jifen2 -= (int)a;
		}
		void change(int a)
		{
			jifen2 -= a;
			jifen1 += a/2; 
		}
		void print()
		{
			CVip::print() ;
			CCredit::print() ;
		}
};

int main()
{
	int a,b,d,n,jifen;
	string c;
	char k;
	float money;
	cin>>a>>b>>c>>d;
	CVipCredit h(a,b,c,d);
	cin>>n;
	while(n--)
	{
		cin>>k;
		if(k=='o')
		{
			cin>>money;
			h.order(money) ;
		}
		if(k=='c')
		{
			cin>>money;
			h.expense(money); 
		}
		if(k=='q')
		{
			cin>>money;
			h.refund(money); 
		}
		if(k=='t')
		{
			cin>>jifen;
			h.change(jifen) ; 
		}
	}
	h.print() ;
}


