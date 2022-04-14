//问题 : 教师与学生（类和对象）

//题目描述

//校园里的主体是学生，学生包含很多属性，比如姓名、学号、所在学院、专业、性别、住址、联系电话。。。。。。等等，
//有这些属性，需要操纵它们的动作，比如读取姓名、设置姓名、读取学号、设置学号。。。。。。等等，根据以上的信息，
//请给出一个完整的学生类定义
//校园里还包含各不同院系的老师，请思考教师这个类Teacher该包含哪些属性和方法（与学生相比，教师属性就要添加职称、
//职务、学历等信息，但不需要学号、专业等信息）给出一个完整的教师类定义：
//教师的日常工作包括布置作业（homework）、批改作业(review)。其中布置作业需要指定是哪门课程的作业，需要知道课程名称，然后返回课程编号；
//批改作业需要接收学生的作业答案，并根据答案返回分数，如果答案大于60则返回分数88，否则返回分数44。
//学生的日常学习包括做作业（dohomework），作业内容是根据课程编号返回作业答案，以课程编号的平方值做为作业答案。
//在前面师生两个类中增加相应的操作方法，并根据输入输出要求使用上述的方法。
//要求：必须使用师生两个类的方法来实现布置作业、批改作业、做作业的过程，凡是发现用其他方法一律无效！

//输入
//第一行输入t表示有t门课程
//接着输入t行，每行包含两个参数，第一个参数是课程编号（正整数），第二个参数课程名称（字符串）
//接着一行输入n，n小于t，表示老师布置作业的数量
//接着输入n行，每行输入一个作业对应的课程名称，每输入一行就依次调用三个方法来表示三个操作：老师布置作业，学生做作业，老师批改作业

//输出
//每行输出一个作业的成绩


//样例输入
//5
//4 math
//8 chinese
//6 english
//7 biology
//9 history
//3
//history
//math
//english

//样例输出
//88
//44
//44



//定义一个结构类型含课程编号和课程名称两个成员,定义学生类含dohomework成员函数(根据课程编号返回作业答案),
//定义教师类含homework（根据课程名称查课程表返回课程编号)和review(根据作业答案返回成绩)两个成员函数。
//主函数定义结构数组并将课程表数据输入之、然后分别定义学生类和教师类对象并用对象依次调
//用相应的homework, dohomework和review成员函数。


#include<iostream>
#include<string.h>
using namespace std;

struct Course
{
	int coursenumber;
	char coursename[10];
};

class Student
{
	public:
		int dohomework(int k)
		{
			return k*k;
		}
	private:
};

class Teacher
{
	public:
		int homework(char p[10],Course a[10])
		{
			int i=0;
			if(strcmp(a[i].coursename ,p) == 0)
				return a[i].coursenumber ;
			else i++;
		}
		int review(int x)
		{
			if(x>60)
				return 88;
			else 
				return 44;
		}
	private:
};


int main()
{
	int t;
	Course a[10];
	Student ST;
	Teacher TE;
	cin>>t;
	while(t--)
	{
		int i=0;
		cin>>a[i].coursenumber >>a[i].coursename ;
		i++;
	}
	int n;
	cin>>n;
	while(n--)
	{
		int ww;
		char p[10];
		cin>>p;
		ww =TE.homework(p,a);
		ww =ST.dohomework(ww);
		ww =TE.review(ww) ;  
		cout<<ww<<endl;
	}
	return 0;
}
