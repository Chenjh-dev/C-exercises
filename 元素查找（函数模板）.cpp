/*
Ԫ�ز��ң�����ģ�壩

��Ŀ����
��дһ���������н��в��ҵĺ���ģ�壬��������Ϊ����n��Ԫ�أ�����ΪT��Ҫ���ҵ�Ԫ��Ϊkey��
ע�⣺����ʹ��ģ�庯��

����
��һ������t��ʾ��t������ʵ��
�ڶ���������һ����д��ĸ��ʾ�������ͣ�I��ʾ�������ͣ�D��ʾ˫���������ͣ�
C��ʾ�ַ��ͣ�S��ʾ�ַ����ͣ�Ȼ������n��ʾ���鳤�ȡ�
����������n������
����������key
��������t��ʵ��


���
ÿ�����һ��������ҵ����key�������еĵڼ���Ԫ�أ���1��ʼ�����Ҳ������0

��������
4
I 5
5 3 51 27 9
27
D 3
-11.3 25.42 13.2
2.7
C 6
a b g e u q
a
S 4
sandy david eason cindy
cindy

�������
4
0
1
4

����ĿҪ����һ������ģ��(���ܶ��������غ���)��������������ʵ�����Ͳ�������֮��

*/

#include<iostream>
using namespace std;

template <class T>
int find(T *a,int n,T c)
{
	int i,judge=0;
	for(i=0;i<n;i++)
	{
		if(a[i]==c)
		{
			judge=1;
			i++;
			break;
		}
	}
	if(judge==1)
		return i;
	else
		return 0; 
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
			int *k,thefind;
			k=new int[n+1];
			for(i=0;i<n;i++)
			{
				cin>>k[i];
			}
			cin>>thefind;
			cout<<find(k,n,thefind)<<endl;
			delete [] k;
		}
		else if(judge=='D')
		{
			double *k,thefind;
			k=new double[n+1];
			for(i=0;i<n;i++)
			{
				cin>>k[i];
			}
			cin>>thefind;
			cout<<find(k,n,thefind)<<endl;	
			delete [] k;
		}
		else if(judge=='C')
		{
			char *k,thefind;
			k=new char[n+1];
			for(i=0;i<n;i++)
			{
				cin>>k[i];
			}
			cin>>thefind;
			cout<<find(k,n,thefind)<<endl;
			delete [] k;	
		}
		else if(judge=='S')
		{
			string *k,thefind;
			k=new string[n+1];
			for(i=0;i<n;i++)
			{
				cin>>k[i];
			}
			cin>>thefind;
			cout<<find(k,n,thefind)<<endl;
			delete [] k;	
		}	
		else 
			cout<<"error"<<endl;
	}
}




















