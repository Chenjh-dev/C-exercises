/*
����԰���麯�����̬��

��Ŀ����
ĳ������԰�ڣ����ϻ�������Ѽ�Ӻ���ȶ������԰�Ĺ���ԱΪÿ�����ﶼ����һ�����֣�
����ÿ�����ﶼ�����䡢���ص���Ϣ��ÿ��ιʳ��ʱ�򣬲�ͬ�Ķ��ﶼ��л�(speak)��
ÿ�ֶ���Ľл�������ͬ���ϻ��Ľл����ǡ�AOOO�������Ľл����ǡ�WangWang����
Ѽ�ӵĽл����ǡ�GAGA������Ľл����ǡ�HENGHENG����
����һ��Animal�Ļ��࣬Animal���к���Speak()���������ϻ�(Tiger)����(Dog)��
Ѽ��(Duck)����(Pig)�࣬���ܷ�����ͬ�Ľл��������ı���Ϣ�����������
��д�������붯�����ơ����֡����䣬�ö���԰�ڵĸ��ֶ���л���
Ҫ��ֻʹ��һ������ָ�룬ָ�����ɵĶ��󲢵��÷�����

����
���԰����ĸ���
��һ�ֶ��������  ����  ����
�ڶ��ֶ��������  ���� ����
......

���
�����Ӧ�������Ϣ
��������ڸ��ֶ�����There is no �������� in our Zoo.  ����������ο��������

��������
4
Tiger Jumpjump 10
Pig Piglet 4
Rabbit labi 3
Duck tanglaoya 8

�������
Hello,I am Jumpjump,AOOO.
Hello,I am Piglet,HENGHENG.
There is no Rabbit in our Zoo.
Hello,I am tanglaoya,GAGA.

����ĿҪ����ɻ���Animal��������Tiger��Dog��Duck��Pig�Ķ��塣
�������������ݡ��û���ָ��ָ��̬�����Ķ��󲢵���speak��Ա������
*/

#include<iostream>
#include<cstring>
using namespace std;

class Animal
{
	public:
		Animal(string a,int b):name(a),age(b){}
		virtual void Speak()=0;
	protected:
		string name;
		int age;
};

class Tiger:public Animal
{
	public:
		Tiger(string a,int b):Animal(a,b){}
		void Speak(){ cout<<"Hello,I am "<<name<<",AOOO."<<endl; }
};

class Dog:public Animal
{
	public:
		Dog(string a,int b):Animal(a,b){}
		void Speak(){ cout<<"Hello,I am "<<name<<",WangWang."<<endl; }
};

class Duck:public Animal
{
	public:
		Duck(string a,int b):Animal(a,b){}
		void Speak(){ cout<<"Hello,I am "<<name<<",GAGA."<<endl; }
};

class Pig:public Animal
{
	public:
		Pig(string a,int b):Animal(a,b){}
		void Speak(){ cout<<"Hello,I am "<<name<<",HENGHENG."<<endl; }
};

void show(Animal *r)
{
	r->Speak();
}

int main()
{
	int t;
	cin>>t;
	char a[20];
	string b;
	int c;
	Animal *p;
	while(t--)
	{
		cin>>a>>b>>c;
		
		if(!strcmp(a,"Tiger"))
			{ p =new Tiger(b,c); }
		else if(!strcmp(a,"Dog"))
			{ p =new Dog(b,c); }
		else if(!strcmp(a,"Duck"))
			{ p =new Duck(b,c); }
		else if(!strcmp(a,"Pig"))
			{ p =new Pig(b,c); }
		else
			{ cout<<"There is no "<<a<<" in our Zoo."<<endl; continue; }
		show(p);
		delete p;
	}
	
}

