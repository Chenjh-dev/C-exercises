#include<stdio.h>
#include<string.h>

int main()
{
	int T,M,space;
	int timetotal,time;
	double timerate;
	char action[10],k;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&M);
		space=0;
		timetotal=0.0;
		timerate=1.0;
		while(M--){
			scanf("%s",&action);
			if(strcmp(action,"IN")==0){
				space++;
				timerate*=0.05;
			}else if(strcmp(action,"STAY")==0){
				scanf("%d",&time);
//				if(time*timerate<0){
//					timetotal+=(int)time*timerate*-1;
//				}else{
					timetotal+=60*(int)time*timerate;
//				}
			}else if(strcmp(action,"OUT")==0){
				if(space!=0){
					space--;
					timerate*=20;
				}
			}else{
				printf("error enter\n");
			}
		}
		printf("%ld\n",timetotal);
	}
}
