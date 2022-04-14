#include<stdio.h>

int main()
{
	int k1,k2,i,n1,n2,n3;
	scanf("%d %d",&k1,&k2);
	for(i=k1;i<=k2;i++){
		n1=i/100;
		n2=i%100/10;
		n3=i%10;
		if(i==n1*n1*n1+n2*n2*n2+n3*n3*n3){
			printf("%d\n",i);
		}
	}
}
