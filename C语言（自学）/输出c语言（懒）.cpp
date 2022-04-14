#include<stdio.h>
#include<string.h>
void main ()
{
	int i;
	char word[][80] =
	{
		" ****        *    *****                    *            ",
		"*        ",
		"***********************************",
	
	""""""};
		for(i=0 ; strlen(word[i])!=0;i++)
			printf("%s\n",word[i]);
}