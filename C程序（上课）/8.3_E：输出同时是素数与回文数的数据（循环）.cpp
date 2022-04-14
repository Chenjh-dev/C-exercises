/*
输出同时是素数与回文数的数据（循环）

题目描述
输出指定范围内的同时是素数与回文数的数据，如果没有，输出“Not found”

输入
测试数据的组数n
第一组指定数据范围的起始值与终止值
第二组指定数据范围的起始值与终止值
..........
第n组指定数据范围的起始值与终止值

输出
输出该范围内同时是素数与回文数的数据，如果没有，输出"Not found"

样例输入
2
100 200
20 50

样例输出
101
131
151
181
191
Not found

*/

#include<stdio.h>

int main()
{
	int n,start,end,i,judge,tag,n1,n2,n3,j;
	scanf("%d",&n);
	while(n--){
		scanf("%d %d",&start,&end);
		tag=0;
		if(end<=1){
			printf("Not found\n");
			continue;
		}
		if(start<=1){
			start=2;
		}
		for(i=start;i<=end;i++){
			judge=0;
			for(j=2;j<i;j++){//判断素数 
				if(i%j==0){
					judge=1;
					break;
				}
			}
			if(judge==1){
				continue;
			}
			if(i<10||i<100&&i/10==i%10||i<1000&&i%10==i/100){//判断回文数 
				tag=1;
				printf("%d\n",i);
			}
		}
		if(tag!=1){
			printf("Not found\n");
		}
	}
}
