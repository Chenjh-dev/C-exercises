/*

�����ַ�����������
ʱ������: 1 Sec  �ڴ�����: 128 MB
�ύ: 32  ���: 28
[�ύ][״̬][���۰�]
��Ŀ����


дһ�������������ַ�������

����


�����ַ���

���


���Ӻ���ַ���

��������

123
abc

�������

123abc
*/

#include<stdio.h>
#include<string.h>

void run(char a[],char b[],char c[])
{
	int i;
	for(i=0;i<strlen(a);i++){
		c[i]=a[i];
	}
	for(;i<strlen(a)+strlen(b);i++){
		c[i]=b[i-strlen(a)];
	}
	c[i]='\0';
}

int main()
{
	char a[30],b[30],c[30];
	scanf("%s%s",&a,&b);
	run(a,b,c);
	printf("%s",c);
}
