//���� : �ҳ�ĳ����Χ�ڵ���������(����������)

//��Ŀ����
//������˹����ɸ����ư���ɸ����ɸ����һ����ϣ����ѧ�Ұ�����˹�����������һ�ּ򵥼춨�������㷨��
//Ҫ�õ���Ȼ��n���ڵ�ȫ������������Ѳ����ڸ���n�����������ı����޳���ʣ�µľ���������
//����Ҫɸ��ֵ�ķ�Χn���ҳ����ڵ�����������2ȥɸ������2���£���2�ı����޳�����������һ��������
//Ҳ����3ɸ����3���£���3�ı����޳���������ȥ����һ������5ɸ����5���£���5�ı����޳����������ظ���ȥ......��
//���ð�����˹����ɸ�����������㷨��������CSieve����ʵ��:
//class CSieve
//{
//	private:
//         char *p_sieve;
//        unsigned long num;                //num�����Χ
//	public:
//         CSieve(unsigned long n);
//         void printPrime();
//         ~CSieve();
//};

//����p_sieveΪ����ָ��, p_sieve[i]=1��ʾi������, p_sieve[i]=0��ʾi����������
//��д�����������������ӡĳ����Χ�ڵ�����������


//����
//�������ݵ�����
//n1
//n2
//......

//���
//2��n1����������
//2��n2����������
//......


//��������
//2
//10
//20

//�������
//2 3 5 7
//2 3 5 7 11 13 17 19


#include<iostream>
#include<cmath>
using namespace std;

class CSieve
{
	private:
        char *p_sieve;
        unsigned long num;
	public:
        CSieve(unsigned long n)
        {
        	int i;
        	num = n;
        	p_sieve =new char[num+1];
    		for(i=0;i<num;i++)
    		{
    			p_sieve[i] ='1';
			}
		}
		void shaixuan();
        void printPrime();
        ~CSieve()
        {
        	delete [] p_sieve;
		}
};

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

void CSieve::printPrime()
{
	int i;
	for(i=2;i<=num+1;i++)
	{
		if(p_sieve[i]=='1')
		{
			cout<<i<<" ";
		}
	}
	cout<<endl;
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		CSieve s(n);
		s.shaixuan ();
        s.printPrime ();
	}
	return 0;
}

