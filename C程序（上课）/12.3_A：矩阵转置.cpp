/*
����ת��

��Ŀ����
��������A�����A��ת�þ���

����
����n,m��ʾ����A��n�У�m��
����������n�У�ÿ��m������n<10,m<10��

���
���m�У�ÿ��n����

��������
2 2
1 2
2 1

�������
1 2
2 1

*/

#include<stdio.h>

int main()
{
	int i,j,n,m,a[20][20];
	scanf("%d %d",&n,&m);
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			scanf("%d",&a[i][j]);
		}
	}
	for(i=0;i<m;i++){
		for(j=0;j<n-1;j++){
			printf("%d ",a[j][i]);
		}
		printf("%d\n",a[j][i]);
	}
}


