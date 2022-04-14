#include<stdio.h>
#define PI 3.14
main()
{
	float r,cir,area;
	scanf("%f",&r);
	cir=2*PI*r;
	area=PI*r*r;
	printf("Radius=%f\n",cir);
	printf("Circumference=%f\n",cir);
	printf("Area=%f\n",area);
}