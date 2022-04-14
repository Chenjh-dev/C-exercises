/*
学生成绩管理系统 - I

题目描述
现有一学生管理系统，包含N个学生姓名与学生成绩，
你需要回答Q个操作，
这些询问包括求平均值，求最大值，求最小值，改变某个同学的成绩

输入
测试数据有多组
输入的第一行输入一个整数T，代表测试组数
每组测试数据第一行有两个整数N, M  (1 <= N <= 100, 1 <= M <= 100)
接下来N行输入N个学生的姓名和成绩，保证每个同学的姓名各不相同且长度不超过20，成绩都是非负整数
接下来M行输入M个操作，这些操作的格式包括：
QUERY_AVERAGE: 求平均值，输出保留1位小数
QUERY_MAX: 求最大值
QUERY_MIN: 求最小值
CHANGE index score: 将存在于名单中下标为index（下标从1开始）的同学的成绩修改为score，输入保证合法

输出
对于每组测试样例
对于其中的每个询问操作各输出一行
每组样例之间输出一行空行

样例输入
2
3 7
DalaoLin 100
XuezhaChen 59
ChiguaWang 88
QUERY_AVERAGE
QUERY_MAX
QUERY_MIN
CHANGE 1 99
QUERY_MIN
QUERY_MAX
QUERY_AVERAGE
1 1
DalaoLin 100
QUERY_AVERAGE

样例输出
82.3
100
59
59
99
82.0

100.0

*/

#include<stdio.h>
#include<string.h>

int main()
{
	int a[101],T,N,M,i,j,total,max,min,score,k1,k2;
	float average;
	char c[20],name[101][20];
	scanf("%d",&T);
	while(T--){
		total=0,max=0;
		scanf("%d %d\n",&N,&M);
		for(i=1;i<=N;i++){
			j=0;
			scanf("%s %d",&name[i],&a[i]);
			total+=a[i];
			if(max<a[i]){
				max=a[i];
			}
			if(i==1){
				min=a[i];
			}
			else if(min>a[i]){
				min=a[i];
			}
		}
		average=total*1.0/N;
		while(M--){
			scanf("%s",&c);
			if(strcmp(c,"QUERY_AVERAGE")==0){
				printf("%.1f\n",average);
			}
			else if(strcmp(c,"QUERY_MAX")==0){
				printf("%d\n",max);
			}
			else if(strcmp(c,"QUERY_MIN")==0){
				printf("%d\n",min);
			}
			else if(strcmp(c,"CHANGE")==0){
				scanf("%d %d",&k1,&k2);
				total=total-a[k1]+k2;
				average=total*1.0/N;
				a[k1]=k2;
				max=a[1];
				min=a[1];
				for(i=2;i<=N;i++){
					if(max<a[i]){
						max=a[i];
					}
					else if(min>a[i]){
						min=a[i];
					}
				}	
			}
		}
		if(T!=0)
			printf("\n");
	}//while
}
