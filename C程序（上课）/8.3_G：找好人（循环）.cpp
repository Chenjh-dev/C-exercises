/*
�Һ��ˣ�ѭ����

��Ŀ����
ĳѧУ����λͬѧ�е�һλ���˺��£�������������������֮��
У��������λ��˭���ĺ��¡��ĸ��˵Ļش�ֱ��ǣ�
A˵��������
B˵����C
C˵����D
D˵��C��˵��
��֪����˵�����滰��һ����˵���Ǽٻ������ڱ����������µĵ�����˭��

����
������

���
X
(X��ʾA,,B,C,D�е�һ��)

��������


�������
C

*/

#include<stdio.h>

int main()
{
	char x='A';
	int i=1,judge=0;//iΪ����� 
	while(1){
		switch(i){
			case 1:if(x=='A'&&x=='C'&&x=='D'&&x!='D')judge=1;break;
			case 2:if(x!='A'&&x!='C'&&x=='D'&&x!='D')judge=1;break;
			case 3:if(x!='A'&&x=='C'&&x!='D'&&x!='D')judge=1;break;
			case 4:if(x!='A'&&x=='C'&&x=='D'&&x=='D')judge=1;break;
		}
		if(judge==1){
			printf("%c",x);
			break;
		}
		i++;
		if(i==5){
			i=1;
			x+=1;
		}
	}
}
