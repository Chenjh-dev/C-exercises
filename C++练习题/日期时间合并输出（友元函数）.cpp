/*

����ʱ��ϲ��������Ԫ������

��Ŀ����
��֪������Date�������ԣ��ꡢ�¡��գ�
������Ա����������Ҫ���б�д��ע�����û������ĳ�Ա����
��֪ʱ����Time�������ԣ�ʱ���֡��룬������Ա����������Ҫ���б�д��
ע�����û������ĳ�Ա����
���ڱ�дһ��ȫ�ֺ�����ʱ������ڵĶ���ϲ�����һ�������
����ԭ��Ϊ��void Display(Date &, Time &)
�������Ҫ��Ϊ��
1��ʱ����������ȹ̶�2λ������2λ��0
2�����������ȹ̶�Ϊ4λ���º��յ�������ȹ̶�2λ������2λ��0
����2017��3��3��19ʱ5��18��
�����Ϊ��2017-03-03 19:05:18
����Ҫ��
1���Ѻ���Display��Ϊʱ���ࡢ���������Ԫ
2���ֱ𴴽�һ�����ڶ����ʱ����󣬱������ڵ������ʱ�������
3������Print����ʵ�����ں�ʱ��ĺϲ����

����
��һ������t��ʾ��t��ʾ��
����һ������������������ʾ������
�ٽ���һ������������������ʾʱ����
��������t��ʾ��

���
ÿ�����һ�����ں�ʱ��ϲ�������
���t��

��������
2
2017 3 3
19 5 18
1988 12 8
5 16 4

�������
2017-03-03 19:05:18
1988-12-08 05:16:04

������ĿҪ�����Date�ࡢTime���ȫ�ֺ���Display�Ķ��塣
�������������ݡ�������󲢵���Display���������Ӧ����Ϣ��
*/

#include<iostream>
#include<iomanip>
using namespace std;

class Time;
class Date
{
	public:
		Date(int a,int b,int c)
		{
			year = a;
			month = b;
			day = c;
		}
		friend void Display(Date &a,Time &b);
	private:
		int year;
		int month;
		int day;
};

class Time
{
	public:
		Time(int a,int b,int c)
		{
			h = a;
			m = b;
			s = c;
		}
		friend void Display(Date &a, Time &b);
	private:
		int h;
		int m;
		int s;
};

void Display(Date &a, Time &b)
{
	cout<<setw(4)<<a.year<<"-"<<setfill('0')<<setw(2)<<a.month<<"-"<<setfill('0')<<setw(2)<<a.day<<" "<<setfill('0')<<setw(2)<<b.h<<":"<<setfill('0')<<setw(2)<<b.m<<":"<<setfill('0')<<setw(2)<<b.s<<endl;
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int y,month,d,h,m,s;
		cin>>y>>month>>d>>h>>m>>s;
		Date a(y,month,d);
		Time b(h,m,s);
		Display(a,b);
	}
}

