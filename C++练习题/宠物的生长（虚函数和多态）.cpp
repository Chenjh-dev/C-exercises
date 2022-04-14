/*
������������麯���Ͷ�̬��

��Ŀ����
��Ҫ����һ��ϵͳ���Գ��������״̬���й�����������Ļ����ܣ�
class Pet
{ protected:
����string name;//����
int length;//��
int weight;//����
CDate current;//��ʼ��¼ʱ��
��������CDate�����ꡢ�¡�������˽�����ݣ���������������Ҫ���⡣��
public:
virtual void display(CDate day)=0;//���Ŀ������ʱ�������������
}
��PetΪ���࣬������Cat��Dog������:
Catһ������0.1�����ؼ�0.2��
Dogһ������0.2�����ؼ�0.1��
���������ಢ��д��������Ҫ������������һ������ָ��Pet *pt�����ڲ����������ݡ�
�����������������Ϣ����Ӧ����Cat������Dog����󣬲�������������ʱ������������ء�

����
��һ��Ϊ���Դ���
�ڶ����ǿ�ʼ��¼����
�ӵ�������ÿ����������ռһ�У�ÿ�и�������Ļ�����Ϣ��
��������ͣ�1ΪCat��2ΪDog�������֡��������ء������������ڡ�

���
Ҫ�����Ŀ�����ڳ����������������أ����Ҫ����С�����2λ��������������С�ڿ�ʼ���ڣ������error����

��������
3
2019 5 5
1 tony 10 10 2018 12 30
2 jerry 5 6 2019 5 10
1 tom 3 4 2019 6 1

�������
error
jerry after 5 day: length=6.00,weight=6.50
tom after 27 day: length=5.70,weight=9.40

����ĿҪ����ɻ���Pet��������Cat��Dog�Ķ��塣�������������ݡ�
�û���ָ��ָ��̬�����Ķ��󲢵�����س�Ա������
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
		CDate current;//��ʼ��¼ʱ��
	public:
		Pet(string a,float l,float w,CDate b)
		{
			name=a;
			length=l;
			weight=w;
			current=b;
		}
		virtual void display(CDate day)=0;//���Ŀ������ʱ�������������
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
