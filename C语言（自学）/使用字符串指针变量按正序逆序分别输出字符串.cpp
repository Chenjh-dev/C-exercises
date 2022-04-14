#include<stdio.h>
#include<string.h>

void main()
{
	char *pstr ="I Love China!";
	int i;

	printf("%s\n",pstr);

	for (i=strlen(pstr)-1;i>=0;i--)
		printf("%c",pstr[i]);
	printf("\n");
}