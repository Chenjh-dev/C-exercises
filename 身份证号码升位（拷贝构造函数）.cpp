//身份证号码升位（拷贝构造函数）

//题目描述

//class CDate
//{
//private:
//int year, month, day;
//public:
//CDate(int,int,int);
//bool check(); //检验日期是否合法
//bool isLeap();
//void print();
//};
//class CStudentID
//{
//private:
//char *p_id, *p_name; //身份证号码，姓名
//CDate birthday; //出生日期
//int registered; //登记否
//public:
//CStudentID(char *p_idval, char *p_nameval, CDate &day); //构造函数，若:日期非法;日期与id日期不符;id有非法字符;id不是15位或18位;id是18位但检验码不对,则输出"illegal id"并置registered=0。否则输出对象的属性并置registered=1.
//CStudentID(const CId &r); //拷贝构造函数，若r.p_id为15位则升到18位(加年份的19和校验位)
//bool checked() { return registered; }
//~CStudentId();
//};
//按上述方式定义一个日期类CDate和学生ID类CStudentID。
//身份证第18位校验码的生成方法：
//1、将身份证号码前17位数分别乘以7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2。然后将其相加
//2、将17位数字和系数乘加的和除以11，得到余数。
//3、余数与校验码的对应关系为1,0,X,9,8,7,6,5,4,3,2。也即：如果余数是3，身份证第18位就是9。如果余数是2，身份证的最后一位号码就是X。
//主函数:
//输入测试次数t
//循环t次
//每次循环中首先输入年月日,并定义日期对象
//然后输入姓名和身份证号码,并先用构造函数定义一个CStudentID对象s,若s.checked()为true,则再用s拷贝构造s_copy对象

//输入
//测试数据的组数 t
//第一个出生日期年月日
//第一个姓名,身份证号码
//第二个出生日期年月日
//第二个姓名,身份证号码
//......

//输出
//第一个CStudent对象s的信息
//第一个拷贝构造CStudent对象s_copy输出的信息或者无输出
//第二个CStudent对象s的信息
//第二个拷贝构造CStudent对象s_copy输出的信息或者无输出
//......

//样例输入
//6
//2018 2 29
//张三 440301180229113
//1997 4 30
//李四 440301980808554
//1920 5 8
//王五 530102200508011
//1980 1 1
//赵六 340524198001010012
//1988 11 12
//钱七 1102038811120A4
//1964 11 15
//孙八 432831641115081

//样例输出
//张三 illegal id
//李四 illegal id
//王五 1920年5月8日 530102200508011
//王五 1920年5月8日 53010219200508011X
//赵六 illegal id
//钱七 illegal id
//孙八 1964年11月15日 432831641115081
//孙八 1964年11月15日 432831196411150810

//按题目要求定义CDate类和CStudentID类(不能在成员函数里用cin输入)。
//主函数实现数据的输入、并先用输入的数据构造对象oldid并在构造函数内输出相应的信息，
//接着用oldid调用checked()的结果判断是否用oldid拷贝构造newid实现身份证号码由15位升18位，
//并在拷贝构造函数中输出相关信息。

#include<iostream>
#include<string.h> 
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
 

class CStudentID
{
	private:
		char *p_id, *p_name;
		CDate birthday;
		int registered;
	public:
		CStudentID(char *p_idval, char *p_nameval, CDate &day)
		{
			registered = 1;
			p_id = new char[strlen(p_idval)];
			strcpy(p_id,p_idval);
			p_name = new char[strlen(p_nameval)];
			strcpy(p_name,p_nameval);
			birthday = day;
			if( strlen(p_id) == 15 )//如果是15位                         //判断   日期  非法字符   位数    最后一位 
			{
				if( birthday.Getyear()%100 != (p_id[6]-'0')*10+(p_id[7]-'0') || birthday.Getmonth()%100 != (p_id[8]-'0')*10+(p_id[9]-'0') || birthday.Getday() != (p_id[10]-'0')*10+(p_id[11]-'0') )//     日期 
					 registered=0;
				else
				{
					for(int k=0;k<strlen(p_id);k++)//非法符 
					{
						if(p_id[k]-'0' < 0 || p_id[k]-'0' > 9)
							registered=0;
					}
				}
			}
			else if(strlen(p_id) == 18 )//18位 
			{
				if( birthday.Getyear() != (p_id[6]-'0')*1000+(p_id[7]-'0')*100+(p_id[8]-'0')*10+(p_id[9]-'0') || birthday.Getmonth() != (p_id[10]-'0')*10+(p_id[11]-'0') || birthday.Getday() != (p_id[12]-'0')*10+(p_id[13]-'0') )//日期 
					registered=0;
				else
				{
					for(int k=0;k<strlen(p_id)-1;k++)//非法符 
					{
						if(p_id[k]-'0' < 0 || p_id[k]-'0' > 9 )
							registered=0;
					}
					if(p_id[17] != Judge19(p_id))
						registered=0;
				}
			}
			else
				registered = 0;
			cout<<p_name<<" ";
			if(registered==0)
				cout<<"illegal id"<<endl;
			else
			{
				birthday.print() ;
				cout<<p_id<<endl;
				cout<<p_name<<" ";
				birthday.print() ;
			}
		}
//第七位开始年后两位，9位，十一位，
//换后第七位开始年，11,13
		CStudentID(const CStudentID &r,CDate &p)
		{
			
			int i,k1,k2,m;
			p_id = new char[18];
			p_name = new char[4];
			for(i=0;i<6;i++)
				p_id[i] = r.p_id[i];
			m = p.Getyear() /100;//千百位
			k2 = m % 10;//百位 
			k1 = ( m - k2) / 10 ;//千位 
			p_id[6] = (char)(k1+'0');
			p_id[7] = (char)(k2+'0');
			for(i=8;i<17;i++)
				p_id[i] = r.p_id[i-2];
			p_id[17] = Judge19(p_id);
			cout<<p_id;
			cout<<endl;
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
		bool checked() { return registered; }
		~CStudentID()
		{
			if(p_id != NULL)
				delete [] p_id;
			if(p_name != NULL)
				delete [] p_name;
		}
};

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int x1,x2,x3;
		cin>>x1>>x2>>x3;
		CDate P(x1,x2,x3);
		char k1[4];
		cin>>k1;
		char k2[18];
		cin>>k2;
		if(P.check() )
		{
			CStudentID a(k2,k1,P);
			if(a.checked () )
			{
				CStudentID b(a,P);	
			}
		}
		else
			cout << k1 <<" illegal id"<<endl;
	}
	return 0;
}

