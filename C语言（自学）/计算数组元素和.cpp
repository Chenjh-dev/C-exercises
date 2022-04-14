#include<stdio.h>

#define N 5

void main()
{
	int A[N];
	int i,sum,*p;

	printf("input %d numbers:",N);
	for (i=0;i<N;i++)
		scanf("%d",A+i);

	for (sum=0,i=0;i<N;i++)
		sum+=A[i];
	printf("sum = %d\n",sum);

	for (sum=0,i=0;i<N;i++)
		sum+=*(A+i);
	printf("sum = %d\n",sum);

	for (sum=0,p=A,i=0;i<N;i++)
		sum+=p[i];
	printf("sum = %d\n",sum);

	for (sum=0,p=A+2;p<A+N;p++)
		sum+=*p;
	printf("sum = %d\n",sum);
}