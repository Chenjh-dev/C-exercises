/*

����ĿҪ�����Ľ�����CQuad(�����ݳ�Ա��int��ʾ���Ľ�����)
�������Ľ�һ���㷨������+�����������һ��ȫ�ֺ���ʵ������CQuad��������͡�
�������������ָ�����飬�������ݣ���̬��������������ȫ�ֺ�����������

��Ŀ����
����һ���Ľ��Ƶ��࣬�ض��塰+����ʵ���Ľ��������ۼӡ�

����
��һ����������Ҫ���Ľ������ĸ���
�ڶ��п�ʼ�����������Ľ�����

���
���������Ľ������ۼӵĺ�

��������
3
13
2
21

�������
102
*/

#include<iostream>
using namespace std;

class CQuad
{
	private:
		int n;
	public:
		CQuad(){n=0;}
		void set(int a){n=a;}
		int getn(){return n;}
		CQuad operator + (CQuad &p)
		{
			CQuad a;
			int x1,x2,x3,x4,h1,h2,h;
			x1=n/100;
			x3=n%10;
			x2=(n-x1*100-x3)/10;
			h1=x1*16+x2*4+x3;
			x1=p.n/100;
			x3=p.n%10;
			x2=(p.n-x1*100-x3)/10;
			h2=x1*16+x2*4+x3;
			h=h1+h2;
			x1=h/64;
			h=h%64;
			x2=h/16;
			h=h%16;
			x3=h/4;
			x4=h%4;
			a.set(x1*1000+x2*100+x3*10+x4);
			return a;
		}
};

int find(CQuad *p,int t)
{
	int i;
	CQuad sum;
	for(i=0;i<t;i++)
	{
		sum = sum + p[i];
	}
	return sum.getn();
}

int main()
{
	int i,t,n;
	CQuad *p;
	cin>>t;
	p = new CQuad[t];
	for(i=0;i<t;i++)
	{
		cin>>n;
		p[i].set(n); 
	}
	cout<<find(p,t)<<endl;
	delete [] p;
}
