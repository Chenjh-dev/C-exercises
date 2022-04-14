/*
ɸ��������(��̬���ݳ�Ա�;�̬��Ա����)

��Ŀ����
�ð�����˹����ɸ����num֮�ڵ������������ΰѲ�����num��ƽ���������������ı����޳���
Ҳ�����ȴ�2��ʼ����2�ı����޳�,Ȼ�����һ��ʣ�µ���С����3�ı����޳�����������ֱ��������num��ƽ���������ʣ�µľͶ���������
����CSieve��������sieve��ʾɸ�ӣ�sieve[i]='1'��ʾi������, sieve[i]='0'��ʾi���޳���������: 
class CSieve
 {
 private:
         char *sieve;
         unsigned long num;
         void findPrime();     //��ɸ��ɸ��2��num֮������з�����(ʹ��Ӧ��sieve����Ԫ��Ϊ'0')
 public:
         CSieve(unsigned long n);
         void printPrime();        //��ӡ����sieve[i]='1'��i
         ~CSieve();
 };
�޸���������CSieve�࣬ʹ����CSieve��Ķ�����sieve���鲢�ܹ�����������printPrime()��
����¶���Ķ����numֵ������sieve����Ĵ�С,���ʾ�÷�Χ�ڵ������Ѿ�ɸѡ��ϣ������ٵ���findPrime()��
����¶���Ķ����numֵ����sieve����Ĵ�С,����Ҫ���·���sieve������Ϊɸ�Ӳ�����findPrime()�ҳ��·�Χ�ڵ�����������
(��������ʾ�����ȸ��ݲ��Դ�������CSieve����ָ�����飬ÿ�β��Զ�̬����CSieve����) 

����
��һ��������Դ�����
ÿ�β�������һ�У�����������n������2����

���
ÿ�β������һ�У���2��n������������

��������
3
23
100
44

�������
2 3 5 7 11 13 17 19 23
2 3 5 7 11 13 17 19 23 29 31 37 41 43 47 53 59 61 67 71 73 79 83 89 97
2 3 5 7 11 13 17 19 23 29 31 37 41 43

����ĿҪ����CSieve��(���뽫sieveָ�붨��Ϊ��̬���ݳ�Ա),
����������CSieve�����ָ�����顢�������ݡ���̬�������󲢵���printPrime��Ա�������������
*/

#include<iostream>
#include<cmath>
using namespace std;

class CSieve
{
	private:
        static char *p_sieve;
        unsigned long num;
	public:
        CSieve(unsigned long n)
        {
        	int i;
        	num = n;
        	p_sieve =new char[num+1];
    		for(i=0;i<=num;i++)
    		{
    			p_sieve[i] ='1';
			}
		}
		void shaixuan();
		int getnum()
		{
			return num;
		}
        void printPrime(int k,int mm);
        ~CSieve(){}
};

char *CSieve::p_sieve = NULL;

void CSieve::shaixuan()
{
	int n,i;
	for(n=2;n<=sqrt(num);n++)
	{
		if(p_sieve[n] == '0')
			continue;
		for(i=n*2;i<=num;i+=n)
			p_sieve[i]='0';
		
	}
}

void CSieve::printPrime(int k,int mm)
{
	int i;
	if(mm==1)
	{
		for(i=2;i<=k;i++)
		{
			if(p_sieve[i]=='1')
			{
				cout<<i<<" ";
			}
		}
	}
	else
	{
		for(i=2;i<=num;i++)
		{
			if(p_sieve[i]=='1')
			{
				cout<<i<<" ";
			}
		}
	}
	
	cout<<endl;
}

int main()
{
	int t,i=0,mm=1;
	int n[20];
	int k[20]={0};
	int j=0;
	cin>>t;
	CSieve* s[20];
	while(t--)
	{
		cin>>n[i];
		if( i>0 && n[i] <= n[j] )
		{
			s[i-1]->printPrime(n[i],mm);
		}
		else
		{
			j=i;
		 	s[i] = new CSieve(n[i]);
			s[i]->shaixuan ();
  	   		s[i]->printPrime (n[i],mm);
  	   		k[i]=1;
		}
        i++;
	}
	for(i=0;i<20;i++)
	{
		if(k[i]==1)
			delete s[i];
	}
}
