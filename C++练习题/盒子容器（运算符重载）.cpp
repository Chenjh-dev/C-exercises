/*
������������������أ�

��Ŀ����
������������࣬����4����Ա����š��������ߣ�(�����ڵ��ڿ�)�Ҹú����ݻ���Ϊ���������
����ÿ�������������浹��ˮ���ض��塰-���������ʵ�����һ�����ӷ���
��һ�����������������ˮ����������������ˮ�����������������ı��
�Լ����ˮ�����(��ܰ��ʾ����һ����������������)������������Ļ�����ʽ���£�
class box{
private string num;
private int length;
private int width;
private int height;
��
}

����
��һ������Բ����ĸ���
�ڶ��п�ʼ��������ÿ��Բ����ı�š���������

���
���ˮ��������Բ���������ı���Լ����ˮ�����

��������
3
01 10 10 12
02 12 9 8
03 12 10 8

�������
02���ӷ���03���������ˮ��࣬Ϊ864��

����ĿҪ����CBox�ಢ����-�������
����һ��ȫ�ֺ������������������������ˮ�����������������ı���Լ����ˮ�������
�������������ָ�����飬�������ݣ���̬��������������ȫ�ֺ�����������

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
			if(height>=length)//�������� 
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
	cout<<p[num2].getnum()<<"���ӷ���"<<p[num1].getnum()<<"���������ˮ��࣬Ϊ"<<v1<<"��"<<endl;
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
