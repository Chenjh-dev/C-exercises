/*
�������㣨��Ԫ������

��������������£�
http://172.31.221.21/JudgeOnline/upload/pimg1098_1.png
Ҫ�����£�
1.ʵ�ָ��������Ԫ����addCom��outCom��
2.�ο�addCom����Ϊ����������һ����Ԫ����minusCom������ʵ�����������ļ���
3.��main�����У�ͨ����Ԫ������ʵ�ָ����ļӼ����͸����������

����
��1�У���1��������ʵ�����鲿
��2�У����������Ĵ�����ע�⣺���������㡣�������ɲο�����
��3�п�ʼ��ÿ�������������ͣ��Լ���������ĸ�����ʵ�����鲿����+����ʾ������ӣ���-����ʾ���������


���
ÿ��������������Ľ�������������ʽΪ��(ʵ��,�鲿)����

��������
10 10
3
+ 20 10
- 15 5
+ 5 25

�������
(30,20)
(15,15)
(20,40)
������ĿҪ�����complex�༰addCom��minusCom��outCom�����Ķ��塣
�������������ݡ�����complex���󲢵�����Ӧ�������������������

*/

#include<iostream>
using namespace std;

class complex
{
	public:
		complex();
		complex(double r,double i){real=r,imag=i;}
		friend complex addCom(complex &c1,complex &c2);
		friend complex minusCom(complex &c1,complex &c2);
		friend void outCom(complex c);
	private:
		double real;
		double imag;
};

complex addCom(complex &c1,complex &c2)
{
	double h;
	h = c1.real + c2.real;
	c1.real = h ;
	h = c1.imag + c2.imag;
	c1.imag = h;
}

complex minusCom(complex &c1,complex &c2)
{
	double h;
	h = c1.real - c2.real;
	c1.real = h ;
	h = c1.imag - c2.imag;
	c1.imag = h;
}

void outCom(complex c)
{
	cout<<"("<<c.real<<","<<c.imag<<")"<<endl;
}

int main()
{
	double x1,y1,x2,y2;
	char h;
	cin>>x1>>y1;
	complex a(x1,y1);
	int t;
	cin>>t;
	while(t--)
	{
		cin>>h;
		cin>>x1>>y1;
		complex b(x1,y1);
		if( h == '+')
			addCom(a,b) ;
		else if( h == '-')
			minusCom(a,b) ;
		outCom(a);
	}
}
