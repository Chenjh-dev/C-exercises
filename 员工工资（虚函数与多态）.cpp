/*
Ա�����ʣ��麯�����̬��

��Ŀ����
ĳ��˾Ա���������У�������ְλ�����𡢹������ޣ���������޶��ǷǸ�������
������ʾ���󡣰��������У����캯�������㹤�ʵķ�����salary()����
Ա��ְλ��Ϊ���֣�Employee��Teamleader��Manager������ְλ������ʾ����
����ְλԱ�����������ڼ��㹤�ʵķ�����ͬ��
1. Employee��ÿ�¹��� = 1000 + 500*���� + 50*��������
2. Teamleader��ÿ�¹��� = 3000 + 800*���� + 100*��������
3. Manager��ÿ�¹��� = 5000 + 1000 * (����+��������)
���㹤�ʵķ�������ÿ��Ա���Ĺ�������
Ҫ������ͨԱ��Ϊ���࣬�鳤�;���̳л��࣬������ֻ��ʹ�û���ָ��ָ���������ö���ķ�����

����
���԰����ĸ��� t
ÿ������һ��Ա������Ϣ������������ְλ�����𡢹�������

���
�����ӦԱ������Ϣ
���д�����Ϣ�������������Ϣ����ְλ��Ϣ�뼶���������Ϣͬʱ���������ְλ������Ϣ

��������
5
zhangsan Employee 4 5
lisi Teamleader 4 5
Wangwu Manager 4 5
chenliu Precident 4 5
xiaoxiao Manager -1 5

�������
zhangsan:Employee,Salary:3250
lisi:Teamleader,Salary:6700
Wangwu:Manager,Salary:14000
error position.
error grade or year.

������ĿҪ����ɻ���Employee��������Teamleader��Manager�Ķ��塣
�������������ݡ��û���ָ��ָ��̬�����Ķ��󲢵���salary��Ա������
*/

#include<iostream>
#include<string.h>
using namespace std;

class Employee
{
	protected:
		string name;
		string position;
		int grade;
		int year;
	public:
		Employee(string a,string b,int c,int d):name(a),position(b),grade(c),year(d)
		{
			cout<<name<<":"<<position<<",Salary:";
		}
		virtual int Jisuang(){ return 1000+500*grade+50*year; }
};

class Teamleader:public Employee
{
	public:
		Teamleader(string a,string b,int c,int d):Employee(a,b,c,d){}
		int Jisuang(){ return 3000+800*grade+100*year; }
};

class Manager:public Employee
{
	public:
		Manager(string a,string b,int c,int d):Employee(a,b,c,d){}
		int Jisuang(){ return 5000+1000*(grade+year); }
};

void show(Employee *r)
{
	cout<< r->Jisuang() <<endl;
}

int main()
{
	int t;
	string a,b;
	int c,d;
	Employee *p;
	cin>>t;
	while(t--)
	{
		cin>>a>>b>>c>>d;
		if(c<0 || d<0)
		{	cout<<"error grade or year."<<endl;continue;}
		if(b == "Employee")
			p = new Employee(a,b,c,d);
		else if(b == "Teamleader")
			p = new Teamleader(a,b,c,d);
		else if(b == "Manager")
			p = new Manager(a,b,c,d);
		else 
		{	cout<<"error position."<<endl; continue; }  
		show(p) ;
		delete p;
	}
}
