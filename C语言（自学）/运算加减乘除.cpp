#include<stdio.h>
void main()
{
	float a,b;
	int tag=0;
	char ch;
	float result;

	printf("input two number:");
	scanf("%f%f",&a,&b);
    fflush(stdin);
	printf("input arithmetic lable(+-*/):");
	scanf("%c",&ch);

	switch(ch)
	{
		case '+': result=a+b;  break;
		case '-': result=a-b;  break;
		case '*': result=a*b;  break;
		case '/': if(!b)
				  {
					  printf("divisor is zero!\n");
						  tag=1;
				  }
			else
				result=a/b;  break;
		default:printf("illegal arithmtic lable\n");
			    tag=1;
	}
	if(!tag)
		printf("%.2f %c %.2f = %.2f\n",a,ch,b,result);
}
			
