/*

 回文判断（函数）
时间限制: 1 Sec  内存限制: 128 MB
提交: 1382  解决: 815
[提交][状态][讨论版]
题目描述


编写一个函数int isPalindrome(char s[])，判断参数表示的字符串是否是回文，如果是返回1，否则返回0。在主函数中调用它，判断输入的字符串是否是回文，如果是，输出“yes”，如果不是，输出"No"。

输入


测试数据的个数 t 

第一个字符串 

第二个字符串 

........ 

输出


如果是，输出“yes”，如果不是，输出"No"

样例输入

3
abba
abcba
ab

样例输出

Yes
Yes
No
*/

#include<stdio.h>
#include<string.h>

int isPalindrome(char s[])
{
	int i,j;
	for(i=0,j=strlen(s)-1;i<j;i++,j--){
		if(s[i]!=s[j]){
			return 0;
		}
	}
	return 1;
}

int main()
{
	int t,i;
	char s[20];
	scanf("%d",&t);
	while(t--){
		scanf("%s",&s);
		if(isPalindrome(s)){
			printf("Yes\n");
		}
		else{
			printf("No\n");
		}
	}
}
