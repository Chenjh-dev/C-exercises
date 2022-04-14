/*
ʱ��ģ��(�̳У�

��Ŀ����
����������࣬�����������ݳ�Աvalue,���к���increment������1��
����ѭ���������̳м������࣬����˽�����ݳ�Ա����Сֵmin_value��max_value,
��д���к���increment��ʹ��value��min_value~max_value������ѭ��+1��
����ʱ���࣬���ݳ�Ա��˽��ѭ������������Сʱhour������minute����second��
���к���time(int s)���㵱ǰʱ�侭��s��֮���ʱ�䣬
��hour,minute,second����valueֵ��
����ʱ����������뵱ǰʱ��;���������,����time����������ʱ�䡣
������ĿҪ�����ӱ�Ҫ�Ĺ��캯���������������������躯����
��Ϊclock��ϵͳ���ú�����Ϊ�˱����������벻Ҫʹ��clock��Ϊ�������ߺ�����

����
��һ�в��Դ���n
2��һ�飬��һ��Ϊ��ǰʱ�䣨Сʱ ���� �룩���ڶ���Ϊ������������

���
���n��
ÿ�ж�Ӧÿ�鵱ǰʱ��;������������õ�����ʱ�䣨Сʱ�����ӣ��룩��

��������
2
8 19 20
20
23 30 0
1801

�������
8:19:40
0:0:1

������ĿҪ����ɼ�������CCounter��ѭ����������CRcounter��ʱ����CClock��Ķ��壬
�����඼���붨�幹�캯��,����CClock��������Ӷ������ݳ�Աhour��minute��second
����ΪCRcounter������������������ݡ�����CClock�����
��������time��Ա���������µ�ʱ�䡣
*/

#include<iostream>
using namespace std;

class CCounter
{
	protected:
		int value;
	public:
		CCounter(int a){ value=a; }
		int increment(){ return value++; }
		int get(){ return value; }
};

class CRcounter:public CCounter
{
	private:
		int min_value;
		int max_value;
	public:
		CRcounter(int a,int b,int c):CCounter(a)
		{
			min_value = b;
			max_value = c;
		}
		int increment()
		{
			value++;
			if( value >= max_value )
				value -= max_value;
			return value;
		}
};

class CClock
{
	private:
		CRcounter hour,minute,second;
	public:
		CClock(int a,int b,int c):hour(a,0,24),minute(b,0,60),second(c,0,60){}
		int time(int s)
		{
			while(s--)
			{
				if( second.increment() == 0 )
				{
					if( minute.increment() == 0 )
						hour.increment() ;
				}
			}
			cout<<hour.get()<<":"<<minute.get()<<":"<<second.get()<<endl; 
		}
};

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int h,m,s,n;
		cin>>h>>m>>s>>n;
		CClock k1(h,m,s);
		k1.time(n); 	
	}
};
