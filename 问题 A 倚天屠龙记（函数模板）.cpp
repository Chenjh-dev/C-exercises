/*
���� A: ���������ǣ�����ģ�壩

��Ŀ����
��������һ�����ԣ�ֻҪ���콣���������а��ص�����ƴ��һ�𣬾��ܵõ������޵е��ڹ����š�
���һ������ģ�壬���ƴ�յĹ��ܣ������콣���������ӵ��������ĺ��棩�������������. 
����ÿ��������n��Ԫ����ɣ�����ΪT��

����
��һ������t��ʾ��t������ʵ��
�ڶ���������һ����д��ĸ��ʾ�������ͣ�I��ʾ�������ͣ�D��ʾ˫���������ͣ�
C��ʾ�ַ��ͣ�Ȼ������n��ʾ���ݸ�����
�������������콣��n������
������������������n������
��������t��ʵ��

���
ÿ�����һ�����

��������
2
I 5
5 3 51 27 9
27 0 0 5 1
C 5
kitty
hello

�������
2700515351279
hellokitty

����ĿҪ����һ������ģ��(���ܶ��������غ���)��������������ʵ�����Ͳ�������֮��
*/

#include<iostream>
using namespace std;

template <class T>
void yitian(T *a,T *b,int n)
{
	T *k;
	int i;
	k=new T[n*2+1];
	for(i=0;i<n;i++)
	{
		k[i]=b[i];
	}
	for(i=0;i<n;i++)
	{
		k[i+n]=a[i];
	}
	for(i=0;i<n*2;i++)
	{
		cout<<k[i];
	}
	cout<<endl;
	delete []k;
}

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
			int *a,*b;
			a=new int[n+1];
			b=new int[n+1];
			for(i=0;i<n;i++)
			{
				cin>>a[i];
			}
			for(i=0;i<n;i++)
			{
				cin>>b[i];
			}
			yitian(a,b,n);	
			delete []a,b;
		}
		else if(judge=='D')
		{
			double *a,*b;
			a=new double[n+1];
			b=new double[n+1];
			for(i=0;i<n;i++)
			{
				cin>>a[i];
			}
			for(i=0;i<n;i++)
			{
				cin>>b[i];
			}
			yitian(a,b,n);
			delete []a,b;	
		}
		else if(judge=='C')
		{
			char *a,*b;
			a=new char[n+1];
			b=new char[n+1];
			for(i=0;i<n;i++)
			{
				cin>>a[i];
			}
			for(i=0;i<n;i++)
			{
				cin>>b[i];
			}
			yitian(a,b,n);	
			delete []a;
			delete [] b;
		}
		else
			cout<<"error"<<endl;
	}
}
