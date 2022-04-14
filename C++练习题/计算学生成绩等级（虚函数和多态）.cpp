/*
����ѧ���ɼ��ȼ����麯���Ͷ�̬��

��Ŀ����
�����3���࣬�ֱ���ѧ����Student����������Undergraduate��
�о�����Postgraduate������Student���ǻ��࣬������������ѧ����Ϣ��
����������𣨱����������о���������ѧ�γ̣�����ٶ�Ϊ3�ſΣ��������ʾ��
�ɼ��ͳɼ��ȼ��ȣ�Undergraduate���Postgraduate����Student��������࣬
����֮�����Ҫ����Ǽ���3�ſγ�ƽ���ɼ��ȼ��ķ���������ͬ��
�о����ı�׼Ҫ�ȱ������ı�׼��һЩ�����±���ʾ��
��������׼                �о�����׼
80~100  ����              90~100  ����
70~80   ����              80~90   ����
60~70   һ��              70~80   һ��
50~60   ����              60~70   ����
50����  ������            60����  ������

ѧ��Student������������ʾ��
class Student
{
	protected:
 		string name; //ѧ������
  		int type; //ѧ�����:1��ʾ��������2��ʾ�о���
  		int courses[3]; //3�ſεĳɼ�
  		string courseGrade; //�ɼ��ȼ�
	public:
 		Student(string n,string t,int a1,int a2,int a3);//���췽��
 		virtual void calculateGrade()=0;//����ɼ��ȼ�
 		void print();//�����Ϣ
};

��StudentΪ���࣬������Undergraduate��Postgraduate�����ࡣ
���������ಢ��д��������Ҫ������������һ������ָ�룬���ɻ��ද̬���飬�������������

����
��һ�б�ʾ���Դ������ӵڶ��п�ʼ��ÿ����������ռһ�У�
ÿ�������������£�ѧ��������ѧ�����1Ϊ��������2Ϊ�о�������3�ſεĳɼ���

���
ѧ����������𡢳ɼ��ȼ�

��������
5
���� 1 90 95 100
���� 1 80 85 90
���� 2 82 85 88
���� 1 75 82 87
���� 2 80 82 84

�������
����,������,����
����,������,����
����,�о���,����
����,������,����
����,�о���,����

����ĿҪ����ɻ���Student��������Undergraduate��Postgraduate�Ķ��塣
����������������ָ�����顢�������ݲ��ò�ͬ�Ļ���ָ��ָ��̬�����Ķ���
������calculateGrade��Ա������

*/

#include<iostream>
#include<cstring>
using namespace std;

class Student
{
	protected:
   		string name; //ѧ������
   		int type; //ѧ�����:1��ʾ��������2��ʾ�о���
   		int courses[3]; //3�ſεĳɼ�
  		string courseGrade; //�ɼ��ȼ�
	public:
 		Student(string n,int t,int a1,int a2,int a3)
 		{
 			name=n;
 			type=t;
 			courses[0]=a1;
 			courses[1]=a2;
 			courses[2]=a3;
		}
  		virtual void calculateGrade()=0;//����ɼ��ȼ�
   		void print()
		    { 
			   	cout<<name<<",";
		   		if(type==1)
		   			cout<<"������";
		   		else if(type==2)
		   			cout<<"�о���";
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
				courseGrade="����";
			else if(score>=70)
				courseGrade="����";
			else if(score>=60)
				courseGrade="һ��";
			else if(score>=50)
				courseGrade="����";
			else 
				courseGrade="������"; 
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
				courseGrade="����";
			else if(score>=80)
				courseGrade="����";
			else if(score>=70)
				courseGrade="һ��";
			else if(score>=60)
				courseGrade="����";
			else 
				courseGrade="������"; 
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

