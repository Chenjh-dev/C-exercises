//�������(�������캯��)

//��Ŀ����
//�����Ϊһ�ֶ���Ҳ������������������������԰���������ơ�����(�ֱ���O��T��B��ʾԭ�桢���ð滹�Ǳ���)��
//��Ч��������(��CDate���Ӷ����ʾ)�ʹ洢����(�ֱ���D��H��U��ʾ���̡����̺�U��)�ȡ�
//���������ͨ���������캯����ʵ�֣���ʱ�ڿ������캯����������͸ĳɡ�B��, �洢���ʸ�Ϊ"H"���������䡣
//����ɸ���Ŀ������졢����ʹ�ӡ(������2015��4��7��������Ч�ڻ��ж����죬�Ƿ����)��Ա������ʵ�֡�
//�����������Ч��ֹ������0��0��0�գ���ʾ���������ƣ�Ϊunlimited��������������2015��4��7��֮ǰ�����ǹ��ڣ���ʾΪexpired��
//�������������2015��4��7��֮������ʾ֮���ʣ�����������������Ϣ�����������

//��CDate���ʵ�֣�
// class CDate
// {
// private:
//     int year, month, day;
// public:
//     CDate(int y, int m, int d) { year = y; month = m; day = d; }
//     bool isLeapYear() { return (year%4 == 0 && year%100 != 0) || year%400 == 0; }
//     int getYear() { return year; }
//    int getMonth() { return month; }
//     int getDay() { return day; }
//     int getDayofYear()         //�������ڴӵ���1��1�����������
//    {
//     int i, sum=day; 
//     int a[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
//     int b[13]={0,31,29,31,30,31,30,31,31,30,31,30,31};

//        if (isLeapYear())
//             for(i=0;i<month;i++)   sum +=b[i];
//         else
//             for(i=0;i<month;i++)   sum +=a[i];

//         return sum;
//     }
// };


//����
//�������ݵ����� t
//��һ���������
//��һ���������  ��һ�������������  ��һ�������Ч���� �� ��
//�ڶ����������
//�ڶ���������� �ڶ�������������� �ڶ��������Ч���� �� ��
//......

//���
//name: ��һ���������
//type: ��һ���������
//media: ��һ�������������
//��һ�����2015-4-7�����Ч����

//name: ��һ���������
//type: backup
//media: hard disk
//��һ�����2015-4-7�����Ч����
//......

//��������
//3
//Photoshop_CS5
//O D 0 0 0
//Audition_3.0
//B U 2015 2 3
//Visual_Studio_2010
//T H 2015 5 5

//�������
//name:Photoshop_CS5
//type:original
//media:optical disk
//this software has unlimited use

//name:Photoshop_CS5
//type:backup
//media:hard disk
//this software has unlimited use

//name:Audition_3.0
//type:backup
//media:USB disk
//this software has expired

//name:Audition_3.0
//type:backup
//media:hard disk
//this software has expired

//name:Visual_Studio_2010
//type:trial
//media:hard disk
//this software is going to be expired in 28 days

//name:Visual_Studio_2010
//type:backup
//media:hard disk
//this software is going to be expired in 28 days

//����ĿҪ�������CSoftware�Ķ��塣������ʵ�����ݵ����롢
//���ù��캯������һ���������øö��󿽱�����һ������
//�ֱ���������������ô�ӡ��Ա������������Ϣ��

#include<iostream>
using namespace std;

class CDate
{
 	private:
	   	int year, month, day;
 	public:
 		CDate(){}
   	  	CDate(int y, int m, int d) { year = y; month = m; day = d; }
 	    bool isLeapYear() { return (year%4 == 0 && year%100 != 0) || year%400 == 0; }
   		int getYear() { return year; }
     	int getMonth() { return month; }
		int getDay() { return day; }
    	int getDayofYear()    
    	{
     	 	int i, sum=day; 
   	 	 	int a[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
    		int b[13]={0,31,29,31,30,31,30,31,31,30,31,30,31};

     		if (isLeapYear())
       	    	for(i=0;i<month;i++)   sum +=b[i];
   		    else
    		    for(i=0;i<month;i++)   sum +=a[i];

		 	return sum;
   		}
};

class CSoftware
{
	private:
		char *name;
		char type;
		char media;
		int use;
		CDate k;
	public:
		CSoftware(){}
		CSoftware(char x1[20],char x2,char x3)
		{
			name = new char[20];
			name = x1;
			type = x2;
			media = x3;		
		}
		void Setuse(CDate p)
		{
			k = p;
			use = k.getDayofYear() - 97;
		}
		CSoftware(const CSoftware &r)
		{
			name = r.name ;
			type = 'B' ;
			media = 'H';
			use = r.use ;
		}
		void printf()
		{
			cout << "name:" << name << endl;
			if(type == 'O')
				cout << "type:original" << endl;
			else if(type == 'T')
				cout << "type:trial" << endl;
			else if(type == 'B')
				cout << "type:backup" << endl;
			if(media == 'D')
				cout << "media:optical disk" << endl;
			else if(media == 'H')
				cout << "media:hard disk" << endl;
			else if(media == 'U')
				cout << "media:USB disk" << endl;
			if(use == -97)
				cout << "this software has unlimited use" << endl;
			else if(use <= 0)
				cout << "this software has expired" <<endl;
			else
			cout << "this software is going to be expired in " << use << " days" << endl;
			cout<<endl;
		}
};	

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		char a[20],b,c;
		int k1,k2,k3;
		cin>>a>>b>>c>>k1>>k2>>k3;
		CDate p(k1,k2,k3);
		CSoftware x1(a,b,c);
		x1.Setuse(p)  ;
		CSoftware x2(x1);
		x1.printf() ;
		x2.printf() ;
	}
	return 0;
}



