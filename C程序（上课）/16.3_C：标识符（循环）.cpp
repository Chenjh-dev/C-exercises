/*

��ʶ����ѭ����
ʱ������: 1 Sec  �ڴ�����: 128 MB
�ύ: 734  ���: 215
[�ύ][״̬][���۰�]
��Ŀ����


C�����еı�ʶ��ֻ������ĸ�����ֺ��»��������ַ���ɣ��ҵ�һ���ַ���������ĸ���»��ߡ�c89�涨��ʶ����31���ַ����ڣ��Ҳ����ǹؼ��֡� ������Թؼ��ֱȽϣ�����c89��׼������һ�У��ж��Ƿ�Ϸ���ʶ����

����


��һ�У����Դ���

 ÿ���������һ���ַ�

���


��ÿ��������ݣ���ΪC���ԺϷ���ʶ�������YES���������NO��

��������

5
_temp
ABC10 
area90
9long
width!


�������

YES
NO
YES
NO
NO

*/

#include<stdio.h>
#include<string.h>

int check(char a[]){
	if(a[0]=='_'||(a[0]>='a'&&a[0]<='z')||(a[0]>='A'&&a[0]<='Z')){
		
	}
	else{
		return 0;
	}
	for(int i=1;i<strlen(a);i++){
		if((a[i]>='a'&&a[i]<='z')||(a[i]>='A'&&a[i]<='Z')||(a[i]>='0'&&a[i]<='9')){
			
		}else{
			return 0;
		}
	}
	return 1;
}

int main()
{
	int t;
	char a[100];
	scanf("%d\n",&t);
	while(t--){
		gets(a);
		if(strlen(a)>31||strlen(a)<1||!check(a)){
			printf("NO\n");
			continue;
		}
		printf("YES\n");
	}
}
