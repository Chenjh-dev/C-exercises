/*

�����ַ���

��Ŀ����
ʵ��strcpy�����Ĺ��ܣ����ַ���S2���Ƹ��ַ���S1�����S1��
������ֱ�ӽ�S2�������ÿ⺯����strcpy�����򲻸���(S1��S2�������ո�)

����
�����������t
����ÿ����ԣ������ַ���S1  S2������<20��

���
����ÿ����ԣ�����ַ���S1

��������
3
shenzhen
guangzhou
yellow
red
morning
night

�������
guangzhou
red
night

*/

#include<stdio.h>

int main()
{
	int t,i,j,L;
	char a[21],b[21];
	scanf("%d\n",&t);
	while(t--){
		i=0;
		do{
			scanf("%c",&a[i]);
			i++;
		}while(a[i-1]!='\n');
		L=i;
		i=0;
		do{
			scanf("%c",&b[i]);
			i++;
		}while(b[i-1]!='\n');
		for(j=0;j<i;j++){
			a[j]=b[j];
		}
		for(;j<L;j++){
			a[j]=' ';
		}
		for(j=0;j<i;j++){
			printf("%c",a[j]);
		}
	}
} 
