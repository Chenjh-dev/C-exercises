/*
盒子容器（运算符重载）

题目描述
定义盒子容器类，包含4个成员：编号、长、宽、高，(长大于等于宽)且该盒子容积就为它的体积，
现向每个盒子容器里面倒满水，重定义“-”运算符，实现求出一个盒子放入
另一个盒子容器内溢出来水的体积，并输入溢出水最多的两个盒子容器的编号
以及溢出水的体积(温馨提示：不一定就是两个体积相减)。盒子容器类的基本形式如下：
class box{
private string num;
private int length;
private int width;
private int height;
…
}

输入
第一行输入圆柱体的个数
第二行开始依次输入每个圆柱体的编号、长、宽、高

输出
溢出水最多的两个圆柱体容器的编号以及溢出水的体积

样例输入
3
01 10 10 12
02 12 9 8
03 12 10 8

样例输出
02盒子放入03盒子溢出的水最多，为864。

按题目要求定义CBox类并重载-运算符。
定义一个全局函数求出所有立方体盒子中溢出水最多的两个盒子容器的编号以及溢出水的体积。
主函数定义对象指针数组，输入数据，动态创建对象。最后调用全局函数求出结果。

*/

#include<iostream>
using namespace std;

class CBox
{
	private:
		int length,width,height;
		string num;
	public:
		CBox(){}
		void set(string a,int x1,int x2,int x3)
		{
			num=a;
			length=x1;
			width=x2;
			height=x3;
		}
		int operator - (CBox &p)
		{
			int m1,m2,m3,M1,M2,M3;
			if(height>=length)//三数排序 
			{
				m1=height;
				m2=length;
				m3=width;
			}
			if(width>=height)
			{
				m1=length;
				m2=width;
				m3=height;
			}
			else
			{
				m1=length;
				m2=height;
				m3=width;
			}
			if(p.geth() >=p.getl() ) 
			{
				M1=p.geth() ;
				M2=p.getl() ;
				M3=p.getw() ;
			}
			if(p.getw() >=p.geth() )
			{
				M1=p.getl() ;
				M2=p.getw() ;
				M3=p.geth() ;
			}
			else
			{
				M1=p.getl() ;
				M2=p.geth() ;
				M3=p.getw() ;
			}
			
			if(m3<M3||m2<M2)
				return 0;
			else
			{
				if(m1>=M1)
					return M1*M2*M3;
				else
					return m1*M2*M3;
			}
			
			
		}
		string getnum(){return num;}
		int getl(){return length;}
		int getw(){return width;}
		int geth(){return height;}
};

void find(CBox *p,int n)
{
	int i,j,v1=0,v2=0,num1=0,num2=0;
	for(i=0;i<n-1;i++)
	{
		for(j=i+1;j<n;j++)
		{
			v2=p[i]-p[j];
			if(v2>v1)
			{
				v1=v2;
				num1=i;
				num2=j;
			}
			v2=p[j]-p[i];
			if(v2>v1)
			{
				v1=v2;
				num1=j;
				num2=i;
			}
		}
	}
	cout<<p[num2].getnum()<<"盒子放入"<<p[num1].getnum()<<"盒子溢出的水最多，为"<<v1<<"。"<<endl;
}

int main()
{
	string num;
	int i,n,x1,x2,x3,k;
	cin>>n;
	CBox *p;
	p=new CBox[n];
	for(i=0;i<n;i++)
	{
		cin>>num>>x1>>x2>>x3;
		p[i].set(num,x1,x2,x3); 
	}
	find(p,n);
	delete [] p;
}
