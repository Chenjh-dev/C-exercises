/*

�����ַ����ĳ���

��Ŀ����
�����ַ���S�ĳ��ȣ�������strlen������ͬ�������ܵ��ÿ⺯��strlen��
���򲻸��֡�������ַ����������ո�

����
�����������t
����ÿ����ԣ������ַ���S������<=30��

���
����ÿ����ԣ����S�ĳ���

��������
1
hehe

�������
4

*/

#include<stdio.h>

int main()
{
	int t,i,length;
	char c;
	scanf("%d\n",&t);
	while(t--){
		length=0;
		scanf("%c",&c);
		while(c!='\n'){
			length++;
			scanf("%c",&c);
		}
		printf("%d\n",length);
	}
}
