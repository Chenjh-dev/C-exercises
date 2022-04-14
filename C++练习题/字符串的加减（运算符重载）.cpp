/*

按题目要求定义CStr类的+、-和=运算符重载函数。主函数首先用输入的两行字符串定义对象a,b，
用缺省构造定义对象c,最后计算c=a+b及c=c-b并分别输出c的值。

题目描述
定义一个字符串类str，该类中包含2个属性，字符串长度和一个char型指针保存字符串内容。
增加以下运算符的重载：+、- 。+运算符表示把2个字符串拼接成一个字符串。
-运算符表示例如a2-a1，则删除a2中出现的a1字符串。
要求如下：
1.实现str类；
2.编写main函数，初始化2个str对象A、B，输出这2个对象相加后的对象C的结果信息。
输出C与B之间相减后的结果信息。
(提示:strstr(char *a,char*b)可以从a字符串中查找出b首次出现的地址)

输入
第1行：输入一个字符串，初始化第一个str对象。
(提示:通过cin. getline(char *,int strCount)可以输入一个字符串到char数组中)
第2行：输入一个字符串，初始化第二个str对象。

输出
第1行：输出两个字符串相加后的长度和字符串。
第2行：输出两个字符串相减后的长度和字符串。

样例输入
i am a 
student!

样例输出
length=15 i am a student!
length=7 i am a 

*/

#include<iostream>
#include<string.h>
using namespace std;

class Str
{
	private:
		int length;
		char *p;
	public:
		Str(){ p=NULL,length=0; }
		Str(char *s)
		{ 
			p = new char[strlen(s)+1];	
			strcpy(p,s);
			length=strlen(s); 
		}
		Str(const Str &obj)
		{
			if(p!=NULL)
 				delete [] p;
 			p=new char[strlen(obj.p)+1];
 			strcpy(p,obj.p);
 			length=obj.length;
		} 
		~Str()
		{
			if(p!=NULL)
				delete [] p;
		}
		friend Str operator + (const Str &s1,const Str &s2)
		{
			Str h;
			h.length = s1.length +s2.length ;
			h.p=new char[h.length+1];
			strcpy(h.p,s1.p);
			strcat(h.p,s2.p);
			return h;
		}
		friend Str operator - (const Str &s1,const Str &s2)
		{
			int a;
			Str h;
			if(strstr(s1.p,s2.p)==NULL)
			{
				h=s1;
			}
			else
			{
				a=strlen(strstr(s1.p,s2.p));
				h.p=new char[strlen(s1.p)-a+1];
				h.length = s1.length -a ;
				for(int i=0;i<h.length;i++)
					h.p[i]=s1.p[i];
			}
			return h;
		}
		void operator = (const Str &obj)
		{
			length=obj.length;
			// cout<<obj.p<<endl;
			if(p==NULL)
 			{ 
  				p=new char[strlen(obj.p)+1];
  				strcpy(p,obj.p);
			}
 			else
 			{
  				delete [] p;
  				p=new char[strlen(obj.p)+1];
  				strcpy(p,obj.p);
				//  cout<<p<<endl;
 			}
		}
		void show()
		{
			cout<<"length="<<length<<' '<<p<<endl;
		}
};

int main()
{
	char str1[20],str2[20];
	cin.getline(str1,sizeof(str1));
	cin.getline(str2,sizeof(str2));
	Str a(str1),b(str2),c;
	c=a+b;
	c.show() ;
	c=c-b;
	c.show() ;
}

