/*
n!��ѭ����

��Ŀ����
����n!�����Ǽ���1*2*3*...*n�ĳ˻���ע��0��=1��

����
n��ֵ

���
n!��ֵ

��������
5

�������
5!=120

*/


#include<stdio.h>

int main()
{
	int n,i,answer=1;
	scanf("%d",&n);
	if(n==0)
		printf("%d!=1",n);
	else{
		for(i=1;i<=n;i++){
			answer*=i;
		}
		printf("%d!=%d",n,answer);
	}
}
