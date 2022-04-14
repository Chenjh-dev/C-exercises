#include <stdio.h>
#include<math.h>
int main()
{
	int a,b,c;
	double s,A;

	a=b=c=4;
	s =(a+b+c)/2.0;
	A=sqrt(s*(s-a)*(s-b)*(s-c));

	printf("%f\n",A);

	return 0;

}