//问题 : 学生类定义（类和对象）

//题目描述


//面向对象程序设计的中心就是把客观事物抽象为程序世界里一段段代码，校园里的主体是学生，泛泛的学生包含很多属性，比如姓名、学号、所在学院、专业、性别、住址、联系电话。。。。。。等等，
//有这些属性，需要操纵它们的动作，比如读取姓名、设置姓名、读取学号、设置学号。。。。。。等等，这就是我们课堂说的属性和方法，对于属性和方法，我们又有访问控制方式限制，
//标示为public、private、protected等，根据以上的信息，请给出一个完整的学生类定义：Student，并测试输出n个该类对象的各项属性值。

//输入

//第一行表示要输入n个对象

//后续各行输入不同对象的各属性值，每个对象一行。

//输出

//输出不同对象的各自属性

//每个对象占一行

//样例输入

//2
//WangHai 2014150112 计算机 计算机科学与技术 男 南区215 13760222222
//LiBin 2013151292 计算机 软件工程 男 南区318 13677777777

//样例输出

//WangHai 2014150112 计算机 计算机科学与技术 男 南区215 13760222222
//LiBin 2013151292 计算机 软件工程 男 南区318 13677777777






#include<iostream>
using namespace std;

class student
{
	private :
		string name;
		int No;
		string college;
		string major;
		char sex;
		string address;
		int phone;
	public :
		void set();
};


void main()
{
	int t;
	cin>>t;
	while(t--)
	{
		
	}
}



#include<iomanip>
#include<iostream>
using namespace std;
class Student
{
    private:
		string name,number,faculty,major,sex,addr,tel;//姓名、学号、所在学院、专业、性别、住址、联系电话    
	public:
		void setName(string name);----------
        void setNumber(string number);
        void setFaculty(string faculty);
        void setMajor(string major);
        void setSex(string sex);        
		void setAddr(string addr);        
		void setTel(string tel);        
		string getName();  ----------------      
		string getNumber();        
		string getFaculty();        
		string getMajor();        
		string getSex();        
		string getAddr();        
		string getTel();        
		void setInfo(string name,string number,string faculty,string major,string sex,string addr,string tel);    ----------    
		void ShowInfo();---------------------
};  

		void Student::setName(string na){    name=na;} --------------
		void Student::setNumber(string nu){    number=nu;} 
		void Student::setFaculty(string f){    faculty=f;} 
		void Student::setMajor(string m){    major=m;} 
		void Student::setSex(string s){    sex=s;} 
		void Student::setAddr(string a){    addr=a;} 
		void Student::setTel(string t){    tel=t;} 
		void Student::setInfo(string name,string number,string faculty,string major,string sex,string addr,string tel)------------
		{    
		setName(name);    
		setNumber(number);   	 
		setFaculty(faculty);    
		setMajor(major);    
		setSex(sex);    
		setAddr(addr);    
		setTel(tel);
		} 
		

		string Student::getName()---------------
		{
		    return name;
		} 
		string Student::getNumber()
		{
		    return number;
		} 
		string Student::getFaculty()
		{
		    return faculty;
		} 
		string Student::getMajor()
		{
		    return major;
		} 
		string Student::getSex()
		{
		    return sex;
		} 
		string Student::getAddr()
		{
		    return addr;
		} 
		string Student::getTel()
		{
		    return tel;
		} 
		void Student::ShowInfo()
		{    
		cout<<getName()        <<" "<<getNumber()        <<" "<<getFaculty()        <<" "<<getMajor()        <<" "<<getSex()        <<" "<<getAddr()        <<" "<<getTel()        <<endl;
		} 


		int main()
		{
		    int n,m;    string name,number,faculty,major,sex,addr,tel;    
			cout<<"请输入学生个数：";    
			cin>>n;    
			m=n;    
			Student stu[n];    
			cout<<"请按  姓名、学号、所在学院、专业、性别、住址、联系电话  的顺序输入"<<n<<"个学生的信息\n";     
			while(n--)
			{        
			cin>>name>>number>>faculty>>major>>sex>>addr>>tel;        
			stu[n].setInfo(name,number,faculty,major,sex,addr,tel);    
			}    
			cout<<endl;    
			for(int i=0;i<m;i++)
				stu[i].ShowInfo();     
			return 0;
		}


