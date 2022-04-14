/*
计算学生成绩等级（虚函数和多态）

题目描述
请设计3个类，分别是学生类Student，本科生类Undergraduate，
研究生类Postgraduate，其中Student类是基类，它包含基本的学生信息，
如姓名、类别（本科生还是研究生）、所学课程（这里假定为3门课，用数组表示）
成绩和成绩等级等；Undergraduate类和Postgraduate都是Student类的派生类，
它们之间的主要差别是计算3门课程平均成绩等级的方法有所不同，
研究生的标准要比本科生的标准高一些，如下表所示：
本科生标准                研究生标准
80~100  优秀              90~100  优秀
70~80   良好              80~90   良好
60~70   一般              70~80   一般
50~60   及格              60~70   及格
50以下  不及格            60以下  不及格

学生Student基类框架如下所示：
class Student
{
	protected:
 		string name; //学生姓名
  		int type; //学生类别:1表示本科生，2表示研究生
  		int courses[3]; //3门课的成绩
  		string courseGrade; //成绩等级
	public:
 		Student(string n,string t,int a1,int a2,int a3);//构造方法
 		virtual void calculateGrade()=0;//计算成绩等级
 		void print();//输出信息
};

以Student为基类，构建出Undergraduate、Postgraduate两个类。
生成上述类并编写主函数，要求主函数中有一个基类指针，生成基类动态数组，来接收子类对象。

输入
第一行表示测试次数。从第二行开始，每个测试用例占一行，
每行数据意义如下：学生姓名、学生类别（1为本科生，2为研究生）、3门课的成绩。

输出
学生姓名、类别、成绩等级

样例输入
5
张三 1 90 95 100
李四 1 80 85 90
王五 2 82 85 88
赵六 1 75 82 87
陈七 2 80 82 84

样例输出
张三,本科生,优秀
李四,本科生,优秀
王五,研究生,良好
赵六,本科生,优秀
陈七,研究生,良好

按题目要求完成基类Student和派生类Undergraduate、Postgraduate的定义。
主函数定义基类对象指针数组、输入数据并用不同的基类指针指向动态创建的对象
并调用calculateGrade成员函数。

*/

#include<iostream>
#include<cstring>
using namespace std;

class Student
{
	protected:
   		string name; //学生姓名
   		int type; //学生类别:1表示本科生，2表示研究生
   		int courses[3]; //3门课的成绩
  		string courseGrade; //成绩等级
	public:
 		Student(string n,int t,int a1,int a2,int a3)
 		{
 			name=n;
 			type=t;
 			courses[0]=a1;
 			courses[1]=a2;
 			courses[2]=a3;
		}
  		virtual void calculateGrade()=0;//计算成绩等级
   		void print()
		    { 
			   	cout<<name<<",";
		   		if(type==1)
		   			cout<<"本科生";
		   		else if(type==2)
		   			cout<<"研究生";
		   		cout<<","<<courseGrade<<endl;
			}
};

class Undergraduate:public Student
{
	public:
		Undergraduate(string n,int t,int a1,int a2,int a3):Student(n,t,a1,a2,a3){}
		void calculateGrade()
		{
			int score;
			score=( courses[0]+courses[1]+courses[2] )/3;
			if(score>=80)
				courseGrade="优秀";
			else if(score>=70)
				courseGrade="良好";
			else if(score>=60)
				courseGrade="一般";
			else if(score>=50)
				courseGrade="及格";
			else 
				courseGrade="不及格"; 
		}
};

class Postgraduate:public Student
{
	public:
		Postgraduate(string n,int t,int a1,int a2,int a3):Student(n,t,a1,a2,a3){}
		void calculateGrade()
		{
			int score;
			score=( courses[0]+courses[1]+courses[2] )/3;
			if(score>=90)
				courseGrade="优秀";
			else if(score>=80)
				courseGrade="良好";
			else if(score>=70)
				courseGrade="一般";
			else if(score>=60)
				courseGrade="及格";
			else 
				courseGrade="不及格"; 
		}
};

int main()
{
	int t;
	cin>>t;
	string n;
	int type;
	int a1,a2,a3;
	Student *p;
	while(t--)
	{
		cin>>n>>type>>a1>>a2>>a3;
		if(type==1)
			p=new Undergraduate(n,type,a1,a2,a3);
		else if(type==2)
			p=new Postgraduate(n,type,a1,a2,a3);
		else
			cout<<"error";
		p->calculateGrade();
		p->print();
		delete p;
	}
}

