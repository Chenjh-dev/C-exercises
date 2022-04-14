/*
���������㣨��������أ�

��Ŀ����
�����������CBigInteger�������֧��1000λ�������ݳ�ԱΪһ���ַ�ָ�롣
��Ա��������Ԫ����������
1�����ι��캯����Ϊ�ַ�ָ�붯̬����1001���ַ��ռ䡣���ݲ�����ʼ����������
2)  �޲ι��캯����Ϊ�ַ�ָ�붯̬����1001���ַ��ռ䡣
3�����������+��ʵ�������������ļӷ���
4�����������-��ʵ�������������ļ�����
5�����������*��ʵ�������������ĳ˷���
6���������룬�����������
7����������������������
8�������������ͷŷ���Ŀռ䡣�ú����������Ρ�
�������������������ɴ������ļӡ������ˡ��������������£������޸ġ�

����
���Դ���
ÿ���������һ�У� ������1 ����� ������2

���
��ÿ���������������ʽ�ͼ������������ʽ��������

��������
3
100 * -100
-123456789 + 123456
0001 - -123

�������
100 * (-100) = (-10000)
(-123456789) + 123456 = (-123333333)
1 - (-123) = 124

����ĿҪ�����������CBigInteger�����ַ����������Ԫ�ر�ʾ��������ÿһλ��
������+��-��*��<<��>>�������������������Ŀ������ʾ����

*/

#include<iostream>
#include<cstring>
#include<stdio.h>
#include<math.h>
using namespace std;

class CBigInteger
{
	private:
		char *p;
	public:
		CBigInteger(char *h)
		{
			p=new char[strlen(h)+1];
			strcpy(p,h);
		}
		CBigInteger(){p=new char[1001];}
		long long changenum(char *h)
		{
			int i,l=strlen(h);
			long long a=0;
			if(h[0]!='-')
			{
				for(i=0;i<l;i++)
				{
					a+=(h[i]-'0')*pow(10,l-i-1); 
				}
			}
			else
			{
				for(i=1;i<l;i++)
				{
					a+=(h[i]-'0')*pow(10,l-i-1); 
				}
				a*=-1;
			}
			return a;
		}
		char* changechar(long long a)
		{
			char *b;
			b=new char[1001];
			sprintf(b,"%lld",a);
			return b;
		}
		CBigInteger operator + (CBigInteger &h)
		{
			char *a;
			long long x1,x2,xx;
			x1=changenum(p);
			x2=changenum(h.p);
			xx=x1+x2;
			a = changechar(xx);
			CBigInteger k(a);
			return k;
		}
		CBigInteger operator - (CBigInteger &h)
		{
			char *a;
			long long x1,x2,xx;
			x1=changenum(p);
			x2=changenum(h.p);
			xx=x1-x2;
			a = changechar(xx);
			CBigInteger k(a);
			return k;
		}
		CBigInteger operator * (CBigInteger &h)
		{
			char *a;
			long long x1,x2,xx;
			x1=changenum(p);
			x2=changenum(h.p);
			xx=x1*x2;
			a = changechar(xx);
			CBigInteger k(a);
			return k;
		}
		friend istream & operator >> (istream &in,CBigInteger &h )
		{
			in>>h.p ;
			return in;
		}
		friend ostream & operator << (ostream & out,const CBigInteger &h )
		{
			int i,l=strlen(h.p),k=0;
			if(h.p[0]!='-')
				for(i=0;i<l;i++)
				{
					if(k==0&&i!=l-1)
					{
						if(h.p[i]!='0')
						{
							k=1;
							cout<<h.p[i];
						}
					}
					else
					{
						cout<<h.p[i];
					}
				}
			else
			{
				cout<<"(";
				for(i=0;i<l;i++)
				{
					if(k==0&&i!=l-1)
					{
						if(h.p[i]!='0')
						{
							k=1;
							cout<<h.p[i];
						}
					}
					else
					{
						cout<<h.p[i];
					}
				}
				cout<<")";
			}	
			return out;
		}
		~CBigInteger()
		{
			if(p!=NULL)
				delete [] p;
		}
};

int main()
{
	int t;
	char op;
	CBigInteger bigNum1;
	CBigInteger bigNum2;
	
	cin>>t;
	while(t--)
	{
		cin>>bigNum1>>op>>bigNum2;
		cout<<bigNum1<<" "<<op<<" "<<bigNum2<<" = ";
		if(op=='+')
			cout<<bigNum1+bigNum2<<endl;
		else if(op=='-')
			cout<<bigNum1-bigNum2<<endl;	
		else if(op=='*')
			cout<<bigNum1*bigNum2<<endl;
	}
	return 0;
}



















