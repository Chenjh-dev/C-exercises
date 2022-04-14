#include<stdio.h>

void main()
{
	short int    a[2][3] = {{1,2,3,},{4,5,6}};
	short int    i,j,(*p)[3];

	p =a;
	for (i=0;i<2;i++)
	{
		for (j=0;j<3;j++)
			printf("a[%d][%d]=%d  ", i,j,p[i][j]);
		printf("\n");
	}
}