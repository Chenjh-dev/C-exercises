/*

���Լ��----����
ʱ������: 1 Sec  �ڴ�����: 128 MB
�ύ: 182  ���: 155
[�ύ][״̬][���۰�]
��Ŀ����

д�����������ֱ����������������Լ������С�������������������������������������������������ɼ������롣

����

������

���

���Լ�� ��С������

��������

6 15

�������

3 30
*/

#include<stdio.h>

int findmax(int a,int b)
{
	int i,k,m;
	k=a>b?b:a;
	for(i=1;i<=k;i++){
		if(a%i==0&&b%i==0){
			m=i;
		}
	}
	return m;
}

int findmin(int a,int b)
{
	int i,k;
	k=a>b?a:b;
	for(i=k;i%a!=0||i%b!=0;i++){}
	return i;
}

int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	printf("%d %d\n",findmax(a,b),findmin(a,b));
}
