/*
班级学生平均成绩计算（继承）

题目描述
定义Person类具有姓名、年龄等属性，具有输出基本信息的display函数。
选修《面向对象程序设计》课程的学生是在Person类的基础上，派生出的子类：学生类。
子类继承父类成员，新增其他成员、改写display函数。
1.       学生类具有平时成绩、考试成绩和总评成绩三个属性，
2.       计算总评成绩的函数，总评成绩=平时成绩*40%+考试成绩*60%。
3.       新的display函数
教授《面向对象程序设计》课程的老师是在Person类的基础上，派生出的子类：教师类。
子类继承父类成员，新增其他成员、改写display函数。
1.       增加选课学生数组、选课人数、班级平均分三个属性
2.       在选课学生数组中增加一个学生的函数
3.       计算班级学生平均分的函数
4.       新的display函数
定义上述类并编写主函数，首先建立一个教师类对象，
随后将n个学生类对象加入教师类对象的选课学生数组中。
计算该教师教授班级学生的平均成绩，并输出。

输入
教师类对象基本信息
选课人数n
随后每行输入学生类对象相关信息

输出
教师类对象信息
所有选课学生信息

样例输入
Cindy 18
2
Sandy 8 90 80
David 9 60 70

样例输出
Cindy 18 2 75.00
Sandy 8 84.00
David 9 66.00

按题目要求定义CPerson类和派生类CStudent。
主函数输入数据、定义对象并调用相应的成员函数实现程序的功能。
*/

#include<iostream>
#include<cstring>
#include<iomanip>
using namespace std;

class CPerson
{
	protected:
		string name;
		int age;
	public:
		CPerson(){}
		CPerson(string a,int b):name(a),age(b){}
		virtual void display()=0;
};

class CStudent:public CPerson
{
	private:
		float usualgrade;
		float examgrade;
		float allgrade;
	public:
		CStudent(){}
		CStudent(string a,int b,float c,float d):CPerson(a,b),usualgrade(c),examgrade(d){}
		float Jisuan(){ allgrade=0.4*usualgrade+0.6*examgrade; return allgrade; }
		void display(){ cout<<name<<" "<<age<<" "<<allgrade<<endl; }
};

class CTeacher:public CPerson
{
	private:
		CStudent *h[1000];
		int number;
		float average;
	public:
		CTeacher(string a,int b,CStudent *c[1000],int d):CPerson(a,b),number(d)
		{
			average=0;
			for(int i=0;i<number;i++)
				h[i]=c[i];
		}
		void JIsuan()
		{
			int i;
			float k=0;
			for(i=0;i<number;i++)
				k+= h[i]->Jisuan() ;
			average=k/number;
		}
		void display()
		{ 
			cout<<name<<" "<<age<<" "<<number<<" "<<fixed<<setprecision(2)<<setfill('0')<<average<<endl; 
			for(int i=0;i<number;i++)
				h[i]->display() ;
		}
		~CTeacher()
		{
			for(int i=0;i<number;i++)
				delete h[i];
		}
};

int main()
{
	string name,Name;
	int i,n,age,Age;
	float score1,score2;
	cin>>Name>>Age>>n;
	CStudent *p[1000];
	for(i=0;i<n;i++)
	{
		cin>>name>>age>>score1>>score2;
		p[i]=new CStudent(name,age,score1,score2);
	}
	CTeacher h(Name,Age,p,n);
	h.JIsuan() ;
	h.display() ;
	for(i=0;i<n;i++)
		delete p[i];
}

