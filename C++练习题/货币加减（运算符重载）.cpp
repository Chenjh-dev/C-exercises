/*

题目描述
定义CMoney类，包含元、角、分三个数据成员，友元函数重载‘+’、'-'，
实现货币的加减运算（假设a-b中a的金额始终大于等于b的金额），
重载输入、输出，实现货币的输入，输出。
读入最初的货币值，对其不断进行加、减操作，输出结果。
可根据需要，为CMoney类添加构造函数或其它成员函数。

输入
测试次数
每组测试数据格式如下：
第一行，初始货币：元 角 分
第二行开始，每行一个操作：add 元 角 分（加）、minus 元 角 分（减）、stop（结束）

输出
对每组测试数据，输出操作终止后的货币金额，具体输出格式见样例。
 
样例输入
2
0 0 0
add 48 9 0
minus 0 5 3
add 18 6 8
add 12 1 2
stop
10 2 5
add 5 8 0
add 32 1 2
minus 10 5 9
minus 37 5 8
stop

样例输出
79元1角7分
0元0角0分

按题目要求用友元实现CMoney类的+、-、>>和<<运算符重载函数。
主函数首先用缺省方式定义2个对象a,b,之后用cin>>a输入第1个对象数据、
用cin >> cmd >> b输入操作命令和对象b,最后根据cmd完成a与b的加减运算
并用cout<<a输出保存在a的运算结果。
*/

#include <iostream>
#include<cstring>
using namespace std;

class CMoney
{
	private:
		int yuan,jiao,fen;
	public:
		CMoney(){}
		CMoney operator + (const CMoney &b)
		{
			yuan+=b.yuan ;
			jiao+=b.jiao ;
			fen+=b.fen ;
			if(fen>10)
			{
				fen-=10;
				jiao++;
			}
			if(jiao>10)
			{
				jiao-=10;
				yuan++;
			}
		}
		CMoney operator - (const CMoney &b)
		{
			yuan-=b.yuan ;
			jiao-=b.jiao ;
			fen-=b.fen ;
			if(fen<0)
			{
				fen+=10;
				jiao--;
			}
			if(jiao<0)
			{
				jiao+=10;
				yuan--;
			}
		}
		friend istream & operator >> (istream &in,CMoney &a)
		{
			in >> a.yuan >> a.jiao >> a.fen;
			return in;
		} 
		friend ostream & operator << (ostream & out,const CMoney &a)
		{
			cout<<a.yuan <<"元"<<a.jiao <<"角"<<a.fen <<"分";
			return out;
		}
};

int main()
{
	int t,x1,x2,x3;
	CMoney a,b;
	string cmd;
	cin>>t;
	while(t--)
	{
		cin>>a;
		cin>>cmd>>b;
		while(1)
		{
			if(cmd=="add")
				a+b;
			else if(cmd=="minus")
				a-b;
			cin>>cmd;
			if(cmd=="stop")
				break;
			else
				cin>>b;
		}
		cout<<a<<endl;
	}
}


