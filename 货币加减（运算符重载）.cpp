/*

��Ŀ����
����CMoney�࣬����Ԫ���ǡ����������ݳ�Ա����Ԫ�������ء�+����'-'��
ʵ�ֻ��ҵļӼ����㣨����a-b��a�Ľ��ʼ�մ��ڵ���b�Ľ���
�������롢�����ʵ�ֻ��ҵ����룬�����
��������Ļ���ֵ�����䲻�Ͻ��мӡ�����������������
�ɸ�����Ҫ��ΪCMoney����ӹ��캯����������Ա������

����
���Դ���
ÿ��������ݸ�ʽ���£�
��һ�У���ʼ���ң�Ԫ �� ��
�ڶ��п�ʼ��ÿ��һ��������add Ԫ �� �֣��ӣ���minus Ԫ �� �֣�������stop��������

���
��ÿ��������ݣ����������ֹ��Ļ��ҽ����������ʽ��������
 
��������
2
0 0 0
add 48 9 0
minus 0 5 3
add 18 6 8
add 12 1 2
stop
10 2 5
add 5 8 0
add 32 1 2
minus 10 5 9
minus 37 5 8
stop

�������
79Ԫ1��7��
0Ԫ0��0��

����ĿҪ������Ԫʵ��CMoney���+��-��>>��<<��������غ�����
������������ȱʡ��ʽ����2������a,b,֮����cin>>a�����1���������ݡ�
��cin >> cmd >> b�����������Ͷ���b,������cmd���a��b�ļӼ�����
����cout<<a���������a����������
*/

#include <iostream>
#include<cstring>
using namespace std;

class CMoney
{
	private:
		int yuan,jiao,fen;
	public:
		CMoney(){}
		CMoney operator + (const CMoney &b)
		{
			yuan+=b.yuan ;
			jiao+=b.jiao ;
			fen+=b.fen ;
			if(fen>10)
			{
				fen-=10;
				jiao++;
			}
			if(jiao>10)
			{
				jiao-=10;
				yuan++;
			}
		}
		CMoney operator - (const CMoney &b)
		{
			yuan-=b.yuan ;
			jiao-=b.jiao ;
			fen-=b.fen ;
			if(fen<0)
			{
				fen+=10;
				jiao--;
			}
			if(jiao<0)
			{
				jiao+=10;
				yuan--;
			}
		}
		friend istream & operator >> (istream &in,CMoney &a)
		{
			in >> a.yuan >> a.jiao >> a.fen;
			return in;
		} 
		friend ostream & operator << (ostream & out,const CMoney &a)
		{
			cout<<a.yuan <<"Ԫ"<<a.jiao <<"��"<<a.fen <<"��";
			return out;
		}
};

int main()
{
	int t,x1,x2,x3;
	CMoney a,b;
	string cmd;
	cin>>t;
	while(t--)
	{
		cin>>a;
		cin>>cmd>>b;
		while(1)
		{
			if(cmd=="add")
				a+b;
			else if(cmd=="minus")
				a-b;
			cin>>cmd;
			if(cmd=="stop")
				break;
			else
				cin>>b;
		}
		cout<<a<<endl;
	}
}


