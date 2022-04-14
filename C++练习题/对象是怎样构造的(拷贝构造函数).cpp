//对象是怎样构造的(拷贝构造函数)

//题目描述
//某个类包含一个整型数据成员.程序运行时若输入0表示用缺省方式定义一个类对象;
//输入1及一个整数表示用带一个参数的构造函数构造一个类对象;
//输入2及一个整数表示构造2个类对象，一个用输入的整数构造，另一个用前一个对象构造。
//试完成该类的定义和实现。

//输入
//测试数据的组数 t
//第一组数
//第二组数
//......

//输出
//第一个对象构造输出
//第二个对象构造输出
//......


//样例输入
//3
//0
//1 10
//2 20

//样例输出
//Constructed by default, value = 0
//Constructed using one argument constructor, value = 10
//Constructed using one argument constructor, value = 20
//Constructed using copy constructor, value = 20

//根据题目要求在类中定义三个构造函数(可以在构造函数输出相应的信息)。
//主函数实现数据的输入、根据输入定义不同的对象。

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
