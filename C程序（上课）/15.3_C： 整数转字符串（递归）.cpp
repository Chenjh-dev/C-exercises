/*
����ת�ַ������ݹ飩

��Ŀ����
д�ݹ麯��void itostr(int num,char str[])�����������ǽ�һ������numת��Ϊ�ַ���str��������135��ת��Ϊ�ַ�����135�������������£������޸ġ�
itostrÿ�ζ������á�������Ϊʵ��itostr�ĵݹ鶨��ȫ�ֱ�����
http://172.31.221.11/JudgeOnline/upload/pimg1411_1.jpg

����
���Դ���t
t������

���
ÿ�����������ת����������ַ���

��������
5
135
0
78934012
-1110
1323

�������
135
0
78934012
-1110
1323

*/

#include<stdio.h>

void itostr(int num,char str[])
{
	if(num==0){
		str[0]='0';
		str[1]='\0';
		return;
	}
	int len=1,k=num;
	while(k/10!=0){
		k/=10;
		len++;
	}
	if(num<0){
		str[0]='-';
		str[len+1]='\0';
		if(len==1){
			str[len]=-1*num+'0';
			return ;
		}
		itostr(num/10,str);
		str[len]=-1*num%10+'0';
	}else if(num>0){
		str[len]='\0';
		if(len==1){
			str[len-1]=num+'0';
			return ;
		}
		itostr(num/10,str);
		str[len-1]=num%10+'0';
	}
}

int main()
{
	const int SIZE = 20;
	int t,num;
	char str[SIZE];
	
	scanf("%d",&t);
	while(t--){
		scanf("%d",&num);
		itostr(num,str);
		printf("%s\n",str);
	}
	return 0;
}

