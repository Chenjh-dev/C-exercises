/*
时钟模拟(继承）

题目描述
定义计数器类，包含保护数据成员value,公有函数increment计数加1。
定义循环计算器继承计数器类，增加私有数据成员：最小值min_value，max_value,
重写公有函数increment，使得value在min_value~max_value区间内循环+1。
定义时钟类，数据成员是私有循环计数器对象小时hour、分钟minute、秒second，
公有函数time(int s)计算当前时间经过s秒之后的时间，
即hour,minute,second的新value值。
定义时钟类对象，输入当前时间和经过的秒数,调用time函数计算新时间。
根据题目要求，增加必要的构造函数、析构函数和其他所需函数。
因为clock是系统内置函数，为了避免重名，请不要使用clock作为类名或者函数名

输入
第一行测试次数n
2行一组，第一行为当前时间（小时 分钟 秒），第二行为经过的秒数。

输出
输出n行
每行对应每组当前时间和经过秒数后计算得到的新时间（小时：分钟：秒）。

样例输入
2
8 19 20
20
23 30 0
1801

样例输出
8:19:40
0:0:1

根据题目要求完成计数器类CCounter、循环计数器类CRcounter和时钟类CClock类的定义，
三个类都必须定义构造函数,其中CClock类的三个子对象数据成员hour、minute和second
定义为CRcounter类对象。主函数输入数据、定义CClock类对象
并调用其time成员函数计算新的时间。
*/

#include<iostream>
using namespace std;

class CCounter
{
	protected:
		int value;
	public:
		CCounter(int a){ value=a; }
		int increment(){ return value++; }
		int get(){ return value; }
};

class CRcounter:public CCounter
{
	private:
		int min_value;
		int max_value;
	public:
		CRcounter(int a,int b,int c):CCounter(a)
		{
			min_value = b;
			max_value = c;
		}
		int increment()
		{
			value++;
			if( value >= max_value )
				value -= max_value;
			return value;
		}
};

class CClock
{
	private:
		CRcounter hour,minute,second;
	public:
		CClock(int a,int b,int c):hour(a,0,24),minute(b,0,60),second(c,0,60){}
		int time(int s)
		{
			while(s--)
			{
				if( second.increment() == 0 )
				{
					if( minute.increment() == 0 )
						hour.increment() ;
				}
			}
			cout<<hour.get()<<":"<<minute.get()<<":"<<second.get()<<endl; 
		}
};

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int h,m,s,n;
		cin>>h>>m>>s>>n;
		CClock k1(h,m,s);
		k1.time(n); 	
	}
};
