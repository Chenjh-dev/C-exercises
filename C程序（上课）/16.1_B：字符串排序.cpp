/*

�ַ�������
ʱ������: 1 Sec  �ڴ�����: 128 MB
�ύ: 891  ���: 469
[�ύ][״̬][���۰�]
��Ŀ����


���ڸ��������ɸ���������10�����ַ�����ÿ���ַ����ĳ��Ȳ�����20������ASCII��˳��������Ȼ�������


����


�������ݵ�����t

��һ��������ݵĸ���

��һ��������ݵ����ɸ��ַ���

�ڶ���������ݵĸ���

�ڶ���������ݵ����ɸ��ַ���

......


���


��һ�����ݽ������

�ڶ������ݽ������

......

��������
3
4
one two three four
5
blue red yellow red pink
6
chen li zhang huang he ou

�������
two three one four
yellow red red pink blue
zhang ou li huang he chen

*/

#include<stdio.h>
#include<string.h>

void rank_(char a[11][21],int n){
	int i,j,k;
	char b[21];
	for(i=0;i<n-1;i++){
		k=i;
		for(j=i;j<n-1;j++){
			if(strcmp(a[k],a[j+1])<0){
				k=j+1;
			}
		}
		strcpy(b,a[k]);
		strcpy(a[k],a[i]);
		strcpy(a[i],b);
	}
}

int main()
{
	int t,n,i;
	char a[11][21];
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(i=0;i<n;i++){
			scanf("%s",&a[i]);
		}
		rank_(a,n);
		for(i=0;i<n-1;i++){
			printf("%s ",a[i]);
		}
		printf("%s\n",a[i]);
		
	}
}
