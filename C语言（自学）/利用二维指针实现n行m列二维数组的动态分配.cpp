#include<stdio.h>
#include<stdlib.h>

int main()
{
	float  **a,*sum;
	int    n,m,i,j;

	printf("input  n m:");
	scanf("%d%d",&n,&m);

	a=(float  **)malloc(sizeof(float *)*n);
	for(i=0;i<n;i++)
		a[i]=(float *)malloc(sizeof(float)*m);

	sum = (float *)malloc(sizeof(float *)*n);

	for(i=0;i<n;i++)
		for(sum[i]=0,j=0;j<m;j++)
		{
			scanf("%f",&a[i][j]);
			sum[i] += a[i][j];
		}

		printf("result:\n");
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
				printf("%10.1f",a[i][j]);
			printf("%10.1f\n",sum[i]);
		}
}