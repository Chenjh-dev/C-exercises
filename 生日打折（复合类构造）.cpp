//生日打折（复合类构造）

//题目描述
//定义一个日期类Date，包含数据成员year\month\day，
//还包含构造函数及其他函数(根据需要自己添加)
//定义一个会员类VIP，包含数据成员id和birth，
//其中id是整数表示会员编号；birth是Date类型表示生日。

//类VIP包含构造函数和其他函数（根据需要自己添加），
//还包含一个折扣函数Discount。函数Discount返回结果为浮点数表示折扣，
//函数包含1个参数为日期类型，函数功能是判断参数日期是否会员生日，
//是则折扣为0.5，不是则折扣为0.95
//编写程序实现上述类功能并实现输入输出的要求

//输入
//第一行输入年、月、日，表示今天日期
//第二行输入t表示有t个会员
//第三行输入第1个会员的ID、生日的年、月、日
//第四行输入第1个会员的消费金额
//依次类推输入下一个会员的两行数据.....

//输出
//根据会员的消费金额，调用Discount函数判断今天是否会员生日并得到折扣，
//然后计算会员打完折的消费金额
//每一行先输出会员编号，再输出会员打完折的消费金额，消费金额只需要输出整数部分
//提示把浮点数转整数
//double x = 123.456
//cout<<int(x)<<endl;

//样例输入
//2017 4 20
//2
//1111 2000 4 20
//136
//2222 2000 3 30
//125

//样例输出
//1111's consumption is 68
//2222's consumption is 118


//按题目要求完成Date类和VIP类的定义(不能在成员函数里用cin输入)。
//主函数实现数据的输入、对象的定义并依次调用Discount成员函数、
//计算消费金额的成员函数和打印输出的成员函数。

#include<iostream>
using namespace std;

class Date
{
	private:
		int year;
		int month;
		int day;
	public:
		Date(){}
		Date(int x1,int x2,int x3)
		{
			year = x1;
			month = x2;
			day = x3;
		}
		int Getyear(){return year;}
		int Getmonth(){return month;}
		int Getday(){return day;}
};

class VIP
{
	private:
		int id;
		Date birth;
		int year;
		int month;
		int day;
		double zhekou;
		double money;
	public:
		VIP(int x4,int x5,int x6)
		{
			year = x4;
			month = x5;
			day = x6;
		}
		void Get(int a,double b)
		{
			id = a;
			money = b;
		}
		void Discount(Date &p)
		{
			birth = p;
			if(birth.Getday() == day && birth.Getmonth() == month )
				zhekou = 0.5;
			else 
				zhekou = 0.95;
		}
		void JIsuan()
		{
			money = money*zhekou;
		}
		void printf()
		{
			cout<<id<<"'s consumption is "<<int(money)<<endl;
		}
};

int main()
{
	int k1,k2,k3;
	cin>>k1>>k2>>k3;
	VIP a(k1,k2,k3);
	int t;
	cin>>t;
	while(t--)
	{
		int ID,k4,k5,k6;
		double money;
		cin>>ID>>k4>>k5>>k6>>money;
		Date b(k4,k5,k6);
		a.Get(ID,money) ;
		a.Discount(b);
		a.JIsuan() ;
		a.printf() ; 
	}
	return 0;
}
