/*
动物园（虚函数与多态）

题目描述
某个动物园内，有老虎、狗、鸭子和猪等动物，动物园的管理员为每个动物都起了一个名字，
并且每个动物都有年龄、体重等信息。每到喂食的时候，不同的动物都会叫唤(speak)。
每种动物的叫唤声均不同，老虎的叫唤声是“AOOO”，狗的叫唤声是“WangWang”，
鸭子的叫唤声是“GAGA”，猪的叫唤声是“HENGHENG”。
定义一个Animal的基类，Animal类有函数Speak()，并派生老虎(Tiger)、狗(Dog)、
鸭子(Duck)和猪(Pig)类，其能发出不同的叫唤声（用文本信息输出叫声）。
编写程序，输入动物名称、名字、年龄，让动物园内的各种动物叫唤。
要求：只使用一个基类指针，指向生成的对象并调用方法。

输入
测试案例的个数
第一种动物的名称  名字  年龄
第二种动物的名称  名字 年龄
......

输出
输出相应动物的信息
如果不存在该种动物，输出There is no 动物名称 in our Zoo.  ，具体输出参考样例输出

样例输入
4
Tiger Jumpjump 10
Pig Piglet 4
Rabbit labi 3
Duck tanglaoya 8

样例输出
Hello,I am Jumpjump,AOOO.
Hello,I am Piglet,HENGHENG.
There is no Rabbit in our Zoo.
Hello,I am tanglaoya,GAGA.

按题目要求完成基类Animal和派生类Tiger、Dog、Duck、Pig的定义。
主函数输入数据、用基类指针指向动态创建的对象并调用speak成员函数。
*/

#include<iostream>
#include<cstring>
using namespace std;

class Animal
{
	public:
		Animal(string a,int b):name(a),age(b){}
		virtual void Speak()=0;
	protected:
		string name;
		int age;
};

class Tiger:public Animal
{
	public:
		Tiger(string a,int b):Animal(a,b){}
		void Speak(){ cout<<"Hello,I am "<<name<<",AOOO."<<endl; }
};

class Dog:public Animal
{
	public:
		Dog(string a,int b):Animal(a,b){}
		void Speak(){ cout<<"Hello,I am "<<name<<",WangWang."<<endl; }
};

class Duck:public Animal
{
	public:
		Duck(string a,int b):Animal(a,b){}
		void Speak(){ cout<<"Hello,I am "<<name<<",GAGA."<<endl; }
};

class Pig:public Animal
{
	public:
		Pig(string a,int b):Animal(a,b){}
		void Speak(){ cout<<"Hello,I am "<<name<<",HENGHENG."<<endl; }
};

void show(Animal *r)
{
	r->Speak();
}

int main()
{
	int t;
	cin>>t;
	char a[20];
	string b;
	int c;
	Animal *p;
	while(t--)
	{
		cin>>a>>b>>c;
		
		if(!strcmp(a,"Tiger"))
			{ p =new Tiger(b,c); }
		else if(!strcmp(a,"Dog"))
			{ p =new Dog(b,c); }
		else if(!strcmp(a,"Duck"))
			{ p =new Duck(b,c); }
		else if(!strcmp(a,"Pig"))
			{ p =new Pig(b,c); }
		else
			{ cout<<"There is no "<<a<<" in our Zoo."<<endl; continue; }
		show(p);
		delete p;
	}
	
}

