//分数类（类与构造）

//题目描述
//完成下列分数类的实现:
//class CFraction
//{
// private:
//      int fz, fm;
// public:
//      CFraction(int fz_val, int fm_val) ;
//      CFraction add(const CFraction &r);
//      CFraction sub(const CFraction &r);
//      CFraction mul(const CFraction &r);
//      CFraction div(const CFraction &r);
//      int getGCD();   // 求对象的分子和分母的最大公约数
//     void print();
//};
//求两数a、b的最大公约数可采用辗转相除法，又称欧几里得算法，其步骤为:
//1. 交换a, b使a > b;
//2. 用a除b得到余数r,若r=0,则b为最大公约数,退出.
//3. 若r不为0,则用b代替a, r代替b,此时a,b都比上一次的小,问题规模缩小了;
//4. 继续第2步。

//输入
//测试数据的组数 t
//第一组第一个分数
//第一组第二个分数
//第二组第一个分数
//第二组第二个分数
//......

//输出
//第一组两个分数的和
//第一组两个分数的差
//第一组两个分数的积
//第一组两个分数的商

//第二组两个分数的和
//第二组两个分数的差
//第二组两个分数的积
//第二组两个分数的商

//......

//样例输入
//3
//1/2
//2/3
//3/4
//5/8
//21/23
//8/13

//样例输出
//7/6
//-1/6
//1/3
//3/4

//11/8
//1/8
//15/32
//6/5

//457/299
//89/299
//168/299
//273/184
//


//按题目要求定义CFraction类(不能在成员函数里用cin输入,计算结果化简保存在局部对象并返回)。
//主函数实现数据的输入、对象的定义、并依次调用相关成员函数完成分数运算及输出运算结果。


#include<iostream>
using namespace std;

class CFraction
{
private:
    int fz, fm;
    int FZ,FM;
public:
    CFraction(int fz_val, int fm_val)
    {
    	fz = fz_val;
    	fm = fm_val;
	}
    CFraction add(const CFraction &r)
    {
    	FM = fm*r.fm ;
    	FZ = fz*r.fm + fm*r.fz ;
    	getGCD();
	}
    CFraction sub(const CFraction &r)
    {
    	FM = fm*r.fm ;
    	FZ = fz*r.fm - fm*r.fz ;
    	getGCD();
	}
    CFraction mul(const CFraction &r)
    {
    	FM = fm*r.fm ;
    	FZ = fz*r.fz ;
    	getGCD();
	}
    CFraction div(const CFraction &r)
    {
    	FM = fm*r.fz ;
    	FZ = fz*r.fm ;
    	getGCD();
	}
    int getGCD()
	{
		int n1,n2,r;
		if(FZ >= FM)
		{
			n1 = FZ;
			n2 = FM;
		}
		else
		{
			n1 = FM;
			n2 = FZ;
		}
		for(r=1 ; r != 0 ; )
		{
			r = n1 % n2 ;
			if(r != 0)
			{
				n1 = n2;
				n2 = r;
			}
		}
		FZ = FZ/n2;
		FM = FM/n2;
		if(FM < 0)
		{
			FM = FM*-1;
			FZ = FZ*-1;
		}
		print();
	}
    void print()
    {
    	cout << FZ << "/" << FM <<endl;
	}
};

int main()
{
	int t,x1,x2,x3,x4;
	char k1,k2;
	cin>>t;
	while(t--)
	{
		cin >> x1 >> k1 >> x2 ;
		CFraction a(x1,x2);
		cin >> x3 >> k2 >> x4;
		CFraction b(x3,x4);
		a.add(b); 
		a.sub(b);
		a.mul(b);
		a.div(b);
		cout <<endl;
	}
	return 0;
}

