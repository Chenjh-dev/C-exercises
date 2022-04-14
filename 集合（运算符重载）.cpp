/*
���ϣ���������أ�

��Ŀ����
��������һ������ȷ����Ԫ�������ɵ����塣���ϵ������в���������Բ��ȡ�
����A�ͼ���B�Ľ�����������A������B����ͬԪ����ɵļ��ϡ�
����A�ͼ���B�Ĳ��������������ڼ���A�����ڼ���B��Ԫ������ɵļ��ϡ�
����B���ڼ���A����Բ���������A-B��������A��������B��Ԫ����ɵļ��ϡ�
���輯��A={10��20��30}������B={1��10��50��8}����A��B�Ĳ���{10��20��30,1,50,8}��
A��B�Ľ���{10}��B����A����Բ�����{20,30}��
��������������CSet�����԰����������е�Ԫ�ظ���n������ָ��data�洢�����е�Ԫ�ء�
�����У������������������ʽ��������е�Ԫ�ء�
        ����+��������󼯺�A�ͼ���B�Ĳ����������ؽ�����ϡ�
        ����-��������󼯺�B���ڼ���A����Բ����������ؽ�����ϡ�
        ����*��������󼯺�A�ͼ���B�Ľ����������ؽ�����ϡ�
���������뼯��A��B�����ݣ����㼯�ϵĲ���������Բ���
�ɸ�����Ŀ��ΪCSet�������Ҫ�ĳ�Ա������

����
���Դ���
ÿ������������У���ʽ���£�
��һ�У�����A��Ԫ�ظ�����Ԫ��
�ڶ��У�����B��Ԫ�ظ�����Ԫ��

���
ÿ���������������£�
��һ�У�����A
�ڶ��У�����B
�����У�A��B�Ĳ�
�����У�A��B�Ľ�
�����У�B����A����Բ��� �� A����B����Բ����Ĳ�����(A-B)+(B-A)
ÿ��������ݼ��Կ��зָ���

��������
2
3 10 20 30
4 10 1 2 3
5 100 2 3 4 -10
6 -34 12 2 4 90 100

�������
A:10 20 30
B:10 1 2 3
A+B:10 20 30 1 2 3
A*B:10
(A-B)+(B-A):20 30 1 2 3

A:100 2 3 4 -10
B:-34 12 2 4 90 100
A+B:100 2 3 4 -10 -34 12 90
A*B:100 2 4
(A-B)+(B-A):3 -10 -34 12 90

����ĿҪ����CSet�ಢ����+��-��*�������
�������������ݣ�����2��CSet�����������������Ĳ��ͽ��ȼ������㡣

*/

#include<iostream>
#include<string.h>
using namespace std;

class CSet
{
	private:
		int n;
		int *data;
	public:
		CSet(){n=0,data=NULL;}
		void set(int a,int *b)
		{
			n=a;
			data = new int[n+1];
			for(int i=0;i<n;i++)
			{
				data[i]=b[i];
			}
		}
		friend ostream & operator << (ostream &out,const CSet &h)
		{
			for(int i=0;i<h.n;i++)
			{
				out<<h.data[i]<<" ";
			}
			return out;
		}
		CSet operator * (const CSet &h)
		{
			CSet C;
			int k=0,*p;
			p=new int[n];
			for(int i=0;i<n;i++)
			{
				for(int j=0;j<h.n;j++)
				{
					if(data[i]==h.data[j])
					{
						p[k]=data[i];
						k++;
					}
				}
			}
			C.set(k,p);
			return C;
		}
		CSet operator - (const CSet &h)
		{
			CSet K;
			int *p,i,j,k=0,judge=1;
			p=new int[n+1];
			for(i=0;i<n;i++)
			{
				for(j=0;j<h.n;j++)
				{
					if(data[i]==h.data[j])
						judge=0;
				}
				if(judge==1)
				{
					p[k]=data[i];
					k++;
				}
				judge=1;
			}
			K.set(k,p); 
			return K;
		}
		
		CSet operator + (const CSet &h)
		{
			CSet C;
			int *p,i,j,judge=1,k=n;
			p=new int[n+h.n+1];
			for(i=0;i<n;i++)
			{
				p[i]=data[i];
			}
			for(i=0;i<h.n;i++)
			{
				for(j=0;j<n;j++)
				{
					if(h.data[i]==data[j])
						judge=0;
				}
				if(judge==1)
				{
					p[k]=h.data[i];
					k++;
				}	
				judge=1;	
			}
			C.set(k,p);
			return C; 
		}
		~CSet()
		{
			if(data!=NULL)
				delete [] data;
		}
};

int main()
{
	int t,n,i;
	CSet A,B;
	int *a,*b;
	cin>>t;
	while(t--)
	{
		cin>>n;
		a=new int[n+1];
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		A.set(n,a); 
		
		cin>>n;
		b=new int[n+1];
		for(i=0;i<n;i++)
		{
			cin>>b[i];
		}
		B.set(n,b);
		cout<<"A:"<<A<<endl;
		cout<<"B:"<<B<<endl;
		cout<<"A+B:"<<A+B<<endl;
		cout<<"A*B:"<<A*B<<endl;
		cout<<"(A-B)+(B-A):"<<(A-B)+(B-A)<<endl;
		cout<<endl;
		delete []a;
		delete []b;
	}
}















