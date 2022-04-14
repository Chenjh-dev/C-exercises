/*
汽车收费（虚函数和多态）

题目描述
现在要开发一个系统，实现对多种汽车的收费工作。 汽车基类框架如下所示：
class Vehicle
{ protected:
string no;//编号
public:
virtual void display()=0;//应收费用
}
以Vehicle为基类，构建出Car、Truck和Bus三个类。
Car的收费公式为： 载客数*8+重量*2
Truck的收费公式为：重量*5
Bus的收费公式为： 载客数*3
生成上述类并编写主函数，要求主函数中有一个基类指针Vehicle *pv;用来做测试用。
主函数根据输入的信息，相应建立Car,Truck或Bus类对象，对于Car给出载客数和重量，
Truck给出重量，Bus给出载客数。假设载客数和重量均为整数。

输入
第一行表示测试次数。从第二行开始，每个测试用例占一行，每行数据意义如下：
汽车类型（1为car，2为Truck，3为Bus）、编号、基本信息
（Car是载客数和重量，Truck给出重量，Bus给出载客数）。

输出 
车的编号、应缴费用

样例输入
4
1 002 20 5
3 009 30
2 003 50
1 010 17 6

样例输出
002 170
009 90
003 250
010 148

按题目要求完成抽象基类Vehicle和派生类Car、Truck、Bus的定义。
主函数输入数据、用基类指针指向不同的动态创建的派生类对象并调用计算收费的成员函数。

*/

#include<iostream>
#include<cstring>
using namespace std;

class Vehicle
{ 
	protected:
		string no;
	public:
		Vehicle(string a):no(a){}
		virtual void display()=0;
};

class Car:public Vehicle
{
	private:
		int number;
		int weight;
	public:
		Car(string a,int b,int c):Vehicle(a)
		{
			number = b;
			weight = c;
		}
		void display(){ int a=number*8+weight*2; cout<<no<<" "<<a<<endl; }
};

class Truck:public Vehicle
{
	private:
		int weight;
	public:
		Truck(string a,int b):Vehicle(a)
		{
			weight = b;
		}
		void display(){ int a=weight*5; cout<<no<<" "<<a<<endl; }
};

class Bus:public Vehicle
{
	private:
		int number;
	public:
		Bus(string a,int b):Vehicle(a)
		{
			number = b;
		}
		void display(){ int a=number*3; cout<<no<<" "<<a<<endl; }
};

void show(Vehicle *r)
{
	r->display() ;
}

int main()
{
	int t,judge,n,w;
	string no;
	Vehicle *h;
	cin>>t;
	while(t--)
	{
		cin>>judge;
		switch(judge)
		{
			case 1:
			{
				cin>>no>>n>>w;
				h=new Car(no,n,w);
				show(h);
				break;
			}
			case 2:
			{
				cin>>no>>w;
				h=new Truck(no,w);
				show(h);
				break;
			}
			case 3:
			{
				cin>>no>>n;
				h=new Bus(no,n);
				show(h);
				break;
			}
			default:cout<<"error"<<endl;break;
		}
		delete h;		
	}
}















