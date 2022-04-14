#include<iostream>
#include<cmath>
#include<string.h>
using namespace std;

int Int(int n);
float Float(float n);
char Char(char *n);

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		char n;
		cin>>n;
		switch(n)
		{
			case 'I':
			{
				int (*INT)(int n);
				INT =Int;
				int m;
				cin>>m;
				cout<<INT(m)<<endl;	
			}
			break;
			
			case 'F':
			{
				float (*FLOAT)(float n);
				FLOAT = Float;
				int m;
				cin>>m;
				cout<<FLOAT(m)<<endl;
			}
			break;
			
			case 'S':
			{
				char (*CHAR)(char n);
				CHAR = Char;
				char m;
				cin>>m;
				cout<<CHAR(m)<<endl;
			}
			break;
			
			default :  break;
		}
	}
	return 0;
}

int Int(int n)
{
	return n*n;
}

float Float(float n)
{
	return sqrt(n);
}

char Char(char *n)
{
	int L,i;
	L = strlen(n);
	for(i=0;i<L;i++)
	{
		*(n+i) =*(n+i)-32;
	}
}
