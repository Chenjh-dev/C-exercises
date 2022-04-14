/*
���� D: ������ģ�壨��ģ�壩

��Ŀ����
���һ��������ģ��Matrix��֧�������������͵����ݡ�
Ҫ�����ٰ���2����Ա����������ת�ú���transport���Լ���ӡ�������print
��дmain�������в��ԣ�������ĳ�Ա�������ת�ú������

����
��һ��������t����ʾ��t����������
�ӵڶ��п�ʼ����ÿ���������������ݡ�
���������������ͣ�I��ʾint��D��ʾdouble��C��ʾchar��
����������������m��n���ֱ��ʾ������к���
��������������Ԫ�أ�һ��m�У�ÿ��n������

���
���ת�ú�ľ���

��������
2
I 2 3
1 2 3
4 5 6
C 3 3
a b c
d e f
g h i

�������
1 4
2 5
3 6
a d g
b e h
c f i

����ĿҪ����һ����ģ�壬�����������������ݶ�����󲢵�����Ӧ��Ա����ʵ�ֳ����ܡ�

*/

#include<iostream>
using namespace std;

template <class T>
class Matrix
{
	private:
		int r,c;
		T **p;
	public:
		Matrix(T **k,int a,int b)
		{
			int i,j;
			r=a,c=b;
			p=new T*[a+1];
			for(i=0;i<r;i++)
				p[i]=new T[b+1];
			for(i=0;i<r;i++)
				for(j=0;j<c;j++)
					p[i][j]=k[i][j];
		}
		void transport()
		{
			T **pp;
			int i,j;
			pp=new T*[c+1];
			for(i=0;i<c;i++)
				pp[i]=new T[r+1];
			for(i=0;i<c;i++)
				for(j=0;j<r;j++)
					pp[i][j]=p[j][i];
			for(i=0;i<r;i++)
				delete p[i];
			delete [] p;
			p=pp;
			i=r;
			r=c;
			c=i;
		}
		void print()
		{
			int i,j;
			for(i=0;i<r;i++)
			{
				for(j=0;j<c;j++)
				{
					cout<<p[i][j]<<" ";
				}
				cout<<endl;
			}
		}
		~Matrix()
		{
			for(int i=0;i<r;i++)
				delete p[i];
			delete [] p;
		}
};

int main()
{
	int t,m,n,i,j;
	char judge;
	cin>>t;
	while(t--)
	{
		cin>>judge>>m>>n;
		if(judge=='I')
		{
			int **k;
			k=new int*[m+1];
			for(i=0;i<m;i++)
				k[i]=new int[n+1];
			for(i=0;i<m;i++)
				for(j=0;j<n;j++)
					cin>>k[i][j];
			Matrix<int> h(k,m,n);
			h.transport() ;
			h.print() ;
			for(i=0;i<m;i++)
				delete k[i];
			delete [] k;
		}
		else if(judge=='D')
		{
			double **k;
			k=new double*[m+1];
			for(i=0;i<m;i++)
				k[i]=new double[n+1];
			for(i=0;i<m;i++)
				for(j=0;j<n;j++)
					cin>>k[i][j];
			Matrix<double> h(k,m,n);
			h.transport() ;
			h.print() ;
			for(i=0;i<m;i++)
				delete k[i];
			delete [] k;
		}
		else if(judge=='C')
		{
			char **k;
			k=new char*[m+1];
			for(i=0;i<m;i++)
				k[i]=new char[n+1];
			for(i=0;i<m;i++)
				for(j=0;j<n;j++)
					cin>>k[i][j];
			Matrix<char> h(k,m,n);
			h.transport() ;
			h.print() ;
			for(i=0;i<m;i++)
				delete k[i];
			delete [] k;
		}
		else
			cout<<"error"<<endl;
	}
}
