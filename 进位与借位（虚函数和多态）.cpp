/*
��λ���λ���麯���Ͷ�̬��

��Ŀ����


ĳСѧ���꼶����ѧ��ʦ�ڽ�ѧ�������Ӽ�������ʱ���֣����ϵ�ͬѧ���Էֳ����࣬
��һ�������ȷ����ɼӼ�������(GroupA)���ڶ��������ȷ����ɼӷ����㣬
�����ڼ���������˵���������ǽ�λ�Ĵ���(GroupB)���������������Ǽӷ��Ľ�λ��
Ҳ�������Ǽ����Ľ�λ(GroupC)������ʾ��Сѧ���꼶��ûѧ��������
������ģ�⵱��ʦ�ڿ�������ĳλͬѧʱ��ͬѧ������Ļش�
ʵ��ʱ���������Ļ����ܣ�
class Group
{
public:
virtual int add(int x, int y)=0;//����ӷ���������
virtual int sub(int x, int y)=0;//���������������
}
������GroupA, GroupB��GroupC�����ɳ���:
����д��������Ҫ������������һ������Groupָ�룬ͨ����ָ��ͳһ�ؽ���add��sub���㡣

����
��һ�б�ʾ���Դ������ӵڶ��п�ʼ��ÿ����������ռһ�У�ÿ�������������£�ѧ�����1Ϊ��һ��ѧ����2Ϊ�ڶ���ѧ����3Ϊ������ѧ��������һ�������ڶ�������

���
�����Ľ��

��������
3
1 79+81
2 81-79
3 183+69

�������
160
12
142

������ĿҪ����ɻ���Group��������GroupA��GroupB��GroupC�Ķ��塣
�������������ݡ��û������ָ��ָ��̬����������󲢵���add��sub��Ա������
*/

#include<iostream>
using namespace std;

class Group
{
	public:
		Group(){}
		virtual int add(int x, int y)=0;
		virtual int sub(int x, int y)=0;
};

class GroupA:public Group
{
	public:
		GroupA(){}
		int add(int x, int y){ return x+y; }
		int sub(int x, int y){ return x-y; }
};

class GroupB:public Group
{
	public:
		GroupB(){}
		int add(int x, int y){ return x+y; }
		int sub(int x, int y)
		{
			int x1,x2,x3,y1,y2,y3,xx,yy,zz;
			x1=x/100;
			x3=x%10;
			x2=(x-x1*100-x3)/10;
			y1=y/100;
			y3=y%10;
			y2=(y-y1*100-y3)/10;
			
			if(x1<y1)
				xx=x1+10-y1;
			else
				xx=x1-y1;
			if(xx<0)
				xx=-1*xx;
			
			if(x2<y2)
				yy=x2+10-y2;
			else
				yy=x2-y2;
			if(yy<0)
				yy=-1*yy;
			
			if(x3<y3)
				zz=x3+10-y3;
			else
				zz=x3-y3;
			if(zz<0)
				zz=-1*zz;
			
			return xx*100+yy*10+zz;
		}
};

class GroupC:public Group
{
	public:
		GroupC(){}
		int add(int x, int y)
		{
			int x1,x2,x3,y1,y2,y3,xx,yy,zz;
			x1=x/100;
			x3=x%10;
			x2=(x-x1*100-x3)/10;
			y1=y/100;
			y3=y%10;
			y2=(y-y1*100-y3)/10;
			xx=x1+y1;
			xx=xx%10;
			yy=x2+y2;
			yy=yy%10;
			zz=x3+y3;
			zz=zz%10;
			return xx*100+yy*10+zz;
		}
		int sub(int x, int y)
		{
			int x1,x2,x3,y1,y2,y3,xx,yy,zz;
			x1=x/100;
			x3=x%10;
			x2=(x-x1*100-x3)/10;
			y1=y/100;
			y3=y%10;
			y2=(y-y1*100-y3)/10;
			
			if(x1<y1)
				xx=x1+10-y1;
			else
				xx=x1-y1;
			if(xx<0)
				xx=-1*xx;
			
			if(x2<y2)
				yy=x2+10-y2;
			else
				yy=x2-y2;
			if(yy<0)
				yy=-1*yy;
			
			if(x3<y3)
				zz=x3+10-y3;
			else
				zz=x3-y3;
			if(zz<0)
				zz=-1*zz;
			
			return xx*100+yy*10+zz;
		}
};

int main()
{
	int t,type,x,y;
	char k;
	Group *p;
	cin>>t;
	while(t--)
	{
		cin>>type>>x>>k>>y;
		if(type==1)
			p=new GroupA();
		else if(type==2)
			p=new GroupB();
		else if(type==3)
			p=new GroupC();
		else 
		{ 	cout<<"error1"<<endl;continue; }
		
		if(k=='+')
			cout<<p->add(x,y)<<endl; 
		else if(k=='-')
			cout<<p->sub(x,y)<<endl;
		else 
			cout<<"error2"<<endl;
		delete p;	
	}

}
