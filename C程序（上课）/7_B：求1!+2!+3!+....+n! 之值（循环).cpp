/*
��1!+2!+3!+....+n! ֵ֮��ѭ��)

��Ŀ����
��Sn=1!+2!+3!+4!+5!+��+n!ֵ֮������n��һ�����֡�

����
n

���
��

��������
5

�������
153
*/

#include<stdio.h>

int main()
{
	int n,i,j,k,answer=0;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		k=1;
		for(j=1;j<=i;j++){
			k*=j;
		}
		answer+=k;
	}
	printf("%d",answer);
}
