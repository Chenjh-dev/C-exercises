/*

�ֻ�����

��Ŀ����
���һ������ʵ���ֻ��Ĺ��ܡ�������˽�����ԣ��������͡����롢
����״̬��ͣ�����ڣ��������������졢�������졢��ӡ��ͣ����
1���������ͱ�ʾ�û����ֻ�õ�����ĸ��A��ʾ������B��ʾ��ҵ��C��ʾ����
2��������11λ��������һ���ַ�����ʾ
3������״̬��һ�����ֱ�ʾ��1��2��3�ֱ��ʾ���á�δ�á�ͣ��
4��ͣ��������һ�����ڶ���ָ�룬�ڳ�ʼ��ʱ�ó�Աָ��գ�
�����������˽�����������գ��Լ����캯���ʹ�ӡ������
----------------------------------------
5�����캯�������þ��ǽ������������������ø�������ֵ,�������ʾ��Ϣ����ʾ�����
6����������������Ǹ������ж������Ϣ���������ʾ��Ϣ����ʾ�������
      ��һ��ͣ�����ڸ���θ��ƣ�û��ͣ����θ��ƣ����Ѿ�ͣ������θ��ƣ���
7����ӡ�����ǰѶ�����������Զ�����������ʽ��ʾ��
8��ͣ��������ͣ�õ�ǰ���룬������ͣ�����ڣ��޷���ֵ�������ǰ�״̬�ĳ�ͣ�ã�
��ͣ������ָ�봴��Ϊ��̬���󣬲����ݲ���������ͣ�����ڣ���������ʾ��Ϣ����ʾ�����
-------------------------------------------
Ҫ������������ʵ�ֺ��뱸�ݵĹ��ܣ������е������ֻ��ŵ�������Ϣ���и��ƣ�
�����������͸ĳ�D��ʾ���ݣ����ֻ�����ĩβ����ĸX


����
��һ������t��ʾ��t������
�ڶ�������6�������������������͡����롢״̬��ͣ�����ꡢ�¡��գ��ÿո����
��������t��


���
ÿ��ʾ��������У��������ԭ������Ϣ�����ݺ�����Ϣ��ԭ����ͣ�������Ϣ
ÿ��ʾ��֮���ö̻��ߣ��ĸ����ָ����ʾ�����


��������
2
A 15712345678 1 2015 1 1
B 13287654321 2 2012 12 12


�������
Construct a new phone 15712345678
����=����||����=15712345678||State=����
Construct a copy of phone 15712345678
����=����||����=15712345678X||State=����
Stop the phone 15712345678
����=����||����=15712345678||State=ͣ��||ͣ������=2015.1.1
----
Construct a new phone 13287654321
����=��ҵ||����=13287654321||State=δ��
Construct a copy of phone 13287654321
����=����||����=13287654321X||State=δ��
Stop the phone 13287654321
����=��ҵ||����=13287654321||State=ͣ��||ͣ������=2012.12.12
----

*/ 

#include<iostream>
#include<string>
using namespace std;

class Date
{
public:
	int day, month, year;
	Date(int x, int y, int z)
	{
		year = x, month = y, day = z;
	}

	void print()
	{
		cout << year << "." << month << "." << day;
	}
};

class Phone
{
private:
	char type;
	string number;
	int state;
	Date *p;
public:
	Phone(char x, string y, int z, int d1, int d2, int d3)
	{
		type = x;
		number = y;
		state = z;
		//Date k(d1, d2, d3);
		p =new Date(d1,d2,d3);
		cout << "Construct a new phone " << number << endl;
	}
	Phone(Phone &h)
	{
		cout << "Construct a copy of phone " << h.number << endl;
		type = 'D';
		number = h.number + "X";
		state = h.state;
		p = new Date(h.p->year, h.p->month, h.p->day);
	}
	void print()
	{
		cout << "����=";
		switch (type)
		{
		case 'A':cout << "����"; break;
		case 'B':cout << "��ҵ"; break;
		case 'C':cout << "����"; break;
		case 'D':cout << "����"; break;
		default:cout << "error"; break;
		}
		cout << "||����=" << number << "||State=";
		switch (state)
		{
		case 1:cout << "����"; break;
		case 2:cout << "δ��"; break;
		case 3:cout << "ͣ��||ͣ������=", p->print(); break;
		default:cout << "error" << endl; break;
		}
		cout << endl;
	}
	void stop(int x, int y, int z)
	{
		state = 3;
		p = new Date(x, y, z);
		cout << "Stop the phone " << number << endl;
	}
};

int main()
{
	char type;
	string number;
	int state, year, month, day, t;
	cin >> t;
	while (t--)
	{
		cin >> type >> number >> state >> year >> month >> day;
		Phone A(type, number, state, year, month, day);
		A.print();
		Phone B = A;
		B.print();
		A.stop(year, month, day);
		A.print();
		cout << "----" << endl;
	}
}
