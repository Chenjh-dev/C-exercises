/*

字符串排序
时间限制: 1 Sec  内存限制: 128 MB
提交: 891  解决: 469
[提交][状态][讨论版]
题目描述


对于给出的若干个（不超过10个）字符串（每个字符串的长度不超过20），按ASCII的顺序降序排序，然后输出。


输入


测试数据的组数t

第一组测试数据的个数

第一组测试数据的若干个字符串

第二组测试数据的个数

第二组测试数据的若干个字符串

......


输出


第一组数据降序输出

第二组数据降序输出

......

样例输入
3
4
one two three four
5
blue red yellow red pink
6
chen li zhang huang he ou

样例输出
two three one four
yellow red red pink blue
zhang ou li huang he chen

*/

#include<stdio.h>
#include<string.h>

void rank_(char a[11][21],int n){
	int i,j,k;
	char b[21];
	for(i=0;i<n-1;i++){
		k=i;
		for(j=i;j<n-1;j++){
			if(strcmp(a[k],a[j+1])<0){
				k=j+1;
			}
		}
		strcpy(b,a[k]);
		strcpy(a[k],a[i]);
		strcpy(a[i],b);
	}
}

int main()
{
	int t,n,i;
	char a[11][21];
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(i=0;i<n;i++){
			scanf("%s",&a[i]);
		}
		rank_(a,n);
		for(i=0;i<n-1;i++){
			printf("%s ",a[i]);
		}
		printf("%s\n",a[i]);
		
	}
}
