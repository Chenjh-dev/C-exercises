/*
复数运算（友元函数）

复数类的声明如下：
http://172.31.221.21/JudgeOnline/upload/pimg1098_1.png
要求如下：
1.实现复数类和友元函数addCom和outCom。
2.参考addCom函数为复数类增加一个友元函数minusCom，用于实现两个复数的减法
3.在main函数中，通过友元函数，实现复数的加减法和复数的输出。

输入
第1行：第1个复数的实部和虚部
第2行：需进行运算的次数，注意：是连续运算。具体结果可参考样例
第3行开始，每行输入运算类型，以及参与运算的复数的实部与虚部。“+”表示复数相加，“-”表示复数相减。


输出
每行输出复数运算后的结果，复数输出格式为“(实部,虚部)”。

样例输入
10 10
3
+ 20 10
- 15 5
+ 5 25

样例输出
(30,20)
(15,15)
(20,40)
根据题目要求完成complex类及addCom、minusCom和outCom函数的定义。
主函数输入数据、定义complex对象并调用相应函数完成运算输出结果。

*/

#include<iostream>
using namespace std;

class complex
{
	public:
		complex();
		complex(double r,double i){real=r,imag=i;}
		friend complex addCom(complex &c1,complex &c2);
		friend complex minusCom(complex &c1,complex &c2);
		friend void outCom(complex c);
	private:
		double real;
		double imag;
};

complex addCom(complex &c1,complex &c2)
{
	double h;
	h = c1.real + c2.real;
	c1.real = h ;
	h = c1.imag + c2.imag;
	c1.imag = h;
}

complex minusCom(complex &c1,complex &c2)
{
	double h;
	h = c1.real - c2.real;
	c1.real = h ;
	h = c1.imag - c2.imag;
	c1.imag = h;
}

void outCom(complex c)
{
	cout<<"("<<c.real<<","<<c.imag<<")"<<endl;
}

int main()
{
	double x1,y1,x2,y2;
	char h;
	cin>>x1>>y1;
	complex a(x1,y1);
	int t;
	cin>>t;
	while(t--)
	{
		cin>>h;
		cin>>x1>>y1;
		complex b(x1,y1);
		if( h == '+')
			addCom(a,b) ;
		else if( h == '-')
			minusCom(a,b) ;
		outCom(a);
	}
}
