/*

����Ԫ����������
ʱ������: 1 Sec  �ڴ�����: 128 MB
�ύ: 51  ���: 16
[�ύ][״̬][���۰�]
��Ŀ����


дһ�������������ַ����е�Ԫ����ĸ���Ƶ���һ���ַ�����Ȼ�������

����


һ���ַ���

���


˳��������е�Ԫ����ĸ��aeiuo��

��������

abcde

�������

ae

*/

#include<stdio.h>
#include<string.h>

void copy(char a[],char b[])
{
	int l=strlen(a),i,j=0;
	for(i=0;i<l;i++){
		if(a[i]=='a'||a[i]=='e'||a[i]=='i'||a[i]=='o'||a[i]=='u'){
			b[j++]=a[i];
		}
	}
	b[j]='\0';
}

int main()
{
	char a[30],b[30];
	scanf("%s",&a);
	copy(a,b);
	printf("%s",b);
}
