//问题 : 身体评估（类与对象）
//题目描述
//评估成年人身体健康有多个指标，包括BMI、体脂率等
//设计一个身体健康类，包含私有成员：姓名、身高(米)、体重(公斤)，腰围(厘米)，实现两个公有方法如下：
//BMI方法，返回BMI数值(整数)，计算公式BMI= 体重 / 身高的平方
//体脂率方法，返回体脂率数值(浮点数)，计算过程如下：
//1）参数a=腰围（cm）×0.74
//2）参数b=体重（kg）×0.082+34.89
//3）体脂肪重量（kg）=a－b
//4）体脂率 = 体脂肪重量÷体重
//其它方法根据需要自行定义


//输入
//第一行输入t表示有t个测试实例
//第二行起，每行输入四个参数：姓名、身高、体重，腰围
//依次输入t行

//输出
//输出t行，每行输入一个实例的BMI和体脂率，小数数值精确到小数点后2位，用空格隔开


//样例输入
//2
//张高 1.85 78.5 85.2
//李圆 1.55 67.6 77.3

//样例输出
//张高的BMI指数为23--体脂率为0.28
//李圆的BMI指数为28--体脂率为0.25

//按题目要求定义BMI类，含构造函数、计算BMI的成员函数、计算体脂率的成员函数
//以及按指定格式输出数据成员值的成员函数。主函数实现数据的输入、对象的定义、
//调用相关成员函数完成计算、最后输出计算结果(用cout << fixed << setprecision(2)设置输出2位小数)。


#include<iostream>
#include<iomanip>
using namespace std;

class Body
{
	public:
		Body(string a,float b,float c, float d);
		void Jisuan();
		void print();
	private:
		string name;
		float height;
		float weight;
		float waistline;
		int BMI;
		float BFR;
};

Body::Body (string a,float b,float c,float d)
{
	name =a;
	height =b;
	weight =c;
	waistline =d;	
} 

void Body::Jisuan()
{
	BMI = weight/(height*height)+0.5;
	BFR = (waistline*0.74-(weight*0.082+34.89))/weight;
}

void Body::print()
{
	cout<<name<<"的BMI指数为"<<BMI<<"--体脂率为"<< fixed << setprecision(2) <<BFR<<endl;
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string x1;
		float x2,x3,x4;
		cin>>x1>>x2>>x3>>x4;
		Body s(x1,x2,x3,x4);
		s.Jisuan() ;
		s.print() ;
	}
}








