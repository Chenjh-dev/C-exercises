/*
找好人（循环）

题目描述
某学校有四位同学中的一位做了好事，不留名，表扬信来了之后，
校长问这四位是谁做的好事。四个人的回答分别是：
A说：不是我
B说：是C
C说：是D
D说：C胡说。
已知三人说的是真话，一个人说的是假话，现在编程求出做好事的到底是谁？

输入
无输入

输出
X
(X表示A,,B,C,D中的一人)

样例输入


样例输出
C

*/

#include<stdio.h>

int main()
{
	char x='A';
	int i=1,judge=0;//i为错的人 
	while(1){
		switch(i){
			case 1:if(x=='A'&&x=='C'&&x=='D'&&x!='D')judge=1;break;
			case 2:if(x!='A'&&x!='C'&&x=='D'&&x!='D')judge=1;break;
			case 3:if(x!='A'&&x=='C'&&x!='D'&&x!='D')judge=1;break;
			case 4:if(x!='A'&&x=='C'&&x=='D'&&x=='D')judge=1;break;
		}
		if(judge==1){
			printf("%c",x);
			break;
		}
		i++;
		if(i==5){
			i=1;
			x+=1;
		}
	}
}
