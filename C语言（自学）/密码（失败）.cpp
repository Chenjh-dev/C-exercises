#include<stdio.h>
#include<string.h>
void main()
{
	int i=1;
	char administrator[10]="qq";
	char password[20];
	printf("input the password:");
	gets(password);
	if(strcmp(password,"administrator")!=0)
		return;
    i=2;
	printf("%d",i);
	printf("hhhhhhhh");
}