/*
新旧身份证(继承)

题目描述
按下述方式定义一个日期类CDate和描述15位身份证号的旧身份证类COldID:
class CDate
{
private:
int year, month, day;
public:
CDate(int,int,int);
bool check(); //检验日期是否合法
bool isLeap();
void print();
};
class COldID
{
private:
char *p_id15, *p_name; //15位身份证号码，姓名 
CDate birthday; //出生日期
public:
COldID(char *p_idval, char *p_nameval, CDate &day);
bool check(); //验证15位身份证是否合法
void print();
~COldID();
};
然后以COldID为基类派生18位身份证号的新身份证类CNewID,并增加3个数据成员:
p_id18(18位号码)、issueday(签发日期)和validyear(有效期，年数)，并重新定义check()和print()。
身份证第18位校验码的生成方法：
1、将身份证号码前17位数分别乘以7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2。然后将其相加。
2、将17位数字和系数乘加的和除以11，得到余数。
3、余数与校验码的对应关系为1,0,X,9,8,7,6,5,4,3,2。也即：如果余数是3，
身份证第18位就是9。如果余数是2，身份证的最后一位号码就是X。
主函数定义一个派生类对象，并用派生类对象调用check()，若返回false则输出“illegal id”
否则调用print()输出身份证信息。check()对身份证合法性进行验证的规则：
1. 确认15位身份证正确.
2. 确认18位号码是从15位号码扩展的，且第18位校验码正确.
3. 身份证中的出生日期合法.
4. 身份证号码中不含非法字符.
5. 身份证号码的长度正确.
6. 身份证目前处于有效期内. (2017年5月10日）

输入
测试数据的组数 t
第一个人姓名、出生日期年月日、15位身份证号码、18位身份证号码、签发日期年月日、有效期(100年按长期处理)
第二个人姓名、出生日期年月日、15位身份证号码、18位身份证号码、签发日期年月日、有效期(100年按长期处理)
......

输出
第一个人姓名
第一个人18位身份证号信息(号码、签发日期和有效期）或"illegal id"
第二个人姓名
第二个人18位身份证号信息(号码、签发日期和有效期）或"illegal id"
......

样例输入
10
AAAA 1988 2 28 440301880228113 440301198802281133 2006 1 20 20
BBBB 1997 4 30 440301980808554 440301199808085541 2015 2 2 10 
CCCC 1920 5 8 530102200508011 53010219200508011X 1980 3 4 30
DDDD 1980 1 1 340524800101001 340524198001010012 1998 12 11 20
EEEE 1988 11 12 110203881112034 110203198811120340 2007 2 29 20 
FFFF 1964 11 15 432831641115081 432831196411150810 2015 8 7 100
GGGG 1996 12 10 44030196121010 44030119961210109 2014 6 7 20
HHHH 1988 7 21 440301880721X12 44030119880721X122 2006 5 11 20
IIII 1976 3 30 440301760330098 440301197603300983 2003 4 15 20
JJJJ 1955 9 5 440301550905205 440301195509051052 2004 6 4 100 

样例输出
AAAA
440301198802281133 2006年1月20日 20年
BBBB
illegal id
CCCC
illegal id
DDDD
illegal id
EEEE
illegal id
FFFF
432831196411150810 2015年8月7日 长期
GGGG
illegal id
HHHH
illegal id
IIII
illegal id
JJJJ
illegal id

按题目要求定义CDate、COldID(身份证号码为15位)和派生类CNewID(身份证号码为18位)。
主函数输入数据、定义CNewID对象并调用其check成员函数判断输入的身份证信息是否合法。
*/

#include<iostream>
#include<cstring>
using namespace std;

class CDate
{
	private:
		int year, month, day;
public:
	CDate(){}
	CDate(int x1,int x2,int x3)
	{
		year = x1;
		month = x2;
		day = x3;
	}
	bool check()
	{
		if( year <= 0 || month <=0 || month >12 || day <= 0 || day >31 )
			return 0;
		else 
		{
			if( month==4 || month== 6 || month==9 || month==11 )
			{
				if(day>30)
					return 0;
				else
					return 1;
			}
			else if( month == 2 )
			{
				if(isLeap())
				{
					if( day >29 )
						return 0;
					else
						return 1;
				}
				else if( day >28 )
					return 0;
				else 
					return 1;
			}
			else 
				return 1;
		}
	}
	bool isLeap()
	{
		if(( year%4 == 0 && year%100 != 0) || year%400 == 0)
			return 1;
		else 
			return 0;
	}
	int Getyear(){return year;}
	int Getmonth(){return month;}
	int Getday(){return day;}
	void print()
	{
		cout<<year<<"年"<<month<<"月"<<day<<"日 ";
	}
};

