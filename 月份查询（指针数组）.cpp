#include <iostream>
using namespace std;

int main()
{
	int  n ,i ,m ;
	cin >> n;
	char  *p[]={"January","February","March","April","May","June","July","August","September","October","November","December"};

	for(i =0;i < n ; i++)
	{
		cin >> m;
		if( m >=1 && m <= 12)
			cout<<*(p+m-1)<<endl;
		else printf("error\n");
	}
	return 0;
}


