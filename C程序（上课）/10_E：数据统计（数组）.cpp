/*
����ͳ�ƣ����飩

��Ŀ����
����n������n�����������������Ϣ�ļ��㣺
1��ͳ�ƴ���ƽ���������ָ�����С��ƽ���������ָ����� 
2��ͳ�������������ָ����� 
3��ͳ�Ƹ����������ָ����� 
4������n���������ֵ����Сֵ��

����
���Դ���T
ÿ���������һ�У����ָ���n(1<n<31)�����n������

���
��ÿ��������ݣ�������У�
��һ�������ƽ������������λС����  ����ƽ���������ָ���  С��ƽ���������ָ���
�ڶ������������������ ����������
��������������ֵ ��Сֵ��
ÿ�����ݵ�����Կ��зָ������������ʽ��������

��������
2
10 -10 20 67 2 0 12 56 1 9 8
5 -1 -2 1 2 5

�������
16.50 3 7
8 1
max=67 min=-10

1.00 2 2
3 2
max=5 min=-2

*/

#include<stdio.h>

int main()
{
	int total,bignum,smallnum,posnum,negnum,max,min,i,j,k,T,n,a[30];
	float aver;
	scanf("%d",&T);
	while(T--){
	
		total=0,bignum=0,smallnum=0,posnum=0,negnum=0;
		
		scanf("%d",&n);
		for(i=0;i<n;i++){
			scanf("%d",&a[i]);
			total+=a[i];
			if(a[i]>0){
				posnum++;
			}
			else if(a[i]<0){
				negnum++;
			}
		}
		aver=total*1.0/n;
		max=a[0],min=a[0];
		
		for(i=0;i<n;i++){
			if(a[i]*n>total){
				bignum++;
			}
			else if(a[i]*n<total){
				smallnum++;
			}
			if(a[i]>max){
				max=a[i];
			}
			if(a[i]<min){
				min=a[i];
			}
		}
		printf("%.2f %d %d\n",aver,bignum,smallnum);
		printf("%d %d\n",posnum,negnum);
		printf("max=%d min=%d\n\n",max,min);
	}
}
