/*
��̬����

��Ŀ����
һ��ʼδ֪���鳤�ȣ�����Ҫ�󴴽���ͬ���͵�ָ�룬
����ʹ��ָ�봴����Ӧ���ȵ����飬Ȼ������ɲ�ͬ��Ҫ��
��Ҫ�󴴽��������飬�����������������ݵ�ƽ��ֵ
��Ҫ�󴴽��ַ����飬�ҳ������ڵ������ĸ
��Ҫ�󴴽����������飬�ҳ��������Сֵ
Ҫ������������̲���ʹ�������±꣬�����鴴������
�뵽�������Ƚϡ����㣬�����������ʹ��ָ��
��ʾ��ʹ��new�ؼ���

����
��һ������t��ʾ��t������ʵ��
�ڶ���������һ����д��ĸ��ʾ�������ͣ�I��ʾ�������ͣ�
C��ʾ�ַ����ͣ�F��ʾ���������ͣ�Ȼ������n��ʾ���鳤�ȡ�
����������n������
��������t��ʵ��

���
ÿ�����ݲ�ͬ���������������Ӧ�Ľ��


��������
3
C 5
A D E B C
I 6
22 55 77 33 88 55
F 4
3.1 1.9 6.5 4.8


�������
E
55
1.9


*/

#include<iostream>
using namespace std;

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
			int *p,total=0;
			p=new int[n+1];
			for(i=0;i<n;i++)
			{
				cin>>p[i];
				total+=p[i];
			}
			cout<<total/n<<endl;
		}
		else if(judge=='C')
		{
			char *p,find='A';
			p=new char[n+1];
			for(i=0;i<n;i++)
			{
				cin>>p[i];
				if(p[i]>find)
					find=p[i];
			}
			cout<<find<<endl;
		}
		else if(judge=='F')
		{
			float *p,min;
			p=new float[n+1];
			cin>>p[0];
			min=p[0];
			for(i=1;i<n;i++)
			{
				cin>>p[i];
				if(p[i]<min)
					min=p[i];
			}
			cout<<min<<endl;
		}
	}
}
