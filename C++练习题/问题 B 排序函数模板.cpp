/*
������ģ��

��Ŀ����
��дһ����n��Ԫ�ص�������������ĺ���ģ��mysort��
����Ԫ�����Ϳ����ǻ�����������,Ҳ�����ǵ����(���㵽ԭ��ľ���Ƚ�)��
��Ҫ������C++�ṩ��sort����ģ�壩

����
��һ��������Դ���
ÿ�β���������У���1��������һ����д��ĸ��ʾ�������ͣ�I��ʾ�������ͣ�S��ʾ�ַ����ͣ�D��ʾ˫���������ͣ�P��ʾ�㣬�������n��ʾ���鳤�ȡ���2������n�����ݡ�

���
ÿ�β������һ�������Ľ��

��������
4
I 10
15 3 51 27 9 35 78 14 65 8
D 3
-11.3 25.42 13.2
P 6
1.1 2.2 2.4 -6.5 12 32 1.2 1.3 -3.5 0.1 9.2 1.1
S 4
sandy david eason cindy

�������
3 8 9 14 15 27 35 51 65 78 
-11.3 13.2 25.42 
(1.2, 1.3) (1.1, 2.2) (-3.5, 0.1) (2.4, -6.5) (9.2, 1.1) (12.0, 32.0)
cindy david eason sandy

����ĿҪ����һ������ģ��(���ܶ��������غ���)��������������ʵ�����Ͳ�������֮��
*/

#include<iostream>
#include<iomanip>
using namespace std;

template <class T>
void mysort(T *a,int n)
{
	T k;
	int i,j;
	for(i=0;i<n-1;i++)
		for(j=0;j<n-1;j++)
			if(a[j]>a[j+1])
			{
				k=a[j];
				a[j]=a[j+1];
				a[j+1]=k;
			}
	for(i=0;i<n;i++)
		cout<<a[i]<<" ";
	cout<<endl;	
}

class point
{
	private:
		double x;
		double y;
	public:
		point(){}
		void set(double a,double b)
		{
			x=a;
			y=b;
		}
		int operator > (point &k)
		{
			double h1,h2;
			h1=x*x+y*y;
			h2=k.x*k.x+k.y*k.y;
			if(h1>h2)
				return 1;
			else 
				return 0;
		}
		friend ostream & operator << (ostream &out,point k)
		{
			out<<"("<<fixed<<setprecision(1)<<setfill('0')<<k.x<<", "<<k.y<<")";
			return out;
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
			int *a;
			a=new int[n+1];
			for(i=0;i<n;i++)
			{
				cin>>a[i];
			}
			mysort(a,n);
			delete [] a;
		}
		else if(judge=='D')
		{
			double *a;
			a=new double[n+1];
			for(i=0;i<n;i++)
			{
				cin>>a[i];
			}
			mysort(a,n);
			delete [] a;
		}
		else if(judge=='P')
		{
			double k1,k2;
			point *a;
			a=new point[n+1];
			for(i=0;i<n;i++)
			{
				cin>>k1>>k2;
				a[i].set(k1,k2); 
			}
			mysort(a,n);
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
			mysort(a,n);
			delete [] a;
		}
		else 
			cout<<"error"<<endl;
	}
}
