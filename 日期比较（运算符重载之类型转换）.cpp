/*
日期比较（运算符重载之类型转换）

题目描述
定义一个日期类CDate，包含属性：年、月、日，都是整数。
构造函数含单个参数，参数是八位整数，默认值为0，实现整数转为日期类型，
例如参数为20170612，转为year=2017, month=6, day=12
实现转换运算符重载，把日期类型转为整数，例如2017年6月8日转为20170608。
注意，如果月或日小于10，转化为整数时要补0
实现日期的输出函数Print，具体格式看示范数据
主函数如下，不能修改，请实现上面的日期类
int main()
{
	int t, t1, t2;
	CDate C1, C2;
	cin>>t;
	while (t--)
	{	cin>>t1>>t2;
		C1 = t1;
		C2 = t2;
		((C1>C2)?C1:C2).Print(); //日期大的输出，在代码C1>C2中，
		                           会自动把C1和C2转换为整数进行比较
	}
  return 0;
}
注意：本题目不需要也不要重载>运算符，只要实现转换运算符重载，
能够把日期类型转为整数就可以了

输入
第一行输入t表示有t对日期
接着每两行输入两个日期
输入t对

输出
每行输出一对日期中，日期大的信息

样例输入
2
20170630
20160528
19981111
20021212

样例输出
2017年06月30日
2002年12月12日

按题目要求完成日期类CDate的定义，包括转换构造函数和将日期类对象
转换成整数的类型转换成员函数。主函数参照题目给出的示例。
*/

#include<iostream>
#include<iomanip>
using namespace std;

class CDate
{
	private:
		int year,month,day;
	public:
		CDate(){}
		CDate(int a)
		{
			year = a/10000;
			day = a%100;
			month = ( a-year*10000-day )/100;
		}
		operator int()
		{
			return year*10000+month*100+day;
		}
		void Print()
		{
			cout<<year<<"年"<<setw(2)<<setfill('0')<<month<<"月"<<setw(2)<<setfill('0')<<day<<"日"<<endl;
		}
};

int main()
{
	int t, t1, t2;
	CDate C1, C2;
	cin>>t;
	while (t--)
	{	
		cin>>t1>>t2;
		C1 = t1;
		C2 = t2;
		((C1>C2)?C1:C2).Print();
	}
 	return 0;
}



