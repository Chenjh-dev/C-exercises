/*

����ͳ�� 
ʱ������: 1 Sec  �ڴ�����: 128 MB
�ύ: 197  ���: 112
[�ύ][״̬][���۰�]
��Ŀ����


��дһ�����򣬸��ݵ��ʵĳ���Ƶ�ʽ����ӡ��������ĵĸ������ʡ�ÿ������ǰ�������ļ���ֵ��

����


�������ʣ�����0���ʾ���ʽ���

���


�����ӡ���ʳ��ֵ�Ƶ�ʺ͵��ʡ�

��������

good
bad
bad
cute
how
good
good
0

�������

3 good
2 bad
1 cute
1 how

*/

#include<stdio.h>
#include<string.h>

int main()
{
	int i,j,m,n=0,num[20],judge;
	char word[20][20],k[20];
	while(1){
		judge=0;
		scanf("%s",&k);
		if(strcmp(k,"0")==0){
			break;
		}
		for(i=0;i<n;i++){
			if(strcmp(word[i],k)==0){
				num[i]++;
				judge=1;
				break;
			}
		}
		if(judge==0){
			strcpy(word[n],k);
			num[n]=1;
			n++;
		}
	}
	for(i=0;i<n-1;i++){
		m=i;
		for(j=i;j<n-1;j++){
			if(num[m]<num[j+1]){
				m=j+1;
			}
		}
		if(m!=i){
			strcpy(k,word[i]);
			strcpy(word[i],word[m]);
			strcpy(word[m],k);
			j=num[i];
			num[i]=num[m];
			num[m]=j;
		}
	}
	for(i=0;i<n;i++){
		printf("%d %s\n",num[i],word[i]);
	}
}
