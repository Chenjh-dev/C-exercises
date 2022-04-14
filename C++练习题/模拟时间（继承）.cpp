/*
ģ��ʱ�䣨�̳У�

��Ŀ����
����Time���������ʱ���֡��롣
����һ��������Time_12hours�࣬���ڱ�ʾʮ������ʱ�䣬�������³�Ա���ݣ�
char interval[5]; //��ʶΪAM����PM��interval=��AM����interval=��PM��
���Ӽ�һ��ͼ�һ��ĺ�����Ա��
���������ಢ��д����������������ĳ�ʼʱ����Ϣ��
���������Լ����͡����������Լ���������������ʱ����Ϣ��

����
������������������������һ����������Ϊһ�У�ÿ�й�������֣���һ������Ϊ���ƣ�121��ʾ����Ϊ12����AMʱ�䣬122��ʾ����Ϊ12����PMʱ�䣬�ڶ�������Ϊhour������������Ϊminute�����ĸ�����Ϊsecond��������ַ�Ϊ�������ͣ�+��ʾ������-��ʾ�Լ�������������Ϊ���������0��ʾ��������������

���
������ɺ��ʱ��

��������
121 11 59 59 + 3
122 00 00 00 - 3
0

�������
PM 00:00:02
AM 11:59:57

������ĿҪ����ɻ���CTime��������CTime12��Ķ��壬
�����඼���붨�幹�캯�����������������ݡ�����CTime12�����
�������������Լ���Ա���������µ�ʱ�䡣
*/

#include<iostream>
#include<string.h>
#include<iomanip>
using namespace std;

class Time
{
	public:
		Time(int a,int b,int c)
		{
			h=a,m=b,s=c;
		}
	protected:
		int h,m,s;
};

class Time_12hours:public Time
{
	public:
		Time_12hours(int a,int b,int c,int d):Time(b,c,d)
		{
			if(a==121)
				strcpy(interval,"AM");
			else if(a==122)
				strcpy(interval,"PM");
			else
				cout<<"error"<<endl;
		}
		void changeinterval()
		{
			if(strcmp(interval,"AM"))
				strcpy(interval,"AM");
			else if(strcmp(interval,"PM"))
				strcpy(interval,"PM");
			else
				cout<<"error"<<endl;
		}
		void add(int n)
		{
			s=s+n;
			while(s>=60)
			{
				s=s-60;
				m=m+1;
				if(m>=60)
				{
					m=m-60;
					h=h+1;
					if(h>=12)
					{
						h=h-12;
						changeinterval() ;
					}
				}
			}
		}
		void min(int n)
		{
			s=s-n;
			while(s<0)
			{
				s=s+60;
				m=m-1;
				if(m<0)
				{
					m=m+60;
					h=h-1;
					if(h<0)
					{
						h=h+12;
						changeinterval() ;
					}	
				}
			}
		}
		void print()
		{
			cout<<interval<<" "<<setfill('0')<<setw(2)<<h<<":"<<setfill('0')<<setw(2)<<m<<":"<<setfill('0')<<setw(2)<<s<<endl;
		}
	private:
		char interval[5];
};

int main()
{
	int a,b,c,d,e;
	char f;
	cin>>a;
	while(a!=0)
	{
		cin>>b>>c>>d>>f>>e;
		Time_12hours hh(a,b,c,d);
		if(f=='+')
			hh.add(e);
		else if(f=='-') 
			hh.min(e);
		hh.print() ;
		cin>>a; 
	}
}
