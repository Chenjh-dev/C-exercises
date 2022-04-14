/*

标识符（循环）
时间限制: 1 Sec  内存限制: 128 MB
提交: 734  解决: 215
[提交][状态][讨论版]
题目描述


C语言中的标识符只能由字母、数字和下划线三种字符组成，且第一个字符必须是字母或下划线。c89规定标识符在31个字符以内，且不能是关键字。 假设忽略关键字比较，采用c89标准。输入一行，判断是否合法标识符。

输入


第一行，测试次数

 每组测试数据一行字符

输出


对每组测试数据，若为C语言合法标识符，输出YES，否则输出NO。

样例输入

5
_temp
ABC10 
area90
9long
width!


样例输出

YES
NO
YES
NO
NO

*/

#include<stdio.h>
#include<string.h>

int check(char a[]){
	if(a[0]=='_'||(a[0]>='a'&&a[0]<='z')||(a[0]>='A'&&a[0]<='Z')){
		
	}
	else{
		return 0;
	}
	for(int i=1;i<strlen(a);i++){
		if((a[i]>='a'&&a[i]<='z')||(a[i]>='A'&&a[i]<='Z')||(a[i]>='0'&&a[i]<='9')){
			
		}else{
			return 0;
		}
	}
	return 1;
}

int main()
{
	int t;
	char a[100];
	scanf("%d\n",&t);
	while(t--){
		gets(a);
		if(strlen(a)>31||strlen(a)<1||!check(a)){
			printf("NO\n");
			continue;
		}
		printf("YES\n");
	}
}
