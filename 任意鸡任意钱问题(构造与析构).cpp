//任意鸡任意钱问题(构造与析构)

//题目描述
//百鸡百钱问题描述为：用100元钱买100只鸡，已知每只公鸡5元，每只母鸡3元，3只小鸡1元，问能买多少只公鸡、母鸡和小鸡？
//试将该类问题用一个类来表示，百鸡百钱问题只是这个类如CChickProblem的一个实例，假设各种鸡的价格不变,
//类中数据成员有总钱数、要买的总的鸡数、能买到的母鸡、小鸡和公鸡的数量。成员函数有构造和析构函数，
//求问题解的函数findSolution，打印问题解的函数printSolution。(要求用动态数组保存问题的所有解)
//编写程序求解该类问题。

//输入
//测试数据的组数 t
//第一组 鸡数 钱数
//第二组 鸡数 钱数
//.......

//输出
//第一组解个数
//第一组第一个解公鸡数 母鸡数 小鸡数
//第一组第二个解公鸡数 母鸡数 小鸡数
//.........

//第二组解个数
//第二组第一个解公鸡数 母鸡数 小鸡数
//第二组第二个解公鸡数 母鸡数 小鸡数
//.........

//样例输入
//2
//100 100
//200 200

//样例输出
//3
//4 18 78
//8 11 81
//12 4 84
//7
//4 43 153
//8 36 156
//12 29 159
//16 22 162
//20 15 165
//24 8 168
//28 1 171

//按题目要求定义CChickProblem类(要求用动态数组保存问题的所有解)。
//主函数实现数据的输入、对象的定义、并调用求解和打印成员函数。

#include<iostream>
using namespace std;

class CChickProblem
{
	public:
		CChickProblem(int a,int b)
		{
			value = a;
			money = b;
			p = new int[value];
		}
		void findSolution()
		{
			int x1,x2,x3,n,x4,x5;
			i=0;
			
			for( x1=1 ; x1<value ;x1++)	
				for(x2=1 ; x2<value ;x2++)
					for(x3=3 ; x3<value ;x3=x3+3)
					{
						x4 = x1+x2+x3;
						x5 = x1*5+x2*3+x3/3;
						if( (x4 == value) && (x5 == money))
						{
							p[3*i]=x1;
							p[1+3*i]=x2;
							p[2+3*i]=x3;
							i++;
						}
					}		
		}
		void printSolution()
		{
			int n;
			cout << i <<endl;
			for(n=0;n<i;n++)
			{
				
				cout << p[3*n]<< " " << p[1+3*n] << " " << p[2+3*n] << endl;
			}
		}
		~CChickProblem()
		{
			delete [] p;
		}
	private:
		int money;
		int value;
		int *p;
		int i;
};

int main()
{
	int t;
	int k1,k2;
	cin>>t;
	while(t--)
	{
		cin>>k1>>k2;
		CChickProblem s(k1,k2);
		s.findSolution() ;
		
		s.printSolution() ;
	}
	return 0;
}
