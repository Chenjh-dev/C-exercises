#include<stdio.h>
void main()
{
	long profit;
	float ratio;
	float salary=500;
	printf("Input profit:");
	scanf("%ld",&profit);
	if(profit<=1000)
		ratio=0;
	if(1000<profit&&profit<=2000)
		ratio=(float)0.10;
	if(2000<profit&&profit<=5000)
		ratio=(float)0.15;
	if(5000<profit&&profit<=10000)
		ratio=(float)0.20;
	if(10000<profit)
		ratio=(float)0.25;
	salary+=profit*ratio;
	printf("salary=%.2f\n",salary);
}
