/*

素数三元组（循环）

题目描述
相邻三个奇数都是素数是一种非常少见的情形，也就是三个奇数p-2, p, p+2都是素数，
这样就形成了一个素数三元组。输入数字n，在1~n的所有素数三元组。

输入
输入多组数据，每组测试数据为一个正整数n，n <= 5000000。

输出
输出大小不超过n的所有的素数三元组，每行按照从小到大的顺序
输出一个三元组中的三个数，两个数之间用空格间隔(最后一个数字没空格）。
如果不存在这样的素数三元组，请输出“No triple”。

样例输入
1

样例输出
No triple

*/

#include<stdio.h>
#include<math.h>

int main()
{
	int n,a,b,c,i,j,tag1,tag2;
	while(scanf("%d",&n)!=EOF){
		tag2=0;
		a=0,b=0,c=0;
		
		if(n<=2||n>5000000){
			printf("No triple\n");
			continue;
		}
		for(i=3;i<=n;i+=2){
			tag1=0;
			for(j=3;j<=sqrt(i);j+=2){
				if(i%j==0){
					tag1=1;
					break;
				}
			}
			if(tag1==0){
				a=b;
				b=c;
				c=i;
				if(b==a+2&&c==b+2){
					tag2=1;
					printf("%d %d %d\n",a,b,c);
				}
			}
		}
		if(tag2==0){
				printf("No triple\n");
		}
	}
}

//EOF，为End Of File的缩写，通常在文本的最后存在此字符表示资料结束。
//
//while(scanf("%d",&n)!= EOF){}
//因此需要用<Ctrl + z>组合键然后按 Enter 键的方式来告诉系统已经到了EOF，
//这样系统才会结束while.
//
//但是在C++中不存在这种用法，但相同作用的有while((cin >> a) != 0)：
//C++中的while (cin>>n,n)：
//他的作用是：输入一个数，这数不为0时进入循环，为0时跳出循环。

