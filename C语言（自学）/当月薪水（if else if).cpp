#include<stdio.h>
void main()
{
	long profit;
	float ratio;
	float salary=500;
	printf("Input profit:");
	scanf("%ld",&profit);
	if (profit<=1000)
		ratio=0;
	else if (profit<= 2000)
		ratio=(float)0.10;
	else if (profit<= 5000)
		ratio=(float)0.15;
	else if (profit<= 10000)
		ratio=(float)0.20;
	else ratio=(float)0.25;
	salary+=profit*ratio;
	printf("salary=%.2f\n",salary);
}