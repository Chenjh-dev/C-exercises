//���������������(�������캯��)

//��Ŀ����
//ĳ�������һ���������ݳ�Ա.��������ʱ������0��ʾ��ȱʡ��ʽ����һ�������;
//����1��һ��������ʾ�ô�һ�������Ĺ��캯������һ�������;
//����2��һ��������ʾ����2�������һ����������������죬��һ����ǰһ�������졣
//����ɸ���Ķ����ʵ�֡�

//����
//�������ݵ����� t
//��һ����
//�ڶ�����
//......

//���
//��һ�����������
//�ڶ������������
//......


//��������
//3
//0
//1 10
//2 20

//�������
//Constructed by default, value = 0
//Constructed using one argument constructor, value = 10
//Constructed using one argument constructor, value = 20
//Constructed using copy constructor, value = 20

//������ĿҪ�������ж����������캯��(�����ڹ��캯�������Ӧ����Ϣ)��
//������ʵ�����ݵ����롢�������붨�岻ͬ�Ķ���

#include<iostream>
using namespace std;

class First
{
	public:
		First()
		{
			value = 0 ;
			cout << "Constructed by default, value = " << value << endl;
		}
	private:
		int value;
};

class Second
{
	public:
		Second(int a)
		{
			value = a ;
			cout << "Constructed using one argument constructor, value = " << value << endl;
		}
	private:
		int value;
};

class Third
{
	public:
		Third(int b)
		{
			value = b;
			cout << "Constructed using one argument constructor, value = " << value << endl;
		}
		Third(const Third &r)
		{
			value = r.value ;
			cout << "Constructed using copy constructor, value = " << value << endl;
		}
	private:
		int value;
};

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,m;
		cin >> n;
		if(n == 0)
		{
			First k1;
		}
		else if(n == 1)
		{
			cin >> m;
			Second k2(m);
		}	
		else if(n == 2)
		{
			cin >> m;
			Third k3(m),k4(k3);
		}
		else 
			t++;
	}
	return 0;
}
