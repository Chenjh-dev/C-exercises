/*
ѧ���ɼ�����ϵͳ - I

��Ŀ����
����һѧ������ϵͳ������N��ѧ��������ѧ���ɼ���
����Ҫ�ش�Q��������
��Щѯ�ʰ�����ƽ��ֵ�������ֵ������Сֵ���ı�ĳ��ͬѧ�ĳɼ�

����
���������ж���
����ĵ�һ������һ������T�������������
ÿ��������ݵ�һ������������N, M  (1 <= N <= 100, 1 <= M <= 100)
������N������N��ѧ���������ͳɼ�����֤ÿ��ͬѧ������������ͬ�ҳ��Ȳ�����20���ɼ����ǷǸ�����
������M������M����������Щ�����ĸ�ʽ������
QUERY_AVERAGE: ��ƽ��ֵ���������1λС��
QUERY_MAX: �����ֵ
QUERY_MIN: ����Сֵ
CHANGE index score: ���������������±�Ϊindex���±��1��ʼ����ͬѧ�ĳɼ��޸�Ϊscore�����뱣֤�Ϸ�

���
����ÿ���������
�������е�ÿ��ѯ�ʲ��������һ��
ÿ������֮�����һ�п���

��������
2
3 7
DalaoLin 100
XuezhaChen 59
ChiguaWang 88
QUERY_AVERAGE
QUERY_MAX
QUERY_MIN
CHANGE 1 99
QUERY_MIN
QUERY_MAX
QUERY_AVERAGE
1 1
DalaoLin 100
QUERY_AVERAGE

�������
82.3
100
59
59
99
82.0

100.0

*/

#include<stdio.h>
#include<string.h>

int main()
{
	int a[101],T,N,M,i,j,total,max,min,score,k1,k2;
	float average;
	char c[20],name[101][20];
	scanf("%d",&T);
	while(T--){
		total=0,max=0;
		scanf("%d %d\n",&N,&M);
		for(i=1;i<=N;i++){
			j=0;
			scanf("%s %d",&name[i],&a[i]);
			total+=a[i];
			if(max<a[i]){
				max=a[i];
			}
			if(i==1){
				min=a[i];
			}
			else if(min>a[i]){
				min=a[i];
			}
		}
		average=total*1.0/N;
		while(M--){
			scanf("%s",&c);
			if(strcmp(c,"QUERY_AVERAGE")==0){
				printf("%.1f\n",average);
			}
			else if(strcmp(c,"QUERY_MAX")==0){
				printf("%d\n",max);
			}
			else if(strcmp(c,"QUERY_MIN")==0){
				printf("%d\n",min);
			}
			else if(strcmp(c,"CHANGE")==0){
				scanf("%d %d",&k1,&k2);
				total=total-a[k1]+k2;
				average=total*1.0/N;
				a[k1]=k2;
				max=a[1];
				min=a[1];
				for(i=2;i<=N;i++){
					if(max<a[i]){
						max=a[i];
					}
					else if(min>a[i]){
						min=a[i];
					}
				}	
			}
		}
		if(T!=0)
			printf("\n");
	}//while
}
