/*

��ȡ�ַ���(����)
ʱ������: 1 Sec  �ڴ�����: 128 MB
�ύ: 194  ���: 59
[�ύ][״̬][���۰�]
��Ŀ����


��дһ������int substr(char str1[],char str2[],int index)���������ǣ������ַ���str1 (���ȳ���30) �ĵ�index���ַ���ʼ�������ַ����ƣ������µ��ַ���str2������ɹ����ɣ���������1��������ܳɹ����ɣ�����0

����


�������ݵ�����n

��һ������

�ڶ�������

........

���


�ɹ����ɾ�����Ӵ������ɹ����ɣ����"IndexError"

��������

3
Zhenshen University
9
www.szu.edu.cn
12
apple
8


�������

University
cn
IndexError

*/

#include<stdio.h>
#include<string.h>

int substr(char str1[],char str2[],int index)
{
	int l=strlen(str1),i,j=0;
	if(l<=index||index<0){
		return 0;
	}
	for(i=index;i<l;i++){
		str2[j++]=str1[i];
	}
	str2[j]='\0';
	return 1;
}

int main()
{
	int n,d;
	char c;
	char a[100],b[100];
	scanf("%d\n",&n); 
	while(n--){
		gets(a);
		scanf("%d",&d);
		c=getchar();
		if(substr(a,b,d)){
			puts(b);
		}else{
			printf("IndexError\n");
		}
	}
}
