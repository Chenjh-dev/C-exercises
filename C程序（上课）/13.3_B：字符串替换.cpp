#include<stdio.h>

int main()
{
	char a[1005],i,judge;
	while(scanf("%c",&a[0])!=EOF){
		i=0;
		while(a[i]!='\n'){
			i++;
			scanf("%c",&a[i]);
			if(i>=2){
				if(a[i-2]=='y'&&a[i-1]=='o'&&a[i]=='u'){
					a[i-2]='w';
					a[i-1]='e';
					scanf("%c",&a[i]);
				}
			}
		}
		a[i]='\0';
		printf("%s\n",a);
	}
}