#include<iomanip>
#include<iostream>
using namespace std;
class Student
{
    private:
		string name,number,faculty,major,sex,addr,tel;//姓名、学号、所在学院、专业、性别、住址、联系电话    
	public:
		void setName(string name);----------
        void setNumber(string number);
        void setFaculty(string faculty);
        void setMajor(string major);
        void setSex(string sex);        
		void setAddr(string addr);        
		void setTel(string tel);        
		string getName();  ----------------      
		string getNumber();        
		string getFaculty();        
		string getMajor();        
		string getSex();        
		string getAddr();        
		string getTel();        
		void setInfo(string name,string number,string faculty,string major,string sex,string addr,string tel);    ----------    
		void ShowInfo();---------------------
};  

		void Student::setName(string na){    name=na;} --------------
		void Student::setNumber(string nu){    number=nu;} 
		void Student::setFaculty(string f){    faculty=f;} 
		void Student::setMajor(string m){    major=m;} 
		void Student::setSex(string s){    sex=s;} 
		void Student::setAddr(string a){    addr=a;} 
		void Student::setTel(string t){    tel=t;} 
		void Student::setInfo(string name,string number,string faculty,string major,string sex,string addr,string tel)------------
		{    
		setName(name);    
		setNumber(number);   	 
		setFaculty(faculty);    
		setMajor(major);    
		setSex(sex);    
		setAddr(addr);    
		setTel(tel);
		} 


		string Student::getName()---------------
		{
		    return name;
		} 
		string Student::getNumber()
		{
		    return number;
		} 
		string Student::getFaculty()
		{
		    return faculty;
		} 
		string Student::getMajor()
		{
		    return major;
		} 
		string Student::getSex()
		{
		    return sex;
		} 
		string Student::getAddr()
		{
		    return addr;
		} 
		string Student::getTel()
		{
		    return tel;
		} 
		void Student::ShowInfo()
		{    
		cout<<getName()        <<" "<<getNumber()        <<" "<<getFaculty()        <<" "<<getMajor()        <<" "<<getSex()        <<" "<<getAddr()        <<" "<<getTel()        <<endl;
		} 


		int main()
		{
		    int n,m;    string name,number,faculty,major,sex,addr,tel;    
			cout<<"请输入学生个数：";    
			cin>>n;    
			m=n;    
			Student stu[n];    
			cout<<"请按  姓名、学号、所在学院、专业、性别、住址、联系电话  的顺序输入"<<n<<"个学生的信息\n";     
			while(n--)
			{        
			cin>>name>>number>>faculty>>major>>sex>>addr>>tel;        
			stu[n].setInfo(name,number,faculty,major,sex,addr,tel);    
			}    
			cout<<endl;    
			for(int i=0;i<m;i++)
				stu[i].ShowInfo();     
			return 0;
		}#include<iomanip>




#include<iostream>
using namespace std;
class Student
{
    private:
		string name; 
	public:
		void setName(string name);----------      
		string getName();----------------      
		void setInfo(string name);----------    
		void ShowInfo();---------------------
};  

		void Student::setName(string na){    name=na;} --------------
		void Student::setInfo(string name)------------
		{    
		setName(name);    
		} 
		string Student::getName()---------------
		{
		    return name;
		} 
		void Student::ShowInfo()--------------
		{    
		cout<<getName()<<endl;
		} 

		int main()
		{
		    int n,m;    
			string name,number,faculty,major,sex,addr,tel;    
			cin>>n;    
			m=n;
			Student stu[n]; 
			while(n--)
			{        
			cin>>name>>number>>faculty>>major>>sex>>addr>>tel;        
			stu[n].setInfo(name,number,faculty,major,sex,addr,tel);    
			}    
			cout<<endl;    
			for(int i=0;i<m;i++)
				stu[i].ShowInfo();     
			return 0;
		}
















