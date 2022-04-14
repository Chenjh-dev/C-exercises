#include<stdio.h>
#include<stdlib.h>

int main()
{
	int n,t,i,k,total;
	scanf("%d",&n);
	while(n--){
		k=0;
		total=0;
		scanf("%d",&t);
		int *a;
		a=(int *)malloc(t*sizeof(int));
		for(i=1;i<t;i++){
			if(t%i==0){
				a[k]=i;
				k++;
				total+=i;
			}
		}
		if(total==t){
			printf("yes");
		}
		else{
			printf("no");
		}
		for(i=0;i<k;i++){
			printf(",%d",a[i]);
		}
		printf("\n");
	}
}
