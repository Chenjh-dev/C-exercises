/*
һֻС�۷䣨�ݹ飩

��Ŀ����
��һֻ����ѵ�����۷�ֻ�������Ҳ����ڵķ䷿�����ܷ������С����̼����۷�ӷ䷿a�����䷿b�Ŀ���·������
���У��䷿�Ľṹ������ʾ��
http://172.31.221.11/JudgeOnline/upload/pimg1401_1.jpg
��ʾ�����庯��int  GetPathNumber(int a,int b)�����a��b��·���������ء��ҳ�����a+1��b��a+2��b��·������ϵ��

����
�������ݵĵ�һ����һ������N,��ʾ����ʵ���ĸ�����Ȼ����N �����ݣ�ÿ�а�����������a��b(0<a<b<50)��

���
����ÿ������ʵ����������۷�ӷ䷿a�����䷿b�Ŀ���·������ÿ��ʵ�������ռһ�С�

��������
2
1 2
3 6

�������
1
3

*/

#include<stdio.h>

int GetPathNumber(int a,int b)
{
	if(a<b-1){
		return GetPathNumber(a+1,b)+GetPathNumber(a+2,b);
	}
	return 1;
}

int main()
{
	int t,a,b;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&a,&b);
		printf("%d\n",GetPathNumber(a,b));
	}
}
