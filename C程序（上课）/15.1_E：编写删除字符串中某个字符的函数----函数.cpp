/*

��дɾ���ַ�����ĳ���ַ��ĺ���----����
ʱ������: 1 Sec  �ڴ�����: 128 MB
�ύ: 1350  ���: 660
[�ύ][״̬][���۰�]
��Ŀ����


���ƺ���del_char

����ԭ��Ϊ void del_char(char *,char),�����Ĺ�����ɾ��aָ����ַ�����ֵΪch���ַ���������ַ���"AscADef"��ɾ��'A'���ַ���Ϊ"scDef"��


����


��Ҫɾ�����ַ�ch

��Ҫ������ַ���


���


�������ַ���


��������

A
AscADef

�������

scDef
*/

#include<stdio.h>
#include<string.h>

void del_char(char* a,char b)
{
	char c[100];
	int l=strlen(a),i,j=0;
	for(i=0;i<l;i++){
		if(a[i]==b){
			j++;
		}else{
			c[i-j]=a[i];
		}
	}
	c[i-j]='\0';
	strcpy(a,c);
}

int main()
{
	char *a=new char[100];
	char b;
	scanf("%c\n",&b);
	gets(a);
	del_char(a,b);
	printf("%s\n",a);
}
