/*
���ͬʱ������������������ݣ�ѭ����

��Ŀ����
���ָ����Χ�ڵ�ͬʱ������������������ݣ����û�У������Not found��

����
�������ݵ�����n
��һ��ָ�����ݷ�Χ����ʼֵ����ֵֹ
�ڶ���ָ�����ݷ�Χ����ʼֵ����ֵֹ
..........
��n��ָ�����ݷ�Χ����ʼֵ����ֵֹ

���
����÷�Χ��ͬʱ������������������ݣ����û�У����"Not found"

��������
2
100 200
20 50

�������
101
131
151
181
191
Not found

*/

#include<stdio.h>

int main()
{
	int n,start,end,i,judge,tag,n1,n2,n3,j;
	scanf("%d",&n);
	while(n--){
		scanf("%d %d",&start,&end);
		tag=0;
		if(end<=1){
			printf("Not found\n");
			continue;
		}
		if(start<=1){
			start=2;
		}
		for(i=start;i<=end;i++){
			judge=0;
			for(j=2;j<i;j++){//�ж����� 
				if(i%j==0){
					judge=1;
					break;
				}
			}
			if(judge==1){
				continue;
			}
			if(i<10||i<100&&i/10==i%10||i<1000&&i%10==i/100){//�жϻ����� 
				tag=1;
				printf("%d\n",i);
			}
		}
		if(tag!=1){
			printf("Not found\n");
		}
	}
}
