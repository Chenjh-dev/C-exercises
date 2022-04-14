/*
存折与信用卡（继承）

题目描述
定义一个存折类CAccount，存折类具有帐号（account, long）、
姓名（name,char[10])、余额（balance,float）等数据成员，
可以实现存款（deposit,操作成功提示“saving ok!”)、
取款（withdraw，操作成功提示“withdraw ok!”）和查询余额（check）的操作，
取款金额必须在余额范围内，否则提示“sorry! over balance!”。
从存折类派生出信用卡类CCreditcard，信用卡类增加了透支限额（limit,float）
一项数据成员，对取款操作进行修改，允许在限额范围内透支金额，
超出范围取款提示“sorry! over limit!”。
编写主函数，建立这两个类的对象并测试之。
1.对于存折类，输入账号、姓名、余额后，按照查询余额、存款、
查询余额、取款、查询余额的顺序调用类方法并输出。
2.对于信用卡类，输入账号、姓名、余额、透支限额后，
按照查询余额、存款、查询余额、取款、查询余额的顺序调用类方法并输出。

输入
账号 姓名 余额
存款金额
取款金额
账号 姓名 余额 透支限额
存款金额
取款金额

输出
账户余额
存款操作结果
账户余额 
取款操作结果
账户余额
账户余额
存款操作结果
账户余额
取款操作结果
账户余额

样例输入
1000 Tom 1000
500
1000
2000 John 500 500
500
1501

样例输出
balance is 1000
saving ok!
balance is 1500
withdraw ok!
balance is 500
balance is 500
saving ok!
balance is 1000
sorry! over limit!
balance is 1000

按题目要求完成基类CAccount和派生类CCreditcard,两个类都必须定义构造函数。
主函数输入数据、分别定义对象并按照题目要求调用相应的成员函数
（本题可以在成员函数里直接输出提示信息）。
*/
#include<iostream>
#include<cstring>
using namespace std;

class CAccount
{
	protected:
		long account;
		char name[10];
		float balance;
	public:
		CAccount(long a,char b[10],float c)
		{
			account = a;
			strcpy(name,b);
			balance = c; 
		}
		void deposit(int a)
		{
			balance = balance+a;
			cout<<"saving ok!"<<endl;
		}
		void withdraw(int a)
		{
			if(balance-a<0)
			{
				cout<<"sorry! over balance!"<<endl;
			}
			else
			{
				balance=balance-a;
				cout<<"withdraw ok!"<<endl;	
			}	
		}
		void check()
		{
			cout<<"balance is "<<balance<<endl;
		}
};

class CCreditcard:public CAccount
{
	private:
		float limit;
	public:
		CCreditcard(long a,char b[10],float c,float d):CAccount(a,b,c),limit(d){}
		void withdraw(int a)
		{
			if(balance+limit-a<0)
			{
				cout<<"sorry! over limit!"<<endl;
			}
			else
			{
				balance=balance-a;
				cout<<"withdraw ok!"<<endl;
			}
		}
};

int main()
{
	long a;
	char b[10];
	float c,limit;
	int x1,x2;
	
	cin>>a>>b>>c;
	CAccount h1(a,b,c);
	h1.check() ;
	cin>>x1;
	h1.deposit(x1);
	h1.check() ;
	cin>>x2;
	h1.withdraw(x2);
	h1.check() ;
	
	cin>>a>>b>>c>>limit;
	CCreditcard h2(a,b,c,limit);
	h2.check() ;
	cin>>x1;
	h2.deposit(x1);
	h2.check() ;
	cin>>x2;
	h2.withdraw(x2);
	h2.check() ;
}




