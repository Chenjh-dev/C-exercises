/*
�����������ģ��

��Ŀ����
��дһ������������ݵĺ���ģ��reverse��������������ʵ���鲿�û�����

����
��һ��������Դ���
ÿ�β�������һ�У�������һ����д��ĸ��ʾ��������, I��ʾ���͡�
D��ʾ˫�����͡�S��ʾstring�����ַ�����C��ʾ�������������������ݡ�

���
ÿ�β������һ�У��������е�����

��������
5
I 123456
D -235.172
S thisisatest
C -123 456
C 123 -456

�������
654321
-271.532
tsetasisiht
456-123
-456+123

��ʾ
��������ת�����������������ת��Ϊstring.
ģ�庯���ڲ���������ʾ�ķ����ɽ���ֵ�ͱ���aת����string�ͱ���s:
#include "sstream"
......
ostringstream os;
string s;
os << a;
s = os.str();

����ĿҪ����һ������ģ��(���ܶ��������غ���)��������������ʵ�����Ͳ�������֮��

*/

#include<iostream>
#include<algorithm>
#include "sstream"
using namespace std;

class CC
{
	private:
		int value1;
		int value2;
	public:
		CC(int a,int b)
		{
			value1=a;
			value2=b;
		}
		operator string()
		{
			ostringstream os;
			string s;
			if(value1>0)
			{
				os << value2<<'+'<<value1;
			}
			else	
				os << value2<<value1;
			s = os.str();
			reverse(s.begin(),s.end());
			return s;
		}
};

template <class T>
string reverse(T &k)
{
	int find=0,i;
	ostringstream os;
	string s,m;
	os << k;
	s = os.str();
	if(s[0]!='-')
	{
		reverse(s.begin(),s.end());
		if(s[0]=='0'&&s[1]!='+'&&s[1]!='-')
		{
			for(i=0;i<s.size();i++)
			{
				if(s[i]!='0')
					break;
				else
					find=i;
			}
			s=s.substr(find+1);
		}
	}	
	else
	{
		reverse(s.begin(),s.end());
		s=s.substr(0,s.size()-1);
		if(s[0]=='0'&&s[1]!='+'&&s[1]!='-')
		{
			for(i=0;i<s.size();i++)
			{
				if(s[i]!='0')
					break;
				else
					find=i;
			}
			s=s.substr(find+1);
		}
		s="-"+s; 
	}
	return s;
}

int main()
{
	int t,i;
	char judge;
	cin>>t;
	while(t--)
	{
		cin>>judge;
		if(judge=='I')
		{
			int a;
			cin>>a;
			cout<<reverse(a)<<endl;
		}
		else if(judge=='D')
		{
			double a;
			cin>>a;
			cout<<reverse(a)<<endl;
		}
		else if(judge=='S')
		{
			string a;
			cin>>a;
			cout<<reverse(a)<<endl;
		}
		else if(judge=='C')
		{
			int a,b;
			cin>>a>>b;
			CC k(a,b);
			string h=k;
			cout<<reverse(h)<<endl;
		}
		else
			cout<<"error"<<endl;
	}
}


















