/*
����ĿҪ����CXGraph���++ǰ׺��׺��--ǰ׺��׺�Լ�<<��5����������غ�����
������������Ŀ������ʾ����

��Ŀ����
X��ĸ���ԷŴ����С����Ϊn��X��n=1,3,5,7,9,...,21�������磬3��xͼ�����£�

�ּ���һ��n�У�n>0��������Xͼ����ң�������Կ���Xͼ���ķŴ�����С��
ң������5��������1��show����ʾ��ǰXͼ����2��show++, ��ʾ��ǰXͼ����
�ٷŴ�ͼ����n+2��3��++show���ȷŴ�ͼ����n+2������ʾͼ����
4��show--����ʾ��ǰXͼ��������Сͼ����n-2��5��--show������Сͼ����n-2��
����ʾͼ��������Xͼ���ķŴ����С��1-21֮�䡣n=1ʱ����С�������ã�
n=21ʱ���Ŵ������á�

����CXGraph��ʾXͼ������Ŵ���С����ʾ��������ģ��ң������
�������£������޸ġ��벹��CXGraph��Ķ����ʵ�֡�


����
��һ��n������0��������Xͼ���ĳ�ʼ��С��
�ڶ��У���������
ÿ������һ�У�Ϊshow��show++��show--��--show��++show֮һ����������������Ŀ��

���
��ÿ�������������Ӧ��Xͼ����
 
��������
3
5
show
show++
show++
++show
--show

�������
XXX
 X
XXX

XXX
 X
XXX

XXXXX
 XXX
  X
 XXX
XXXXX

XXXXXXXXX
 XXXXXXX
  XXXXX
   XXX
    X
   XXX
  XXXXX
 XXXXXXX
XXXXXXXXX

XXXXXXX
 XXXXX
  XXX
   X
  XXX
 XXXXX
XXXXXXX

*/

#include<iostream>
#include<cstring>
using namespace std;

class CXGraph
{
	private:
		int n;
	public:
		CXGraph(int n)
		{
			this->n = n;
		}
		CXGraph operator ++ (int)
		{
			CXGraph a(*this);
			if(n<21)
				n+=2;
			return a;
		}
		CXGraph &operator ++ ()
		{
			if(n<21)
				n+=2;
			return *this;
		}
		CXGraph operator -- (int)
		{
			CXGraph a(*this);
			if(n>1)
				n-=2;
			return a;
		}
		CXGraph &operator -- ()
		{
			if(n>1)
				n-=2;
			return *this;
		}
		friend ostream &operator << (ostream & out,const CXGraph & h)
		{
			int k,i,m,j;
			k=h.n/2+1;
			for(i=k;i>0;i--)
			{
				for(j=k-i;j>0;j--)
					cout<<" ";
				for(m=2*i-1;m>0;m--)		
					cout<<"X";
				cout<<endl;
			}
			
			for(i=2;i<=k;i++)
			{
				for(j=k-i;j>0;j--)
					cout<<" ";
				for(m=2*i-1;m>0;m--)
					cout<<"X";
				cout<<endl;
			}
			return out;
		}
};

int main()
{
	int t,n;
	string command;
	
	cin>>n;
	CXGraph xGraph(n);

	cin>>t;
	while(t--)
	{
		cin>>command;

		if(command=="show++")
			cout<<xGraph++<<endl;
		else if(command=="++show")
			cout<<++xGraph<<endl;
    	else if(command=="show--")
			cout<<xGraph--<<endl;
		else if(command=="--show")
			cout<<--xGraph<<endl;
		else if(command=="show")
			cout<<xGraph<<endl; 
	}
	return 0;
}


