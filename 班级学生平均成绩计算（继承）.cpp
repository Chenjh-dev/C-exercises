/*
�༶ѧ��ƽ���ɼ����㣨�̳У�

��Ŀ����
����Person�������������������ԣ��������������Ϣ��display������
ѡ�ޡ�������������ơ��γ̵�ѧ������Person��Ļ����ϣ������������ࣺѧ���ࡣ
����̳и����Ա������������Ա����дdisplay������
1.       ѧ�������ƽʱ�ɼ������Գɼ��������ɼ��������ԣ�
2.       ���������ɼ��ĺ����������ɼ�=ƽʱ�ɼ�*40%+���Գɼ�*60%��
3.       �µ�display����
���ڡ�������������ơ��γ̵���ʦ����Person��Ļ����ϣ������������ࣺ��ʦ�ࡣ
����̳и����Ա������������Ա����дdisplay������
1.       ����ѡ��ѧ�����顢ѡ���������༶ƽ������������
2.       ��ѡ��ѧ������������һ��ѧ���ĺ���
3.       ����༶ѧ��ƽ���ֵĺ���
4.       �µ�display����
���������ಢ��д�����������Ƚ���һ����ʦ�����
���n��ѧ�����������ʦ������ѡ��ѧ�������С�
����ý�ʦ���ڰ༶ѧ����ƽ���ɼ����������

����
��ʦ����������Ϣ
ѡ������n
���ÿ������ѧ������������Ϣ

���
��ʦ�������Ϣ
����ѡ��ѧ����Ϣ

��������
Cindy 18
2
Sandy 8 90 80
David 9 60 70

�������
Cindy 18 2 75.00
Sandy 8 84.00
David 9 66.00

����ĿҪ����CPerson���������CStudent��
�������������ݡ�������󲢵�����Ӧ�ĳ�Ա����ʵ�ֳ���Ĺ��ܡ�
*/

#include<iostream>
#include<cstring>
#include<iomanip>
using namespace std;

class CPerson
{
	protected:
		string name;
		int age;
	public:
		CPerson(){}
		CPerson(string a,int b):name(a),age(b){}
		virtual void display()=0;
};

class CStudent:public CPerson
{
	private:
		float usualgrade;
		float examgrade;
		float allgrade;
	public:
		CStudent(){}
		CStudent(string a,int b,float c,float d):CPerson(a,b),usualgrade(c),examgrade(d){}
		float Jisuan(){ allgrade=0.4*usualgrade+0.6*examgrade; return allgrade; }
		void display(){ cout<<name<<" "<<age<<" "<<allgrade<<endl; }
};

class CTeacher:public CPerson
{
	private:
		CStudent *h[1000];
		int number;
		float average;
	public:
		CTeacher(string a,int b,CStudent *c[1000],int d):CPerson(a,b),number(d)
		{
			average=0;
			for(int i=0;i<number;i++)
				h[i]=c[i];
		}
		void JIsuan()
		{
			int i;
			float k=0;
			for(i=0;i<number;i++)
				k+= h[i]->Jisuan() ;
			average=k/number;
		}
		void display()
		{ 
			cout<<name<<" "<<age<<" "<<number<<" "<<fixed<<setprecision(2)<<setfill('0')<<average<<endl; 
			for(int i=0;i<number;i++)
				h[i]->display() ;
		}
		~CTeacher()
		{
			for(int i=0;i<number;i++)
				delete h[i];
		}
};

int main()
{
	string name,Name;
	int i,n,age,Age;
	float score1,score2;
	cin>>Name>>Age>>n;
	CStudent *p[1000];
	for(i=0;i<n;i++)
	{
		cin>>name>>age>>score1>>score2;
		p[i]=new CStudent(name,age,score1,score2);
	}
	CTeacher h(Name,Age,p,n);
	h.JIsuan() ;
	h.display() ;
	for(i=0;i<n;i++)
		delete p[i];
}

