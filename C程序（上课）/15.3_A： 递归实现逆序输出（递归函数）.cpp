/*
�ݹ�ʵ������������ݹ麯����

��Ŀ����
���õݹ麯�����÷�ʽ�����������������ַ������෴˳���ӡ������

����
�ַ������Ⱥ͸��ַ���

���
�������

��������
5
12345

�������
54321

*/

#include<stdio.h>

int length;

bool print(char a[],int index)
{
	if(index+1==length||print(a,index+1)){
		printf("%c",a[index]);
	}
}

int main()
{
	char a[100];
	scanf("%d\n",&length);
	scanf("%s",&a);
	print(a,0);
}
