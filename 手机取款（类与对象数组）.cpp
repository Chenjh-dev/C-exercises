//手机取款（类与对象数组）

//题目描述
//采用面向对象思想实现手机取款的过程
//假设银行账户有卡号、绑定手机号、动态密码、余额等属性，
//包含获取各种属性、校验动态密码、取款操作。属性全是整数数据。
//使用对象数组来保存n个银行账户。
//用户通过手机取款的步骤如下：(一般在主函数实现)
//1、用户输入手机号，在n个银行账户中找到相应的银行账户。
//	如果查找成功则往下执行，否则输出信息“手机号不存在”，不再往下执行；
//2、用户输入动态密码，然后校验动态密码的是否正确
//	如果密码正确则往下执行，否则输出信息“密码错误”，不再往下执行；
//3、用户输入取款金额，然后执行取款操作
//	如果余额不足就拒绝取款并给出信息“卡号XXX--余额不足”；
//	如果取款成功给出信息“卡号XXX--余额YYY”，其中XXX表示卡号，YYY表示余额
//上述描述只是方便说明，可以一次输入所有数据再执行各个操作。

//输入
//第一行输入n，表示有n个账户
//下一行输入第一个账户的信息：卡号、绑定手机号、动态密码、余额
//连续输入n行
//接着输入k，表示要执行k次取款操作
//下一行输入手机号、动态密码、取款金额
//连续输入k行

//输出
//输出k行，每行输出操作结果


//样例输入
//5
//1001 138111 111 1000
//1002 135222 222 200
//1003 136333 333 300
//1004 133444 444 400
//1005 132555 555 500
//4
//136333 333 600
//133444 444 300
//133555 555 200
//138111 222 900

//样例输出
//卡号1003--余额不足
//卡号1004--余额100
//手机号不存在
//密码错误

//按题目要求完成银行帐户类的定义(不能在成员函数里用cin输入)。
//主函数实现数据的输入、对象数组的定义和初始化、然后用对象数组元素
//调用相应成员函数按指定步骤完成取款操作并输出相关信息。

#include<iostream>
using namespace std;

class Account
{
	public:
		Account(){}
		Account(int x1,int x2,int x3,int x4)
		{
			Cardnumber = x1;
			Phonenumber = x2;
			Password = x3;
			Balance = x4;
		}
		int seek(int a,int b,Account r[20])
		{
			int i,n=1;
			for(i=0 ;i<b ;i++ )
			{
				if(a == r[i].Phonenumber)
				{
					a = i;
					n = 0;
					break;
				}
			}
			if(n == 1)
				cout << "手机号不存在" << endl;
			return a;
		} 
		int enterpassword(int a,int c,Account r[20])
		{
			if(c != r[a].Password)
				cout << "密码错误" << endl;
			else 
				c = 0;
			return c;
		}
		int qu(int a,int d,Account r[20])
		{
			int n;
			if(d <= r[a].Balance)
			{
				n = r[a].Balance - d ;
				cout << "卡号" << r[a].Cardnumber << "--余额" << n << endl;
			}
			else
				cout << "卡号" << r[a].Cardnumber << "--余额不足" <<endl;
		}
	private:
		int Cardnumber;
		int Phonenumber;
		int Password;
		int Balance;
};

int main()
{
	int n,i;
	int y1,y2,y3,y4;
	cin >> n;
	Account s[n];
	Account p;
	for(i=0;i<n;i++)
	{
		cin>>y1>>y2>>y3>>y4;
		s[i] = Account(y1,y2,y3,y4);
	}
	int k,m;
	cin >> k;
	while(k--)
	{
		cin>>y1>>y2>>y3;
		m = y1;
		y1=p.seek(y1,n,s) ;
		if(y1 != m)
		{
			y2=p.enterpassword(y1,y2,s);
			if (y2 == 0)
			{
				p.qu(y1,y3,s); 
			}
		}	
	}
}
