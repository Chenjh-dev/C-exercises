/*
筛法求素数(静态数据成员和静态成员函数)

题目描述
用埃拉托斯特尼筛法求num之内的素数就是依次把不大于num的平方根的所有素数的倍数剔除。
也即首先从2开始，把2的倍数剔除,然后把下一个剩下的最小素数3的倍数剔除，依此类推直到不大于num的平方根，最后剩下的就都是素数。
以下CSieve类用数组sieve表示筛子，sieve[i]='1'表示i是素数, sieve[i]='0'表示i被剔除不是素数: 
class CSieve
 {
 private:
         char *sieve;
         unsigned long num;
         void findPrime();     //用筛法筛除2到num之间的所有非素数(使相应的sieve数组元素为'0')
 public:
         CSieve(unsigned long n);
         void printPrime();        //打印所有sieve[i]='1'的i
         ~CSieve();
 };
修改完善上述CSieve类，使所有CSieve类的对象共享sieve数组并能够用类名调用printPrime()。
如果新定义的对象的num值不大于sieve数组的大小,则表示该范围内的素数已经筛选完毕，不必再调用findPrime()。
如果新定义的对象的num值大于sieve数组的大小,则需要重新分配sieve数组作为筛子并调用findPrime()找出新范围内的所有素数。
(主函数提示：首先根据测试次数定义CSieve对象指针数组，每次测试动态创建CSieve对象) 

输入
第一行输入测试次数。
每次测试输入一行，即区域上限n（大于2）。

输出
每次测试输出一行，即2到n的所有素数。

样例输入
3
23
100
44

样例输出
2 3 5 7 11 13 17 19 23
2 3 5 7 11 13 17 19 23 29 31 37 41 43 47 53 59 61 67 71 73 79 83 89 97
2 3 5 7 11 13 17 19 23 29 31 37 41 43

按题目要求定义CSieve类(必须将sieve指针定义为静态数据成员),
主函数定义CSieve类对象指针数组、输入数据、动态创建对象并调用printPrime成员函数输出素数。
*/

#include<iostream>
#include<cmath>
using namespace std;

class CSieve
{
	private:
        static char *p_sieve;
        unsigned long num;
	public:
        CSieve(unsigned long n)
        {
        	int i;
        	num = n;
        	p_sieve =new char[num+1];
    		for(i=0;i<=num;i++)
    		{
    			p_sieve[i] ='1';
			}
		}
		void shaixuan();
		int getnum()
		{
			return num;
		}
        void printPrime(int k,int mm);
        ~CSieve(){}
};

char *CSieve::p_sieve = NULL;

void CSieve::shaixuan()
{
	int n,i;
	for(n=2;n<=sqrt(num);n++)
	{
		if(p_sieve[n] == '0')
			continue;
		for(i=n*2;i<=num;i+=n)
			p_sieve[i]='0';
		
	}
}

void CSieve::printPrime(int k,int mm)
{
	int i;
	if(mm==1)
	{
		for(i=2;i<=k;i++)
		{
			if(p_sieve[i]=='1')
			{
				cout<<i<<" ";
			}
		}
	}
	else
	{
		for(i=2;i<=num;i++)
		{
			if(p_sieve[i]=='1')
			{
				cout<<i<<" ";
			}
		}
	}
	
	cout<<endl;
}

int main()
{
	int t,i=0,mm=1;
	int n[20];
	int k[20]={0};
	int j=0;
	cin>>t;
	CSieve* s[20];
	while(t--)
	{
		cin>>n[i];
		if( i>0 && n[i] <= n[j] )
		{
			s[i-1]->printPrime(n[i],mm);
		}
		else
		{
			j=i;
		 	s[i] = new CSieve(n[i]);
			s[i]->shaixuan ();
  	   		s[i]->printPrime (n[i],mm);
  	   		k[i]=1;
		}
        i++;
	}
	for(i=0;i<20;i++)
	{
		if(k[i]==1)
			delete s[i];
	}
}
