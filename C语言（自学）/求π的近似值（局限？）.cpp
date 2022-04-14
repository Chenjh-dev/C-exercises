/*      ¦Ð/4¡Ö1-1/3+1/5-1/7+...        */
#include<stdio.h>
#include<math.h>
void main()
{
	int s=1;
	float n=1.0,t=1,pi=0;
	while(fabs(t)>=1e-6)
	{
		pi+=t;
		n+=2;
		s=-s;
		t=s/n;
	}
	pi*=4;
	printf("pi=%.6f\n",pi);
}

