/*
宠物的生长（虚函数和多态）

题目描述
需要开发一个系统，对宠物的生长状态进行管理。给出下面的基类框架：
class Pet
{ protected:
　　string name;//姓名
int length;//身长
int weight;//体重
CDate current;//开始记录时间
（日期类CDate包含年、月、日三个私有数据，其他方法根据需要自拟。）
public:
virtual void display(CDate day)=0;//输出目标日期时宠物的身长和体重
}
以Pet为基类，构建出Cat和Dog两个类:
Cat一天身长加0.1，体重加0.2。
Dog一天身长加0.2，体重加0.1。
生成上述类并编写主函数，要求主函数中有一个基类指针Pet *pt，用于测试子类数据。
主函数根据输入的信息，相应建立Cat类对象或Dog类对象，并给出测量日期时宠物的身长和体重。

输入
第一行为测试次数
第二行是开始记录日期
从第三行起，每个测试用例占一行，每行给出宠物的基本信息：
宠物的类型（1为Cat，2为Dog）、名字、身长、体重、最后测量的日期。

输出
要求输出目标日期宠物姓名、身长和体重（结果要求保留小数点后2位）。若测量日期小于开始日期，输出”error”。

样例输入
3
2019 5 5
1 tony 10 10 2018 12 30
2 jerry 5 6 2019 5 10
1 tom 3 4 2019 6 1

样例输出
error
jerry after 5 day: length=6.00,weight=6.50
tom after 27 day: length=5.70,weight=9.40

按题目要求完成基类Pet和派生类Cat、Dog的定义。主函数输入数据、
用基类指针指向动态创建的对象并调用相关成员函数。
*/

#include<iostream>
#include<cstring>
#include<iomanip>
using namespace std;

class CDate
{
	private:
		int year,month,day;
	public:
		CDate(){}
		CDate(int y,int m,int d)
		{
			year=y;
			month=m;
			day=d;
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
		int judge(CDate &r)
		{
			if(r.year>year || (r.year==year && (r.month>month || (r.month==month && r.day>=day)))) 
				return 1;
			else 
				return 0;
		}
};

class Pet
{ 
	protected:
		string name;
		float length;
		float weight;
		CDate current;//开始记录时间
	public:
		Pet(string a,float l,float w,CDate b)
		{
			name=a;
			length=l;
			weight=w;
			current=b;
		}
		virtual void display(CDate day)=0;//输出目标日期时宠物的身长和体重
};

class Cat:public Pet
{
	private:
		int sumday;
	public:
		Cat(string a,float l,float w,CDate b):Pet(a,l,w,b)
		{
			sumday=0;
		}
		void display(CDate day)
		{
			sumday=day.getDayofYear() -current.getDayofYear();
			length+=0.1*sumday;
			weight+=0.2*sumday;
			cout<<name<<" after "<<sumday<<" day: length="<<fixed<<setprecision(2)<<setfill('0')<<length<<",weight="<<fixed<<setprecision(2)<<setfill('0')<<weight<<endl;
		}
};

class Dog:public Pet
{
	private:
		int sumday;
	public:
		Dog(string a,float l,float w,CDate b):Pet(a,l,w,b)
		{
			sumday=0;
		}
		void display(CDate day)
		{
			sumday=day.getDayofYear() -current.getDayofYear();
			length+=0.2*sumday;
			weight+=0.1*sumday;
			cout<<name<<" after "<<sumday<<" day: length="<<fixed<<setprecision(2)<<setfill('0')<<length<<",weight="<<fixed<<setprecision(2)<<setfill('0')<<weight<<endl;
		}
};

int main()
{
	int t;
	cin>>t;
	int y,m,d,judge;
	string name;
	float length,weight;
	cin>>y>>m>>d;
	CDate h1(y,m,d);
	Pet *pt;
	while(t--)
	{
		cin>>judge>>name>>length>>weight>>y>>m>>d;
		CDate h2(y,m,d);
		if(h1.judge(h2)==0 )
		{ cout<<"error"<<endl;continue; }
		if(judge==1)
		{
			pt=new Cat(name,length,weight,h1);
			pt->display(h2); 
		}
		else if(judge==2)
		{
			pt=new Dog(name,length,weight,h1);
			pt->display(h2);
		}
		else
			cout<<"error"<<endl;
		delete pt;	
	}
}
