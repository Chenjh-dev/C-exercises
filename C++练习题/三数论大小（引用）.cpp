#include<iostream>
using namespace std;
int Bijiao(int &r1,int &r2,int &r3);


int main()
{
	int a,b,c,t;
	cin>>t;

	while(t--)
	{
		cin >>a >>b >>c;
		Bijiao(a,b,c);
		cout<<a<<" "<<b<<" "<<c<<endl;
	}
	return 0;
}

int Bijiao(int &r1,int &r2,int &r3)
{
	int n;

	if(r1<=r2)
		n=r1,r1=r2,r2=n;
	if(r1<=r3)
		n=r1,r1=r3,r3=n;
	if(r2<=r3)
		n=r2,r2=r3,r3=n;
	return 0;
}
