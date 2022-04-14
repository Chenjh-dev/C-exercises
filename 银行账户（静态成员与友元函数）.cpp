/*

银行账户（静态成员与友元函数）

题目描述
银行账户类的基本描述如下：
要求如下：
实现该银行账户类
为账户类Account增加一个友元函数，实现账户结息，要求输出结息后的余额
（结息余额=账户余额+账户余额*利率）。友元函数声明形式为 friend void Update(Account& a);
在main函数中，定义一个Account类型的指针数组，让每个指针指向动态分配的Account对象，
并调用成员函数测试存款、取款、显示等函数，再调用友元函数测试进行结息。 
大家可以根据实际需求在类内添加其他方法，也可以修改成员函数的参数设置

输入
第1行：利率
第2行：账户数目n
第3行开始，每行依次输入一个账户的“账号”、“姓名”、“余额”、存款数，取款数。

输出
第1行开始，每行输出一个账户的相关信息，包括账号、姓名、存款后的余额、
存款后结息余额、取款后余额。
最后一行输出所有账户的余额。

样例输入
0.01
3
201501 张三 10000 1000 2000
201502 李四 20000 2000 4000
201503 王二 80000 4000 6000

样例输出
201501 张三 11000 11110 9110
201502 李四 22000 22220 18220
201503 王二 84000 84840 78840
106170

按题目要求完成Account类和update全局函数的定义。主函数定义Account类对象指针数组、
输入数据、设置利率、动态创建对象并调用相关的函数、最后析构动态创建的对象。
*/

#include<iostream>
#include<string.h>
using namespace std;

class Account
{
	public:
		Account(){}
		Account(string accno,string name,float balance);
		~Account(){}
		static void Set(float a ,int b);
		void Deposit(float amount);  //存款 
		void changebalance(float a){_balance = a;}
		void withdraw(float  amonut);//取款 
		float GetBalance(){return _balance; }          // 获取账户余额 
		void Show();                 //显示账户所有基本信息 
		static int GetCount(){return  Account::count;}       //获取账户数 
		static float GetInterestRate(){return Account::InteresRate;}//获取利率 
		friend void Update(Account& a);  //友元函数 
	private:
		static int count;             //银行账户数量 
		static float InteresRate;     //利率 
		string _accno,_accname;       //账户与户名 
		float _balance;               //账户余额 
};

int Account::count = 0;
float Account::InteresRate = 0;

Account::Account(string accno,string name,float balance)
{

	_accno = accno ;
	_accname = name ;
	_balance = balance ;
}

void Account::Set(float a ,int b)
{
	Account::InteresRate = a;
	Account::count = b;
} 

void Account::Deposit(float amonut)
{
	_balance += amonut;
} 

void Account::withdraw(float amonut)
{
	_balance = _balance - amonut ;
} 

void Account::Show ()
{
	cout<<_accno<<" "<<_accname<<" "<<_balance<<" ";
}

void Update(Account *a)
{
	float k;
	k = a->GetBalance() + a->GetBalance() * a->GetInterestRate() ; 
	a->changebalance(k); 
	cout<<a->GetBalance()<<" ";
}

int main()
{
	float lilv;
	int n,i;
	string x1,x2;
	float x3,x4,x5,zz;
	cin>>lilv>>n;
	Account* a[20];
	Account::Set(lilv,n);
	for(i=0;i<n;i++)
	{
		cin>>x1>>x2>>x3>>x4>>x5;
		a[i] = new Account(x1,x2,x3);
		a[i]->Deposit(x4);
		a[i]->Show();
		Update(a[i]);
		a[i]->withdraw(x5);
		cout<<a[i]->GetBalance()<<endl;
		zz = zz + a[i]->GetBalance() ;
	} 
	cout<<zz;
	for(i=0;i<n;i++)
		delete a[i];
}






























