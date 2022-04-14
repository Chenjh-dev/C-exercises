/*
旅馆旅客管理（静态成员）

题目描述


编写程序，实现某旅馆的客人住宿记录功能。
定义一个Customer类，要求输入客人的姓名，创建一个Customer对象。类声明如下：
http://172.31.221.21/JudgeOnline/upload/pimg1101_1.jpg
调用类的Display函数输出客人ID（输出顺序号占4位，如第1位为0001，第2位为0002，依此类推）、
姓名、总人数。总人数和客人租金用静态成员，其他属性采用普通的数据成员。

输入
输入测试次数t
对于每次测试，首先输入当前年份，
接下来依次输入顾客姓名，0表示输入结束。

输出
每行依次输出顾客信息和旅馆信息。包括顾客姓名，顾客编号，旅馆入住总人数，旅馆当前总收入。

样例输入
2
2014
张三 李四 王五 0
2015
Cindy David 0

样例输出
张三 20140001 1 150
李四 20140002 2 300
王五 20140003 3 450
Cindy 20150004 4 600
David 20150005 5 750

根据题目要求完成Customer类的定义。主函数定义Customer类对象指针数组、
输入数据、设置年份、动态创建对象并调用打印成员函数输出相应的信息、最后析构动态创建的对象。
*/

#include<iostream>
#include<string.h>
using namespace std;

class Customer
{
	public:
		Customer(){}
		Customer(char* name);
		~Customer();
		static void changeYear(int r);
		void Display();
	private:
		static int TotalCustNum;
		static int Rent;
		static int Year;
		int CustID;
		char* CustName;
};

int Customer::TotalCustNum = 0;
int Customer::Rent = 0;
int Customer::Year = 2014;

Customer::Customer(char* name)
{
	CustName = new char[strlen(name)];
	strcpy(CustName,name);
	Customer::TotalCustNum ++;
	Customer::Rent += 150;
	CustID = Customer::Year * 10000 + Customer::TotalCustNum ;
} 

void Customer::changeYear(int r)
{
	Customer::Year = r ;
}

void Customer::Display() 
{
	cout<<CustName<<' '<<CustID<<' '<<Customer::TotalCustNum <<' '<<Customer::Rent <<endl; 
}

Customer::~Customer() 
{
	delete [] CustName;
}

int main()
{
	int t,y,i,j;
	cin>>t;
	char a[50];
	Customer* b[50];
	while(t--)
	{
		cin>>y;
		Customer::changeYear(y);
		cin>>a;
		for(i=0 ;a[0] != '0' ;i++ )
		{
			b[i] = new Customer(a);
			b[i]->Display() ;
			cin>>a;
		} 	
	}
	for(j=0;j<i;j++)
		delete b[j];
}
