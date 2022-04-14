#include<stdio.h>
#include<math.h>

int main()
{
	int n,k,answer,t;
	scanf("%d",&t);
	while(t--){
		answer=0;
		scanf("%d%d",&n,&k);
		for(int i=1;i<=k;i++){
			answer+=pow(n,i);
		}
		printf("%d\n",answer);
	}
}
