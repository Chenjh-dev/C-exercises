/*
在职研究生（多重继承）

题目描述
1、建立如下的类继承结构：
1)        定义一个人员类CPeople，其属性（保护类型）有：姓名、性别、年龄；
2)        从CPeople类派生出学生类CStudent，添加属性：学号和入学成绩；
3)        从CPeople类再派生出教师类CTeacher，添加属性：职务、部门；
4)        从CStudent和CTeacher类共同派生出在职研究生类CGradOnWork，
			添加属性：研究方向、导师；
2、分别定义以上类的构造函数、输出函数print及其他函数（如需要）。
3、在主函数中定义各种类的对象，并测试之。

输入
第一行：姓名性别年龄
第二行：学号成绩
第三行：职务部门
第四行：研究方向导师

输出
第一行：People:
第二行及以后各行：格式见Sample

样例输入
wang-li m 23
2012100365 92.5
assistant computer
robot zhao-jun

样例输出
People:
Name: wang-li
Sex: m
Age: 23

Student:
Name: wang-li
Sex: m
Age: 23
No.: 2012100365
Score: 92.5

Teacher:
Name: wang-li
Sex: m
Age: 23
Position: assistant
Department: computer

GradOnWork:
Name: wang-li
Sex: m
Age: 23
No.: 2012100365
Score: 92.5
Position: assistant
Department: computer
Direction: robot
Tutor: zhao-jun

按题目要求定义公共基类CPeople、派生类CStudent、CTeacher
和多重重复继承派生类CGradOnWork，
包括构造函数和print等成员函数。主函数输入数据、
定义各个类的类对象并调用相应的print成员函数。
*/

#include<iostream>
#include<string.h>
using namespace std;

class CPeople
{
	protected:
		string name;
		char sex;
		int age;
	public:
		CPeople(){}
		CPeople(string a,char b,int c)
		{
			name = a;
			sex = b;
			age = c;
		}
		void print()
		{
			
			cout<<"Name: "<<name<<endl;
			cout<<"Sex: "<<sex<<endl;
			cout<<"Age: "<<age<<endl;
		}
};

class CStudent:virtual public CPeople
{
	protected:
		int xuehao;
		float score;
	public:
		CStudent(string a,char b,int c,int d,float e):CPeople(a,b,c)
		{
			xuehao = d;
			score = e;
		}
		void print()
		{
			CPeople::print() ;
			cout<<"No.: "<<xuehao<<endl;
			cout<<"Score: "<<score<<endl;
		}		
};

class CTeacher:virtual public CPeople
{
	protected:
		string position;
		string department;
	public:
		CTeacher(string a,char b,int c,string d,string e):CPeople(a,b,c)
		{
			position = d;
			department = e;
		}
		void print()
		{
			CPeople::print() ;
			cout<<"Position: "<<position<<endl;
			cout<<"Department: "<<department<<endl;
		}		
};

class CGradOnWork:public CStudent,public CTeacher
{
	protected:
		string direction;
		string tutor;
	public:
		CGradOnWork(string a,char b,int c,int d,float e,string f,string g,string h,string i):CStudent(a,b,c,d,e),CTeacher(a,b,c,f,g),CPeople(a,b,c)
		{
			direction = h;
			tutor = i;
		}
		void print()
		{
			CStudent::print() ;
			cout<<"Position: "<<position<<endl;
			cout<<"Department: "<<department<<endl;
			cout<<"Direction: "<<direction<<endl;
			cout<<"Tutor: "<<tutor<<endl;
		}
};

int main()
{
	string a,f,g,h,i;
	float e;
	char b;
	int c,d;
	cin>>a>>b>>c>>d>>e>>f>>g>>h>>i;
	CPeople h1(a,b,c);
	cout<<"People: "<<endl;
	h1.print() ;
	cout<<endl;
	CStudent h2(a,b,c,d,e);
	cout<<"Student: "<<endl;
	h2.print() ;
	cout<<endl;
	CTeacher h3(a,b,c,f,g);
	cout<<"Teacher: "<<endl;
	h3.print() ;
	cout<<endl;
	CGradOnWork h4(a,b,c,d,e,f,g,h,i);
	cout<<"GradOnWork: "<<endl;
	h4.print() ;
}


