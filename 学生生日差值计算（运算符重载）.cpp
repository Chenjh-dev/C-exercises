/*
����ĿҪ����Student�ಢ����-�������
����һ��ȫ�ֺ����������ѧ��������������������˵������Լ����������
�������������ָ�����飬�������ݣ���̬��������������ȫ�ֺ�����������

��Ŀ����
����һ��ѧ����Student��������ѧ���������������ꡢ�¡��� ���ض��� ��-��
��ʵ������ѧ��֮����������ıȽϡ����������صġ�-���������
������ѧ��������������������˵������Լ����������

����
��һ�У���������Ҫ�����ѧ��������
�ڶ��п�ʼ����������ÿ��ѧ���������������ꡢ�¡��ա�

���
�������������������˵������Լ����������

��������
3
Tom 1995 1 1
Joe 1995 2 28
Jimmy 1996 1 8

�������
Tom��Jimmy����������Ϊ372�졣

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
	cout<<p[max].getname()<<"��"<<p[min].getname()<<"����������Ϊ"<<p[max]-p[min]<<"�졣"<<endl;
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

