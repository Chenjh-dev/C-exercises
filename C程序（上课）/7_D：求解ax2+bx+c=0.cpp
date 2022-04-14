#include<stdio.h>
#include<math.h>

int main()
{
	float a,b,c,k;
	scanf("%f %f %f",&a,&b,&c);
	k=b*b-4*a*c;
	if(k>=0){
		printf("x1=%.3f x2=%.3f",(-1*b-sqrt(k))/(2*a),(-1*b+sqrt(k))/(2*a));
	}
	else{
		printf("x1=%.3f+%.3fi x2=%.3f-%.3fi",(-1*b)/(2*a),sqrt(-1*k)/(2*a),(-1*b)/(2*a),sqrt(-1*k)/(2*a));
	}
	return 0;
} 
