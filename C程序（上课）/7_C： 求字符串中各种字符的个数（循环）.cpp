/*
���ַ����и����ַ��ĸ�����ѭ����

��Ŀ����
����һ���ַ����ֱ�ͳ�Ƴ�����Ӣ����ĸ���ո����ֺ������ַ��ĸ�����

����
һ���ַ�

���
ͳ��ֵ

��������
aklsjflj123 sadf918u324 asdf91u32oasdf/.';123

�������
23 16 2 4

*/

#include<stdio.h>

int main()
{
	char c;
	int numA=0,numblank=0,num1=0,numother=0;
	c=getchar();
	while(1){
		if(c=='\n')
			break;
		else if((c>='A'&&c<='Z')||(c>='a'&&c<='z'))
			numA++;
		else if((c>='0'&&c<='9'))
			num1++;
		else if(c==' ')
			numblank++;
		else
			numother++;
		c=getchar();
	}
	printf("%d %d %d %d",numA,num1,numblank,numother);	
}
