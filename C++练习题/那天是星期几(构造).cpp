//问题 : 那天是星期几(构造)

//完成如下所示的CDate类中构造函数和其它成员函数的定义，并编写程序实现按下列格式打印某个日期的功能：mm/dd/yyyy, 星期。
//(提示：计算某个日期(day, month, year)为星期几的公式如下：
//week = (day + 2*month + 3*(month+1)/5 + year + year/4 - year/100 + year/400) % 7 + 1;
//其中，如果month实际为1或2,则计算时公式里month的值取13或14, 且year的值取其实际值减1的值）。

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


//输入
//日期个数
//第一个日期
//第二个日期
//.......


//输出
//日期1月/日期1日/日期1年, 日期1星期
//日期2月/日期2日/日期2年, 日期2星期
//......


//样例输入
//3
//1949 10 1
//2015 1 1
//2011 11 11

//样例输出
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