class COldID
{
	protected:
		char *p_id15, *p_name; //15位身份证号码，姓名
		CDate birthday; //出生日期
	public:
		COldID(char *p_idval, char *p_nameval, CDate &day)
		{
			p_id15 = new char[strlen(p_idval)];
			strcpy(p_id15,p_idval);
			p_name = new char[strlen(p_nameval)];
			strcpy(p_name,p_nameval);
			birthday = day;
			print(); 
		}
		bool check15() //验证15位身份证是否合法
		{
			if(birthday.check() == 0 )
				return 0;
			if(strlen(p_id15) != 15)
				return 0;
			if( birthday.Getyear()%100 != (p_id15[6]-'0')*10+(p_id15[7]-'0') || birthday.Getmonth()%100 != (p_id15[8]-'0')*10+(p_id15[9]-'0') || birthday.Getday() != (p_id15[10]-'0')*10+(p_id15[11]-'0') )//     日期 
					 return 0;
			else
			{
				for(int k=0;k<strlen(p_id15);k++)//非法符 
				{
					if(p_id15[k]-'0' < 0 || p_id15[k]-'0' > 9)
						return 0;
				}
				return 1;
			}
		}
		void print(){ cout<<p_name<<endl; }
		~COldID()
		{
			if(p_id15 != NULL)
				delete [] p_id15;
			if(p_name != NULL)
				delete [] p_name;
		}
};

class CNewID:public COldID
{
	private:
		char *p_id18;
	public:
		CNewID(char name[10],CDate k1,char id1[15],char id2[18]):COldID(id1,name,k1)
		{
			p_id18 = new char[strlen(id2)];
			strcpy(p_id18,id2);
		}
		char Judge19(char *r)
		{
			int a;
			a = (r[0]-'0')*7+(r[1]-'0')*9+(r[2]-'0')*10+(r[3]-'0')*5+(r[4]-'0')*8+(r[5]-'0')*4+(r[6]-'0')*2+(r[7]-'0')*1+(r[8]-'0')*6+(r[9]-'0')*3+(r[10]-'0')*7+(r[11]-'0')*9+(r[12]-'0')*10+(r[13]-'0')*5+(r[14]-'0')*8+(r[15]-'0')*4+(r[16]-'0')*2;
			a = a%11 ;
			switch(a)
			{
				case 0:return '1';break;
				case 1:return '0';break;
				case 2:return 'X';break;
				case 3:return '9';break;
				case 4:return '8';break;
				case 5:return '7';break;
				case 6:return '6';break;
				case 7:return '5';break;
				case 8:return '4';break;
				case 9:return '3';break;
				case 10:return '2';break;
				default:return 'M';break;
			}
		}
		bool check(CDate &h,int time)
		{
			int i;
			if(h.check() == 0)
				return 0;
			for(i=0;i<6;i++)
			{
				if(p_id15[i]!=p_id18[i])
					return 0;
			}
			for(i=14;i<17;i++)
			{
				if(p_id15[i-2]!=p_id18[i])
					return 0;
			}
			if( check15() !=1 )
				return 0;
			if(strlen(p_id18) != 18 )
				return 0;
			if( birthday.Getyear() != (p_id18[6]-'0')*1000+(p_id18[7]-'0')*100+(p_id18[8]-'0')*10+(p_id18[9]-'0') || birthday.Getmonth() != (p_id18[10]-'0')*10+(p_id18[11]-'0') || birthday.Getday() != (p_id18[12]-'0')*10+(p_id18[13]-'0') )//日期 
					return 0;
			else
			{
				for(int k=0;k<strlen(p_id18)-1;k++)//非法符 
				{
					if(p_id18[k]-'0' < 0 || p_id18[k]-'0' > 9 )
						return 0;
				}
				if(p_id18[17] != Judge19(p_id18))
					return 0;
			}
			if(time==100)
				return 1;
			if(h.Getyear() + time > 2017 )//2017年5月10日
				return 1;
			else if(h.Getyear() + time == 2017 )
			{
				if(h.Getmonth() > 5 || (h.Getmonth()==5 && h.Getday()>10) )
					return 0;
				else 
					return 1;
			}
			else 
				return 0;
		}
		void print()
		{
			cout<<p_id18<<" ";
		}
		~CNewID()
		{
			if(p_id18 != NULL)
				delete [] p_id18;
		}
};

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		char name[10],id1[15],id2[18];
		int a1,a2,a3,b1,b2,b3,time;
		cin>>name>>a1>>a2>>a3>>id1>>id2>>b1>>b2>>b3>>time;
		CDate k1(a1,a2,a3),k2(b1,b2,b3);
		CNewID h1(name,k1,id1,id2);
		if(h1.check(k2,time)) 
		{
			h1.print() ;
			k2.print() ;
			if(time==100)
				cout<<"长期"<<endl;
			else
				cout<<time<<"年"<<endl; 
		}	
		else
			cout<<"illegal id"<<endl;
	}
}
