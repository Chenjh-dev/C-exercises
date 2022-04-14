/*
日程安排（多继承+友元函数）

题目描述
已有一个日期类Date，包括三个protected成员数据year，month，day;
另有一个时间类Time，包括三个protected成员数据hour，minute，second，12小时制;
现需根据输入的日程的日期时间，安排前后顺序，为此以Date类和Time类为基类，
建立一个日程类Schedule，包括以下新增成员：
int ID；//日程的ID
定义友元函数bool before(const Schedule & s1，const Schedule & s2);//判断日程s1时间是否早于日程s2。 
编写主函数，根据输入的各项日程信息，建立日程对象，找出需要最早安排的日程
(日期和时间相等时，输出较早建立的日程），并输出该日程对象的信息。
相同的日程，取先输入的。

输入
测试输入包含若干日程，每个日程占一行（日程ID 日程日期 日程时间）。
当读入0时输入结束，相应的结果不要输出。

输出
时间最靠前的日程

样例输入
1 2019 6 27 8 0 1
2 2019 6 28 8 0 1
3 2020 1 1 8 0 0
0


样例输出
The urgent schedule is No.1: 2019/06/27 08:00:01

按题目要求定义Date类和Time类，及其多重继承派生类Schedule。
定义友元函数before以及查找最早日程的全局函数urgent。
主函数定义派生类对象指针数组、输入数据、动态创建对象。最后调用urgent函数。

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

















