/*
�������д�������ƽ��ֵ�����ĸ���

��Ŀ����
����10�����������ǵ�ƽ��ֵ�����������ƽ��ֵ�����ݵĸ�����

����
10����

���
����ƽ�����ĸ���

��������
1 2 3 4 5 6 7 8 9 10

�������
5

*/

#include<stdio.h>

int main()
{
	int i,number=0,total=0,aver,k[10];
	for(i=0;i<10;i++){
		scanf("%d",&k[i]);
		total+=k[i];
	}
	aver=total/10;
	for(i=0;i<10;i++){
		if(aver<k[i]){
			number++;
		}
	}
	printf("%d\n",number);
} 
