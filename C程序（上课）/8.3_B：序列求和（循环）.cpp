/*
������ͣ�ѭ����

��Ŀ����
��һ�������У� 2/1 3/2 5/3 8/5 13/8 21/13...... 
���������е�ǰN��֮�ͣ�������λС����

����
N

���
����ǰN���

��������
10

�������
16.48

*/

#include<stdio.h>

int main()
{
	float fz=2,fm=1,answer=0,k;
	int N;
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		answer+=fz/fm;
		k=fm;
		fm=fz;
		fz+=k;
	}
	printf("%.2f",answer);
}
