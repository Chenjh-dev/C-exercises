/*
�������⣨������

��Ŀ����
����һ����֪�ľ��Σ��ж�����ĵ��Ƿ�����ڸþ����ڡ�
������꣨x,y���ýṹ�������������ο����öԽ����ϵ������������壨���½ǵ�����Ͻǵ㣩��
��֪���ε����½ǵ�Ϊ��1,1�������Ͻǵ�Ϊ��5,5����
Ҫ���дһ�������жϵ��Ƿ��ھ����ڣ���������򷵻�1�����򷵻�-1
���������ø��жϺ������������1�����in������-1�����out

����
�����ĸ�����ÿ���������

���
�ھ����ڲ������ⲿ

��������
3
1 1
5 5
5 10

�������

in
in
out

��ʾ
������ھ����ڣ�������겻���ھ�������귶Χ

*/

#include<stdio.h>

struct Point
{
	int x;
	int y;
};

struct Rectangle
{
	Point A;
	Point B;
};

Point p1={1,1},p2={5,5};
Rectangle r={p1,p2};

int judge(Point p)
{
	if(p.x>=r.A.x&&p.x<=r.B.x&&p.y>=r.A.y&&p.y<=r.B.y){
		return 1;
	}
	else{
		return -1;
	}
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--){
		Point p;
		scanf("%d%d",&p.x,&p.y);
		if(judge(p)==1){
			printf("in\n");
		}
		else{
			printf("out");
		}
	}
}
