/*

日期时间合并输出（友元函数）

题目描述
已知日期类Date，有属性：年、月、日，
其他成员函数根据需要自行编写，注意该类没有输出的成员函数
已知时间类Time，有属性：时、分、秒，其他成员函数根据需要自行编写，
注意该类没有输出的成员函数
现在编写一个全局函数把时间和日期的对象合并起来一起输出，
函数原型为：void Display(Date &, Time &)
函数输出要求为：
1、时分秒输出长度固定2位，不足2位补0
2、年份输出长度固定为4位，月和日的输出长度固定2位，不足2位补0
例如2017年3月3日19时5分18秒
则输出为：2017-03-03 19:05:18
程序要求
1、把函数Display作为时间类、日期类的友元
2、分别创建一个日期对象和时间对象，保存日期的输入和时间的输入
3、调用Print函数实现日期和时间的合并输出

输入
第一行输入t表示有t组示例
接着一行输入三个整数，表示年月日
再接着一行输入三个整数，表示时分秒
依次输入t组示例

输出
每行输出一个日期和时间合并输出结果
输出t行

样例输入
2
2017 3 3
19 5 18
1988 12 8
5 16 4

样例输出
2017-03-03 19:05:18
1988-12-08 05:16:04

根据题目要求完成Date类、Time类和全局函数Display的定义。
主函数输入数据、定义对象并调用Display函数输出相应的信息。
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

