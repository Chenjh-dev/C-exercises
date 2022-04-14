//���� : ���������ڼ�(����)

//���������ʾ��CDate���й��캯����������Ա�����Ķ��壬����д����ʵ�ְ����и�ʽ��ӡĳ�����ڵĹ��ܣ�mm/dd/yyyy, ���ڡ�
//(��ʾ������ĳ������(day, month, year)Ϊ���ڼ��Ĺ�ʽ���£�
//week = (day + 2*month + 3*(month+1)/5 + year + year/4 - year/100 + year/400) % 7 + 1;
//���У����monthʵ��Ϊ1��2,�����ʱ��ʽ��month��ֵȡ13��14, ��year��ֵȡ��ʵ��ֵ��1��ֵ����

//class CDate
//{
// public:
//      void print();
//      void getWeekofDay();
// private:
//        int month;
//        int day;
//        int year;
//        int week;
//};


//����
//���ڸ���
//��һ������
//�ڶ�������
//.......


//���
//����1��/����1��/����1��, ����1����
//����2��/����2��/����2��, ����2����
//......


//��������
//3
//1949 10 1
//2015 1 1
//2011 11 11

//�������
//10/1/1949, Saturday
//1/1/2015, Thursday
//11/11/2011, Friday



#include<iostream>
using namespace std;

class CDate
{
	public:
		CDate(int m,int d,int y)
		{
			month = m;
			day = d;
			year = y;
			week = 0;
		}
		void getWeekofDay();
		void print();
	private:
		int  month;
		int day;
		int year;
		int week;
};

void CDate::getWeekofDay() 
{
	if(month ==1)
	{
		month =13;
		year--;
	}
	if(month ==2)
	{
		month =14;
		year--;
	}
	week = (day + 2*month + 3*(month+1)/5 + year + year/4 - year/100 + year/400) % 7 + 1;
	if(month ==13)
	{
		month =1;
		year++;
	}
	if(month ==14)
	{
		month =2;
		year++;
	}
}

void CDate::print() 
{
	string m;
	switch(week)
	{
		case 1:m="Monday";break;
		case 2:m="Tuesday";break;
		case 3:m="Wednesday";break;
		case 4:m="Thursday";break;
		case 5:m="Friday";break;
		case 6:m="Saturday";break;
		case 7:m="Sunday";break;
	}
	cout<<month<<"/"<<day<<"/"<<year<<", "<<m<<endl;
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int m,d,y;
		cin>>y>>m>>d;
		CDate s(m,d,y);
		s.getWeekofDay() ;
		s.print() ;
	}
	return 0;
}
