/*
矩形内外（函数）

题目描述
对于一个已知的矩形，判断输入的点是否包含在该矩形内。
点的坐标（x,y）用结构体来描述。矩形可以用对角线上的两个点来定义（左下角点和右上角点）。
已知矩形的左下角点为（1,1），右上角点为（5,5）。
要求编写一个函数判断点是否在矩形内，如果在内则返回1，否则返回-1
主函数调用该判断函数，如果返回1则输出in，返回-1则输出out

输入
输入点的个数和每个点的坐标

输出
在矩形内部还是外部

样例输入
3
1 1
5 5
5 10

样例输出

in
in
out

提示
如果点在矩阵内，则点坐标不大于矩阵的坐标范围

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
