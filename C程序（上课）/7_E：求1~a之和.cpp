/*
��1~a֮��

��Ŀ����
�����������ĺ�,����2λС�� 1~a֮�� 1~b��ƽ���� 1~c�ĵ�����

����
a b c

���
1+2+...+a + 1^2+2^2+...+b^2 + 1/1+1/2+...+1/c

��������
100 50 10

�������
47977.93

*/

#include<stdio.h>

int main()
{
	int a,b,c,i;
	float answer=0.0;
	scanf("%d %d %d",&a,&b,&c);
	for(i=1;i<=a;i++){
		answer+=i;
	}
	for(i=1;i<=b;i++){
		answer+=i*i;
	}
	for(i=1;i<=c;i++){
		answer+=1.0/i;
	}
	printf("%.2f\n",answer);
}
