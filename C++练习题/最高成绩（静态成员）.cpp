/*
��߳ɼ�����̬��Ա��

��Ŀ����
ѧ���ඨ�����£�
class Student {
private:
	int id;	//ѧ��
	int score; //�ɼ�
	static int  maxscore;	//��߷���
	static int maxid;		//��߷���ѧ��ѧ��
public:
	Student(int ti=0,int ts=0):id(ti), score(ts){}
	static void findMax(Student & st); //Ѱ����߳ɼ���ѧ��
	static int getMaxScore(); //������߳ɼ�
	static int getMaxID();		//������߳ɼ���ѧ��
};
����һ��ѧ��ѧ�źͳɼ�����������̬��Ա����߳ɼ��Ͷ�Ӧѧ��

����
��һ������n��ʾ��n��ѧ��
��������n�У�ÿ�а����������ݣ���ʾѧ�źͳɼ�

��� 
���þ�̬��Ա�������ѧ�ź���߳ɼ�����ʽ������

��������
3
1002 68
1023 54
1045 32

�������
1002--68
*/ 

//����ĿҪ�����Student��Ķ��塣����������Student�����ָ�����顢�������ݡ�
//��̬�������󲢵���findMax��������getMaxID��getMaxScore������������Ϣ��������̬�����Ķ���

#include<iostream>
using namespace std;

class Student 
{
	private:
		int id;	//ѧ��
		int score; //�ɼ�
		static int  maxscore;	//��߷���
		static int maxid;		//��߷���ѧ��ѧ��
	public:
		Student(int ti=0,int ts=0):id(ti), score(ts){}
		void Get(int a,int b){id = a;score = b;}
		static void findMax(Student st[],int n); //Ѱ����߳ɼ���ѧ��
		static int getMaxScore(){return Student::maxscore ;} //������߳ɼ�
		static int getMaxID(){return Student::maxid ; }		//������߳ɼ���ѧ��
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
