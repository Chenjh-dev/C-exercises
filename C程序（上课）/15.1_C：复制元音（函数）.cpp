/*

复制元音（函数）
时间限制: 1 Sec  内存限制: 128 MB
提交: 51  解决: 16
[提交][状态][讨论版]
题目描述


写一函数，将两个字符串中的元音字母复制到另一个字符串，然后输出。

输入


一行字符串

输出


顺序输出其中的元音字母（aeiuo）

样例输入

abcde

样例输出

ae

*/

#include<stdio.h>
#include<string.h>

void copy(char a[],char b[])
{
	int l=strlen(a),i,j=0;
	for(i=0;i<l;i++){
		if(a[i]=='a'||a[i]=='e'||a[i]=='i'||a[i]=='o'||a[i]=='u'){
			b[j++]=a[i];
		}
	}
	b[j]='\0';
}

int main()
{
	char a[30],b[30];
	scanf("%s",&a);
	copy(a,b);
	printf("%s",b);
}
