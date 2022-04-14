#include<stdio.h>
int main()
{
	int a[100][2][3];
	int T,i,j,k;
	scanf("%d",&T);
	for(i=1;i<T+1;i++)
         for(j=1;j<3;j++)
            for(k=1;k<4;k++)
              scanf("%d",&a[i][j][k]);

for(i=1,k=0;i<T+1;k=0)
   for(j=1;j<4;j++)
     
	 if (a[i][1][j]>=a[i][2][j])
		      k=k+1;
	 else k=k;
	 

		
		if (k==3)
			printf("Yes\n");
		else printf("No\n");
return 0;
}
