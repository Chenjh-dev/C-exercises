//���� : ѧ���ඨ�壨��Ͷ���

//��Ŀ����


//������������Ƶ����ľ��ǰѿ͹��������Ϊ����������һ�ζδ��룬У԰���������ѧ����������ѧ�������ܶ����ԣ�����������ѧ�š�����ѧԺ��רҵ���Ա�סַ����ϵ�绰�������������ȵȣ�
//����Щ���ԣ���Ҫ�������ǵĶ����������ȡ������������������ȡѧ�š�����ѧ�š������������ȵȣ���������ǿ���˵�����Ժͷ������������Ժͷ������������з��ʿ��Ʒ�ʽ���ƣ�
//��ʾΪpublic��private��protected�ȣ��������ϵ���Ϣ�������һ��������ѧ���ඨ�壺Student�����������n���������ĸ�������ֵ��

//����

//��һ�б�ʾҪ����n������

//�����������벻ͬ����ĸ�����ֵ��ÿ������һ�С�

//���

//�����ͬ����ĸ�������

//ÿ������ռһ��

//��������

//2
//WangHai 2014150112 ����� �������ѧ�뼼�� �� ����215 13760222222
//LiBin 2013151292 ����� ������� �� ����318 13677777777

//�������

//WangHai 2014150112 ����� �������ѧ�뼼�� �� ����215 13760222222
//LiBin 2013151292 ����� ������� �� ����318 13677777777






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
		string name,number,faculty,major,sex,addr,tel;//������ѧ�š�����ѧԺ��רҵ���Ա�סַ����ϵ�绰    
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
			cout<<"������ѧ��������";    
			cin>>n;    
			m=n;    
			Student stu[n];    
			cout<<"�밴  ������ѧ�š�����ѧԺ��רҵ���Ա�סַ����ϵ�绰  ��˳������"<<n<<"��ѧ������Ϣ\n";     
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
		string name,number,faculty,major,sex,addr,tel;//������ѧ�š�����ѧԺ��רҵ���Ա�סַ����ϵ�绰    
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
			cout<<"������ѧ��������";    
			cin>>n;    
			m=n;    
			Student stu[n];    
			cout<<"�밴  ������ѧ�š�����ѧԺ��רҵ���Ա�סַ����ϵ�绰  ��˳������"<<n<<"��ѧ������Ϣ\n";     
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
















