#include<stdio.h>
void main(void)
{
	char ch;
	int num[26]={0},i;
	while((ch=getchar())!='\n')
		if(ch>='A'&&ch<='Z')
			num[ch-'A']++;
		for(i=0;i<26;i++)
		{
			if(i%9==0)
				printf("\n");
			printf("%c(%d)",'A'+i,num[i]);
		}
		printf("\n");
}
