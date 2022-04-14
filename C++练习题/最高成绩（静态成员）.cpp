/*
最高成绩（静态成员）

题目描述
学生类定义如下：
class Student {
private:
	int id;	//学号
	int score; //成绩
	static int  maxscore;	//最高分数
	static int maxid;		//最高分数学生学号
public:
	Student(int ti=0,int ts=0):id(ti), score(ts){}
	static void findMax(Student & st); //寻找最高成绩和学号
	static int getMaxScore(); //返回最高成绩
	static int getMaxID();		//返回最高成绩的学号
};
输入一组学生学号和成绩，用上述静态成员求最高成绩和对应学号

输入
第一行输入n表示有n个学生
接着输入n行，每行包括两个数据，表示学号和成绩

输出 
调用静态成员函数输出学号和最高成绩，格式看样例

样例输入
3
1002 68
1023 54
1045 32

样例输出
1002--68
*/ 

//按题目要求完成Student类的定义。主函数定义Student类对象指针数组、输入数据、
//动态创建对象并调用findMax、最后调用getMaxID和getMaxScore函数输出相关信息并析构动态创建的对象。

#include<iostream>
using namespace std;

class Student 
{
	private:
		int id;	//学号
		int score; //成绩
		static int  maxscore;	//最高分数
		static int maxid;		//最高分数学生学号
	public:
		Student(int ti=0,int ts=0):id(ti), score(ts){}
		void Get(int a,int b){id = a;score = b;}
		static void findMax(Student st[],int n); //寻找最高成绩和学号
		static int getMaxScore(){return Student::maxscore ;} //返回最高成绩
		static int getMaxID(){return Student::maxid ; }		//返回最高成绩的学号
};

int Student::maxscore = 0;
int Student::maxid = 0;

void Student::findMax(Student st[],int n)
{
	for(int i=0;i<n;i++)
	{
		if(st[i].score > Student::maxscore )
		{
			Student::maxscore = st[i].score ;
			Student::maxid  = st[i].id ;
		}
	}
}

int main()
{
	int n;
	cin>>n;
	Student *a;
	Student b;
	a = new Student[n];
	int x1,x2;
	for(int i=0;i<n;i++)
	{
		cin>>x1>>x2 ;
		a[i].Get(x1,x2);
	}
	Student::findMax(a,n);
	cout<<Student::getMaxID()  <<"--"<<Student::getMaxScore() <<endl;
	delete [] a; 
}
