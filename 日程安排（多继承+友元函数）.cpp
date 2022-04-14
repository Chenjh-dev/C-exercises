/*
�ճ̰��ţ���̳�+��Ԫ������

��Ŀ����
����һ��������Date����������protected��Ա����year��month��day;
����һ��ʱ����Time����������protected��Ա����hour��minute��second��12Сʱ��;
�������������ճ̵�����ʱ�䣬����ǰ��˳��Ϊ����Date���Time��Ϊ���࣬
����һ���ճ���Schedule����������������Ա��
int ID��//�ճ̵�ID
������Ԫ����bool before(const Schedule & s1��const Schedule & s2);//�ж��ճ�s1ʱ���Ƿ������ճ�s2�� 
��д����������������ĸ����ճ���Ϣ�������ճ̶����ҳ���Ҫ���簲�ŵ��ճ�
(���ں�ʱ�����ʱ��������罨�����ճ̣�����������ճ̶������Ϣ��
��ͬ���ճ̣�ȡ������ġ�

����
����������������ճ̣�ÿ���ճ�ռһ�У��ճ�ID �ճ����� �ճ�ʱ�䣩��
������0ʱ�����������Ӧ�Ľ����Ҫ�����

���
ʱ���ǰ���ճ�

��������
1 2019 6 27 8 0 1
2 2019 6 28 8 0 1
3 2020 1 1 8 0 0
0


�������
The urgent schedule is No.1: 2019/06/27 08:00:01

����ĿҪ����Date���Time�࣬������ؼ̳�������Schedule��
������Ԫ����before�Լ����������ճ̵�ȫ�ֺ���urgent��
�������������������ָ�����顢�������ݡ���̬��������������urgent������

*/

#include<iostream>
#include<iomanip>
using namespace std;

class Date
{
	protected:
		int year,month,day;
	public:
		Date(int a,int b,int c)
		{
			year = a;
			month = b;
			day = c; 
		}
};

class Time
{
	protected:
		int hour,minute,second;
	public:
		Time(int a,int b,int c)
		{
			hour = a;
			minute = b;
			second = c;
		}
};

class Schedule:public Date,public Time
{
	private:
		int ID;
	public:
		Schedule(int id,int a,int b,int c,int d,int e,int f):Date(a,b,c),Time(d,e,f)
		{
			ID = id;
		}
		friend bool before(const Schedule &s1,const Schedule &s2)
		{
			if(s1.year*10000000000+s1.month*100000000+s1.day*1000000+s1.hour*10000+s1.minute*100+s1.second <= s2.year*10000000000+s2.month*100000000+s2.day*1000000+s2.hour*10000+s2.minute*100+s2.second)
				return 0;
			else
				return 1;
		}
		void print()
		{
			cout<<"The urgent schedule is No."<<ID<<": "<<year<<"/"<<setw(2)<<setfill('0')<<month<<"/"<<setw(2)<<setfill('0')<<day<<" "<<setw(2)<<setfill('0')<<hour<<":"<<setw(2)<<setfill('0')<<minute<<":"<<setw(2)<<setfill('0')<<second<<endl;
		}
};

int main()
{
	int id,a,b,c,d,e,f;
	cin>>id>>a>>b>>c>>d>>e>>f;
	Schedule h1(id,a,b,c,d,e,f);
	cin>>id;
	while(id)
	{
		cin>>a>>b>>c>>d>>e>>f;
		Schedule h2(id,a,b,c,d,e,f);
		if(before(h1,h2))
			h1=h2;
		cin>>id;
	}
	h1.print() ;
}

















