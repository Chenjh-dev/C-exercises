/*
��ְ�о��������ؼ̳У�

��Ŀ����
1���������µ���̳нṹ��
1)        ����һ����Ա��CPeople�������ԣ��������ͣ��У��������Ա����䣻
2)        ��CPeople��������ѧ����CStudent��������ԣ�ѧ�ź���ѧ�ɼ���
3)        ��CPeople������������ʦ��CTeacher��������ԣ�ְ�񡢲��ţ�
4)        ��CStudent��CTeacher�๲ͬ��������ְ�о�����CGradOnWork��
			������ԣ��о����򡢵�ʦ��
2���ֱ���������Ĺ��캯�����������print����������������Ҫ����
3�����������ж��������Ķ��󣬲�����֮��

����
��һ�У������Ա�����
�ڶ��У�ѧ�ųɼ�
�����У�ְ����
�����У��о�����ʦ

���
��һ�У�People:
�ڶ��м��Ժ���У���ʽ��Sample

��������
wang-li m 23
2012100365 92.5
assistant computer
robot zhao-jun

�������
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

����ĿҪ���幫������CPeople��������CStudent��CTeacher
�Ͷ����ظ��̳�������CGradOnWork��
�������캯����print�ȳ�Ա�������������������ݡ�
��������������󲢵�����Ӧ��print��Ա������
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


