#include<iostream>
using namespace std;
int Paixu(int r1,int r2);
struct  Shengri
{
	int year;
	int month;
	int day;
	int zong;
};


int main()
{	
	int n,i,t=0;
	cin>>n;
	Shengri a[50];
	int b[50]={0};
	for(i=0; i<n; i++)
	{
		cin>>a[i].year >>a[i].month >>a[i].day  ;
		a[i].zong =a[i].year*10000+a[i].month *100+a[i].day;
		b[i] = a[i].zong;
	}
	for(i=0;i<n;i++)
	{
		Paixu(a[i].zong ,a[i+1].zong);
	}
	for(i=0;i<n;i++)
	{
		Paixu(a[i].zong ,a[i+1].zong);
	}
	for(i=0; i<=n; i++)
	{
		if(b[i] == a[n-1].zong )
		{
			t = i;
		}	
	}
	a[0].year =a[t].year ,a[0].month =a[t].month ,a[0].day =a[t].day ;
	cout << a[0].year  << "-" << a[0].month << "-"<<a[0].day <<endl;
}


int Paixu(int r1,int r2)
{
	int t;
	if(r1<=r2)
	{
		t=r1;
		r1=r2;
		r2=t;		
	}
}


