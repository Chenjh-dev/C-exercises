//按题目要求完成CLuckNumber类的定义。主函数实现数据的输入、先用构造函数定义
//一个对象再用该对象拷贝构造一个对象、并用拷贝构造的对象调用成员函数输出相关信息。

#include<iostream>
using namespace std;

class CLuckNumber
{
	public:
		CLuckNumber(int a)
		{
			value = a;
			p = new int[value];
		}
		CLuckNumber(const CLuckNumber &r)
		{
			value = r.value ;
			p = new int[value+1];
		}
		void Jisuan()
		{
			int n;
			B = 0;
			for(n =1 ; n<=value ; n++)
			{
				if( n%3 != 0 && n%4 != 0 && n%7 == 0 )
				{
					p[B] = n;
					B++;
				}
			}
		}
		void print()
		{
			int i;
			for(i=0 ; i<B ; i++)
			{
				if(i == 0)
					cout << p[0];
				else 
					cout << " " << p[i] ;
			}
			cout << endl;
		}
		~CLuckNumber()
		{
			if(p != NULL)
			delete [] p;
		}
	private:
		int value;
		int *p;
		int B;
};

int main()
{
	int t,m;
	cin >> t;
	while(t--)
	{
		cin >> m;
		CLuckNumber k1(m);
		CLuckNumber k2(k1);
		k2.Jisuan() ;
		k2.print() ; 
	}
	return 0;
}
