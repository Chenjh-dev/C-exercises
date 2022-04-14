//电话号码升位(拷贝构造函数)

//题目描述
//定义一个电话号码类CTelNumber,包含1个字符指针数据成员,以及构造、析构、打印及拷贝构造函数。
//字符指针是用于动态创建一个字符数组，然后保存外来输入的电话号码
//构造函数的功能是为对象设置键盘输入的7位电话号码，
//拷贝构造函数的功能是用原来7位号码的对象升位为8位号码对象,也就是说拷贝构造的对象是源对象的升级.电话升位的规则是原2、3、4开头的电话号码前面加8，原5、6、7、8开头的前面加2。
//注意:电话号码只能全部是数字字符，且与上述情况不符的输入均为非法)

//输入
//测试数据的组数 t
//第一个7位号码
//第二个7位号码
//......

//输出
//第一个号码升位后的号码
//第二个号码升位后的号码
//......

//如果号码升级不成功，则输出报错信息，具体看示例

//样例输入
//3
//6545889
//3335656
//565655

//样例输出
//26545889
//83335656
//Illegal phone number


//按题目要求定义CTelNumber类(不能在成员函数里用cin输入),
//同时编写一个全局函数判断电话号码合法性
//(假设电话号码只能是7位数字字符，且第1个数字不能是0、1和9)。
//主函数输入7位号码并调用判断函数,若合法则定义一个对象oldtel，
//再用oldtel对象拷贝构造newtel实现号码升级，
//最后用newtel调用打印成员函数输出号码升位结果。

#include<iostream>
#include<string.h>
using namespace std;

class CTelNumber
{
	public:
		CTelNumber(char *a)
		{
			oldtel = new char[9];
			strcpy(oldtel,a);
		}
		CTelNumber(const CTelNumber &r)
		{
			int i;
			switch(r.oldtel[0])
			{
				case '2':
				case '3':
				case '4':newtel[0]=8+'0';break;
				case '5':
				case '6':
				case '7':
				case '8':newtel[0]=2+'0';break;
				default:break;
			}
			for(i=0;i<7;i++)
			{
				newtel[i+1]=r.oldtel[i]; 
			} 
		}
		void print()
		{
			newtel[8] = '\0' ;
			cout<<newtel<<endl;
		}
		~CTelNumber(){}
	private:
		char *oldtel;
		char newtel[9];
};

int Judge(char *p)
{
	int m=1;
	int L;
	L=strlen(p);
	if(L != 7 || p[0]== '0' || p[0]=='1' || p[0]=='9')
	{
		cout << "Illegal phone number" << endl;
		m = 0;
	}
	if(m!=0)
	{
		int i;
		for(i=0;i<L;i++)
		{
			if(p[i]<'0' || p[i]>'9')
			{
				m=0;
				cout << "Illegal phone number" << endl;
			}
			if(m==0)
				break;
		}
	}
	return m;
}

int main()
{
	int t,m;
	cin>>t;
	char a[9];
	while(t--)
	{
		cin>>a;
		m = Judge(a);
		if(m!=0)
		{
			CTelNumber b1(a);
			CTelNumber b2(b1);
			b2.print() ;
		}	
	}
	return 0;
}
