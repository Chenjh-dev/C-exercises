/*
˭��Ʊ����ߣ�����ģ�壩

��Ŀ����
ĳС��ҪƱѡ�򳤣���Ʊ����ߵ�ѡ��������ͶƱ���Ʋ���ȫ��
����ÿ��ͶƱʱ����ѡ����ͶƱϵͳ��ʶ�������Ͳ�һ�¡�
���д����ģ�壬����Զ������͵����ݣ����ҳ���Ʊ��ߵ�Ԫ�ء�
���У�ÿ��ͶƱ��ѡƱ��n�ţ�ʶ��������ΪT
ע�⣺����ʹ��ģ�庯��

����
��һ������t��ʾ��t������ʵ��
�ڶ���������һ����д��ĸ��ʾʶ�������ͣ�I��ʾ�������ͣ�
C��ʾ�ַ��ͣ�S��ʾ�ַ����ͣ�Ȼ������n��ʾ���鳤�ȡ�
����������n������
��������t��ʵ��

���
ÿ�����һ��������ֱ������ѡ�ߵ�ʶ����͵�Ʊ�����Կո�ֿ���

��������
3
I 10
5 3 5 2 9 7 3 7 2 3
C 8
a b a e b e e q
S 5
sandy david eason cindy cindy

�������
3 3
e 3
cindy 2

����ĿҪ����һ������ģ��(���ܶ��������غ���)��������������ʵ�����Ͳ�������֮��
*/

#include<iostream>
using namespace std;

template <class T>
void find(T *a,int n)
{
	int i,j,judge=0,k=0,max=0,*h2;
	T *h1;
	h1 = new T[n+1];
	h2 = new int[n+1];
	for(i=0;i<n;i++)
	{
		for(j=0;j<k;j++)
		{
			if(a[i]==h1[j])
			{
				h2[j]++;
				judge=1;
				break;
			}
		}
		if(judge==0)
		{
			h1[k]=a[i];
			h2[k]=1;
			k++;
		}
		judge=0;
	}
	for(i=0;i<k-1;i++)
	{
		if(h2[max] < h2[i+1])
		{
			max=i+1;
		}
	}
	cout<<h1[max]<<" "<<h2[max]<<endl;
	delete [] h1;
	delete [] h2;
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
			int *a;
			a=new int[n+1];
			for(i=0;i<n;i++)
			{
				cin>>a[i];
			}
			find(a,n);
			delete [] a;
		}
		else if(judge=='C')
		{
			char *a;
			a=new char[n+1];
			for(i=0;i<n;i++)
			{
				cin>>a[i];
			}
			find(a,n);
			delete [] a;
		}
		else if(judge=='S')
		{
			string *a;
			a=new string[n+1];
			for(i=0;i<n;i++)
			{
				cin>>a[i];
			}
			find(a,n);
			delete [] a;
		}
		else
			cout<<"error"<<endl;
	}
}


















