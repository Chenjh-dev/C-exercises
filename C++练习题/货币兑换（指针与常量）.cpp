#include<stdio.h>
#include <iostream>
#include <iomanip>
using namespace std;



int main()
{
	int  t , i ;
	char m ;
	float a[4]={6.2619,6.6744,0.0516,0.8065}, *p , n ;
	p = a ;
	cin >> t ;
	for( i = 0; i < t; i++)
	{
		cin >> m >> n ;
		
		switch(m)
		{
		
 		  case 'D': cout<<fixed<<setprecision(4)<<n*(*p)  <<endl; break;
		  case 'E': cout<<fixed<<setprecision(4)<<n*(*(p+1))<<endl; break;
		  case 'Y': cout<<fixed<<setprecision(4)<<n*(*(p+2))<<endl; break;
		  case 'H': cout<<fixed<<setprecision(4)<<n*(*(p+3))<<endl; break;
		  default :                                               break;
		}
	}
	return 0;
}


