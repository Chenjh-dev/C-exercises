/*
字符串碎片（字符串）

题目描述
一个由小写字母组成的字符串可以看成一些同一字母的最大碎片组成的。
例如，"aaabbaaac"是由下面碎片组成的："aaa","bb",‘c’。
输入字符串，请计算字符串的所有碎片及所有碎片的平均长度。
所有碎片的平均长度 = 所有碎片长度之和/碎片个数

输入
测试次数t
每组测试数据为一行字符串

输出
对每组测试数据，输出字符串中按顺序出现的碎片和所有碎片的
平均长度（相同碎片只输出一次，平均长度保留2位小数）。

样例输入
4
aaabbaaac
szuszuszuszu
aaaaaa
apple

样例输出
aaa bb c 2.25
s z u 1.00
aaaaaa 6.00
a pp l e 1.25

*/

#include<stdio.h>
#include<string.h>

int main()
{
	int t,i,j,k,m,num,l;//k为不重复序列个数，num为所有序列总数，l为一行所有字符数 
	char c[50],a[50][50],b[50];
	scanf("%d\n",&t);
	while(t--){
		gets(c);
		b[0]=c[0];
		i=1,k=m=num=l=0;
		do{
			m++;
			if(c[m]!=b[i-1]){  //前后字符不一样 
				b[i]='\0';
				int judge=0;
				for(j=0;j<k;j++){  //检测是否已经有重复序列 
					if(strcmp(a[j],b)==0){
						judge=1;
						break;
					}
				}
				if(judge==0){
					strcpy(a[k],b);
					k++;
				}
				i=1,num++;
				if(c[m]=='\0'){
					l++;
					break;
				}
				b[0]=c[m];
			}
			else{  //前后字符一样 
				b[i]=c[m];
				i++;
			}
			l++;
		}while(c[m]!='\0');
		for(i=0;i<k;i++){
			printf("%s ",a[i]);
		}
		printf("%.2f\n",l*1.0/num);
	}
	return 0;
}
