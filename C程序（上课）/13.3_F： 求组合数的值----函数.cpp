/*
���������ֵ----����

��Ŀ����
���Ƴ�������m,n(M>=n>=0)��,�������б��ʽ��ֵ�������	   m!         
                                                        _________
                                                        n! (m-n)!
Ҫ�󽫼���׳�����ĺ���дΪfact(n),��������ֵ������Ϊfloat

����
m n

���
��Ӧ���ʽ��ֵ

��������
2 1

�������
2

*/

#include<stdio.h>

float fact(int n)
{
	float a=1;
	int i;
	for(i=2;i<=n;i++){
		a*=i;
	}
	return a;
}

int main()
{
	int m,n,k;
	scanf("%d%d",&m,&n);
	printf("%d",(int)(fact(m)/fact(n)/fact(m-n)));
}
