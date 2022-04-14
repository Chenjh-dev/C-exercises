//���֤������λ���������캯����

//��Ŀ����

//class CDate
//{
//private:
//int year, month, day;
//public:
//CDate(int,int,int);
//bool check(); //���������Ƿ�Ϸ�
//bool isLeap();
//void print();
//};
//class CStudentID
//{
//private:
//char *p_id, *p_name; //���֤���룬����
//CDate birthday; //��������
//int registered; //�ǼǷ�
//public:
//CStudentID(char *p_idval, char *p_nameval, CDate &day); //���캯������:���ڷǷ�;������id���ڲ���;id�зǷ��ַ�;id����15λ��18λ;id��18λ�������벻��,�����"illegal id"����registered=0�����������������Բ���registered=1.
//CStudentID(const CId &r); //�������캯������r.p_idΪ15λ������18λ(����ݵ�19��У��λ)
//bool checked() { return registered; }
//~CStudentId();
//};
//��������ʽ����һ��������CDate��ѧ��ID��CStudentID��
//���֤��18λУ��������ɷ�����
//1�������֤����ǰ17λ���ֱ����7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2��Ȼ�������
//2����17λ���ֺ�ϵ���˼ӵĺͳ���11���õ�������
//3��������У����Ķ�Ӧ��ϵΪ1,0,X,9,8,7,6,5,4,3,2��Ҳ�������������3�����֤��18λ����9�����������2�����֤�����һλ�������X��
//������:
//������Դ���t
//ѭ��t��
//ÿ��ѭ������������������,���������ڶ���
//Ȼ���������������֤����,�����ù��캯������һ��CStudentID����s,��s.checked()Ϊtrue,������s��������s_copy����

//����
//�������ݵ����� t
//��һ����������������
//��һ������,���֤����
//�ڶ�����������������
//�ڶ�������,���֤����
//......

//���
//��һ��CStudent����s����Ϣ
//��һ����������CStudent����s_copy�������Ϣ���������
//�ڶ���CStudent����s����Ϣ
//�ڶ�����������CStudent����s_copy�������Ϣ���������
//......

//��������
//6
//2018 2 29
//���� 440301180229113
//1997 4 30
//���� 440301980808554
//1920 5 8
//���� 530102200508011
//1980 1 1
//���� 340524198001010012
//1988 11 12
//Ǯ�� 1102038811120A4
//1964 11 15
//��� 432831641115081

//�������
//���� illegal id
//���� illegal id
//���� 1920��5��8�� 530102200508011
//���� 1920��5��8�� 53010219200508011X
//���� illegal id
//Ǯ�� illegal id
//��� 1964��11��15�� 432831641115081
//��� 1964��11��15�� 432831196411150810

//����ĿҪ����CDate���CStudentID��(�����ڳ�Ա��������cin����)��
//������ʵ�����ݵ����롢��������������ݹ������oldid���ڹ��캯���������Ӧ����Ϣ��
//������oldid����checked()�Ľ���ж��Ƿ���oldid��������newidʵ�����֤������15λ��18λ��
//���ڿ������캯������������Ϣ��

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
		cout<<year<<"��"<<month<<"��"<<day<<"�� ";
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
			if( strlen(p_id) == 15 )//�����15λ                         //�ж�   ����  �Ƿ��ַ�   λ��    ���һλ 
			{
				if( birthday.Getyear()%100 != (p_id[6]-'0')*10+(p_id[7]-'0') || birthday.Getmonth()%100 != (p_id[8]-'0')*10+(p_id[9]-'0') || birthday.Getday() != (p_id[10]-'0')*10+(p_id[11]-'0') )//     ���� 
					 registered=0;
				else
				{
					for(int k=0;k<strlen(p_id);k++)//�Ƿ��� 
					{
						if(p_id[k]-'0' < 0 || p_id[k]-'0' > 9)
							registered=0;
					}
				}
			}
			else if(strlen(p_id) == 18 )//18λ 
			{
				if( birthday.Getyear() != (p_id[6]-'0')*1000+(p_id[7]-'0')*100+(p_id[8]-'0')*10+(p_id[9]-'0') || birthday.Getmonth() != (p_id[10]-'0')*10+(p_id[11]-'0') || birthday.Getday() != (p_id[12]-'0')*10+(p_id[13]-'0') )//���� 
					registered=0;
				else
				{
					for(int k=0;k<strlen(p_id)-1;k++)//�Ƿ��� 
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
//����λ��ʼ�����λ��9λ��ʮһλ��
//�������λ��ʼ�꣬11,13
		CStudentID(const CStudentID &r,CDate &p)
		{
			
			int i,k1,k2,m;
			p_id = new char[18];
			p_name = new char[4];
			for(i=0;i<6;i++)
				p_id[i] = r.p_id[i];
			m = p.Getyear() /100;//ǧ��λ
			k2 = m % 10;//��λ 
			k1 = ( m - k2) / 10 ;//ǧλ 
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

