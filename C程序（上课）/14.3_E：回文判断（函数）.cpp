/*

 �����жϣ�������
ʱ������: 1 Sec  �ڴ�����: 128 MB
�ύ: 1382  ���: 815
[�ύ][״̬][���۰�]
��Ŀ����


��дһ������int isPalindrome(char s[])���жϲ�����ʾ���ַ����Ƿ��ǻ��ģ�����Ƿ���1�����򷵻�0�����������е��������ж�������ַ����Ƿ��ǻ��ģ�����ǣ������yes����������ǣ����"No"��

����


�������ݵĸ��� t 

��һ���ַ��� 

�ڶ����ַ��� 

........ 

���


����ǣ������yes����������ǣ����"No"

��������

3
abba
abcba
ab

�������

Yes
Yes
No
*/

#include<stdio.h>
#include<string.h>

int isPalindrome(char s[])
{
	int i,j;
	for(i=0,j=strlen(s)-1;i<j;i++,j--){
		if(s[i]!=s[j]){
			return 0;
		}
	}
	return 1;
}

int main()
{
	int t,i;
	char s[20];
	scanf("%d",&t);
	while(t--){
		scanf("%s",&s);
		if(isPalindrome(s)){
			printf("Yes\n");
		}
		else{
			printf("No\n");
		}
	}
}
