/*
���ֺ����⣨���飬������

��Ŀ����
��������a1��a2��.......an���ж��Ƿ���Դ���ѡ����������
ʹ���ǵĺ�ǡ��Ϊk��

����
�ж���������ݡ�ÿ������������У�
��һ�У�������n������k��n��ʾ���ĸ�����k��ʾ���ĺ͡�
�ڶ��У�n����

���
ÿ��������ݣ������ǡ�ÿ���Ϊk�������YES������������˳��������������ļ������ĺ���ɣ�����NO��

��������
5 20
10 2 4 7 1
4 10
1 2 -10 4

�������
YES
10 2 7 1
NO

*/

#include<stdio.h>

int a[100];

int find(int n,int now,int k,int total){
	if(now==n){
		if(total==k){
			return 1;
		}
		else{
			return 0;
		}
	}
	else if(find(n,now+1,k,total+a[now])){
		return 1;
	}
	else if(find(n,now+1,k,total)){
		a[now]=0;
		return 1;
	}
	return 0;
}

int main()
{
	int i,j,n,k,total;
	while(scanf("%d",&n)!=EOF){
		scanf("%d",&k);
		for(i=0;i<n;i++){
			scanf("%d",&a[i]);
		}
		total=0;
		if(find(n,0,k,0)){
			printf("YES\n");
			for(i=0;i<n-1;i++){
				if(a[i]!=0){
					printf("%d ",a[i]);
				}
			}
			printf("%d\n",a[i]);
		}
		else{
			printf("NO\n");
		}
	}
}
