/*
���� E: �н�����ģ���ࣨ��ģ�壩

��Ŀ����
��д�н�����ģ��BoundArray������������Ԫ���±����ò����±�Խ��ʱ��ֹ�����ִ�У���
�ܹ��洢�������͵����ݡ�Ҫ��ʵ�ֶ������������ķ���sort������������в��ҵķ���search��

����
��һ��������t����ʾ��t����������
�ӵڶ��п�ʼ����ÿ���������������ݡ�
���������������ͣ�I��ʾint��D��ʾdouble��C��ʾchar���������������Ԫ�ظ���
Ȼ������ÿ��Ԫ��
�������Ҫ���ҵ�Ԫ��

���
���������С���������Ԫ��
Ȼ���������Ԫ�صĽ�����ҵ�������±꣬û�ҵ������-1

��������
2
I 2
1 2
2
D 3
3.5 6.2 2.9
2.1

�������
1 2 
1
2.9 3.5 6.2 
-1

����ĿҪ����һ����ģ�壬�����������������ݶ�����󲢵�����Ӧ��Ա����ʵ�ֳ����ܡ�
*/

#include<iostream>
using namespace std;

template <class T>
class BoundArray
{
	private:
		T *value;
		int n;
	public:
		BoundArray(T *a,int b)
		{
			n=b;
			value=new T[n+1];
			for(int i=0;i<n;i++)
				value[i]=a[i];
		}
		void sort()
		{
			T k;
			int i,j;
			for(i=0;i<n-1;i++)
				for(j=0;j<n-1;j++)
					if(value[j]>value[j+1])
					{
						k=value[j];
						value[j]=value[j+1];
						value[j+1]=k;
					}
			for(i=0;i<n;i++)
				cout<<value[i]<<" ";
			cout<<endl;	
		}
		void search(T k)
		{
			int i,find=-1;
			for(i=0;i<n;i++)
				if(value[i]==k)
				{
					find=i;
					break;
				}	
			cout<<find<<endl;
		}
		~BoundArray()
		{
			delete [] value;
		}
};

int main()
{
	int t,n,i;
	char judge;
	cin>>t;
	while(t--)
	{
		cin>>judge>>n;
		if(judge=='I')
		{
			int *a,find;
			a=new int[n+1];
			for(i=0;i<n;i++)
				cin>>a[i];
			BoundArray<int> h(a,n);
			h.sort() ;
			cin>>find;
			h.search(find); 
			delete [] a;
		}
		else if(judge=='D')
		{
			double *a,find;
			a=new double[n+1];
			for(i=0;i<n;i++)
				cin>>a[i];
			BoundArray<double> h(a,n);
			h.sort() ;
			cin>>find;
			h.search(find); 
			delete [] a;
		}
		else if(judge=='C')
		{
			char *a,find;
			a=new char[n+1];
			for(i=0;i<n;i++)
				cin>>a[i];
			BoundArray<char> h(a,n);
			h.sort() ;
			cin>>find;
			h.search(find); 
			delete [] a;
		}
		else 
			cout<<"error"<<endl;
	}
}
