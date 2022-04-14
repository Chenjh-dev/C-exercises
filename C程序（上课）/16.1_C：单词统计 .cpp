/*

单词统计 
时间限制: 1 Sec  内存限制: 128 MB
提交: 197  解决: 112
[提交][状态][讨论版]
题目描述


编写一个程序，根据单词的出现频率降序打印出所输入的的各个单词。每个单词前标有它的计数值。

输入


各个单词，输入0则表示单词结束

输出


降序打印单词出现的频率和单词。

样例输入

good
bad
bad
cute
how
good
good
0

样例输出

3 good
2 bad
1 cute
1 how

*/

#include<stdio.h>
#include<string.h>

int main()
{
	int i,j,m,n=0,num[20],judge;
	char word[20][20],k[20];
	while(1){
		judge=0;
		scanf("%s",&k);
		if(strcmp(k,"0")==0){
			break;
		}
		for(i=0;i<n;i++){
			if(strcmp(word[i],k)==0){
				num[i]++;
				judge=1;
				break;
			}
		}
		if(judge==0){
			strcpy(word[n],k);
			num[n]=1;
			n++;
		}
	}
	for(i=0;i<n-1;i++){
		m=i;
		for(j=i;j<n-1;j++){
			if(num[m]<num[j+1]){
				m=j+1;
			}
		}
		if(m!=i){
			strcpy(k,word[i]);
			strcpy(word[i],word[m]);
			strcpy(word[m],k);
			j=num[i];
			num[i]=num[m];
			num[m]=j;
		}
	}
	for(i=0;i<n;i++){
		printf("%d %s\n",num[i],word[i]);
	}
}
