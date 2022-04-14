/*
按题目要求定义Student类并重载-运算符。
定义一个全局函数求出所有学生中年龄相差最大的两个人的名字以及相差天数。
主函数定义对象指针数组，输入数据，动态创建对象。最后调用全局函数求出结果。

题目描述
定义一个学生类Student，包含该学生的姓名、出生年、月、日 ，重定义 “-”
号实现两个学生之间相差多少天的比较。并利用重载的“-”运算符，
求所有学生中年龄相差最大的两个人的名字以及相差天数。

输入
第一行：输入所需要输入的学生个数；
第二行开始，依次输入每个学生的姓名、出生年、月、日。

输出
输出年龄相差最大的两个人的名字以及相差天数。

样例输入
3
Tom 1995 1 1
Joe 1995 2 28
Jimmy 1996 1 8

样例输出
Tom和Jimmy年龄相差最大，为372天。

*/

#include<iostream>
using namespace std;

class Student
{
	private:
		string name;
		int year,month,day;
	public:
		Student(){}
		void set(string a,int x1,int x2,int x3)
		{
			name=a;
			year=x1;
			month=x2;
			day=x3;
		}
		int operator - (Student &p)
		{
			int x1,x2=0,x3,xx,n,i;
			if(year!=p.getyear())
			{
				if(isLeapYear())
					x1=366-getDayofYear();
				else
					x1=365-getDayofYear();
				n=p.getyear()-year-1;
				if(n>0)
					for(i=1;i<n;i++)
					{
						if(((year+i)%4 == 0 && (year+i)%100 != 0) || (year+i)%400 == 0)
							x2+=366;
						else
							x2+=365; 
					}
				x3=p.getDayofYear();
				xx=x1+x2+x3;
			}
			else
			{
				x1=getDayofYear();
				x3=getDayofYear();
				xx=x3-x1;
			}
			return xx;
		}
		bool isLeapYear() { return (year%4 == 0 && year%100 != 0) || year%400 == 0; }
		int getDayofYear()    
    	{
     	 	int i, sum=day; 
   	 	 	int a[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
    		int b[13]={0,31,29,31,30,31,30,31,31,30,31,30,31};

     		if (isLeapYear())
       	    	for(i=0;i<month;i++)   sum +=b[i];
   		    else
    		    for(i=0;i<month;i++)   sum +=a[i];

		 	return sum;
   		}
		int getyear(){return year;}
		int getmonth(){return month;}
		int getday(){return day;}
		string getname(){return name;} 
};

void find(Student *p,int t)
{
	int i,max=0,min=0;
	int *a;
	a=new int[t];
	for(i=0;i<t;i++)
	{
		a[i]=p[i].getyear()*10000+p[i].getmonth()*100+p[i].getday();
	}
	for(i=0;i<t;i++)
	{
		if(a[min]<a[i])
			min=i;
		if(a[max]>a[i])
			max=i;
	}
	cout<<p[max].getname()<<"和"<<p[min].getname()<<"年龄相差最大，为"<<p[max]-p[min]<<"天。"<<endl;
	delete [] a;
}

int main()
{
	string name;
	int x1,x2,x3,t,i;
	cin>>t;
	Student *p;
	p = new Student[t];
	for(i=0;i<t;i++)
	{
		cin>>name>>x1>>x2>>x3;
		p[i].set(name,x1,x2,x3); 
	}
	find(p,t);
	delete [] p;
}

