/*
������򵥵ļ�������ѡ��

��Ŀ����
һ����򵥵ļ�������֧��+, -, *, / �������㡣
���迼���������Ϊ��������������ݺ����������ᳬ��int��ʾ�ķ�Χ��

����
����ֻ��һ�У������������������е�1��2������Ϊ��������3������Ϊ��������+,-,*,/����

���
���ֻ��һ�У�һ��������Ϊ��������Ȼ����
1. ������ֳ���Ϊ0��������������Divided by zero!
2. ���������Ч�Ĳ�����(����Ϊ +, -, *, / ֮һ�����������Invalid operator!

��������
1 2 +

�������
3

*/


#include<stdio.h>

int main()
{
	int x,y;
	char oper;
	scanf("%d %d %c",&x,&y,&oper);
	switch(oper){
		case '+':{
			printf("%d",x+y);
			break;
		}
		case '-':{
			printf("%d",x-y);
			break;
		}
		case '*':{
			printf("%d",x*y);
			break;
		}
		case '/':{
			if(y==0){
				printf("Divided by zero!");
				return 0;
			}
			else{
				printf("%d",x/y);
				return 0;
			}
			break;
		}
		default:{
			printf("Invalid operator!");
			break;
		}
	}
}
