/*

��m��n֮���������----����
ʱ������: 1 Sec  �ڴ�����: 128 MB
�ύ: 918  ���: 416
[�ύ][״̬][���۰�]
��Ŀ����


��������������m��n(m<n)����m��n֮��(����m��n)���������ĺͣ�Ҫ���岢���ú���isprime(x)���ж�x�Ƿ�Ϊ����(�����ǳ�1����ֻ�ܱ�������������Ȼ��)��



����


m n

���


������

��������

2 3

�������

5
*/

#include<stdio.h>
#include<math.h>

bool isprime(int a)
{
	int i;
	if(a<=1){
		return false;
	}
	if(a==2){
		return true;
	}
	for(i=2;i<=sqrt(a);i++){
		if(a%i==0){
			return false;
		}
	}
	return true;
}

int main()
{
	int i,total=0,m,n;
	scanf("%d%d",&m,&n);
	for(i=m;i<=n;i++){
		if(isprime(i)){
			total+=i;
		}
	}
	printf("%d\n",total);
}
