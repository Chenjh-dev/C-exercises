/*

 求两个数组中相同的元素
时间限制: 1 Sec  内存限制: 128 MB
提交: 264  解决: 176
[提交][状态][讨论版]
题目描述


 

输入两个数组（数组元素个数6和8），输出在两个数组中都出现的元素（如a[6]={2,3,4,5,6,7},b[8]={3,5,7,9,11,13,15,19},则输出3、5、7）。


输入


输出


样例输入

2 3 4 5 6 7
3 5 7 9 11 13 15 19

样例输出

3
5
7

*/

#include<stdio.h>
#define max 999

int main()
{
	int i,j,a[6],b[8],c[6],n=0;
	for(i=0;i<6;i++){
		scanf("%d",&a[i]);
		for(j=0;j<i;j++){
			if(a[j]==a[i]){
				a[i]=max;
			}
		}
	}
	for(i=0;i<8;i++){
		scanf("%d",&b[i]);
		for(j=0;j<i;j++){
			if(b[j]==b[i]){
				b[i]=max;
			}
		}
	}
	for(i=0;i<6;i++){
		for(j=0;j<8;j++){
			if(a[i]==b[j]&&a[i]!=max){
				printf("%d\n",a[i]);
				a[i]=b[j]=max;
			}
		}
	}
	for(i=0;i<8;i++){
		for(j=0;j<6;j++){
			if(b[i]==a[j]&&b[i]!=max){
				printf("%d\n",b[i]);
				b[i]=a[j]=max;
			}
		}
	}
	printf("\n");
}
