/*
�ж�������������

��Ŀ����
дһ���ж������ĺ�����������������һ������������Ƿ���������Ϣ��

����
�жϴ�����ÿ��������������� ��

���
ÿ�ε������Ƿ�Ϊ����

��������
4
17
5
6
19

�������
prime
prime
not prime
prime

*/

#include<stdio.h>
#include<math.h> 

bool judge(int a)
{
	int i,j;
	for(i=2;i<=sqrt(a);i++){
		if(a%i==0){
			return true;
		}
	}
	return false;
}

int main()
{
	int t,a;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&a);
		if(judge(a)){
			printf("not prime\n");
		}
		else{
			printf("prime\n");
		}
	}
}






