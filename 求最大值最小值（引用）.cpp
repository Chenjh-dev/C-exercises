#include<iostream>
using namespace std;
void find(int *num,int n,int &minIndex,int &maxIndex);


int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n, minIndex, maxIndex ,i ,*a;
		cin>>n;
		a = new int[n];
		for(i=0;i<n ;i++)
			cin>>*(a+i);
		find(a , n, minIndex, maxIndex);
		cout<<"min="<<*(a+minIndex)<<" "<<"minindex="<<minIndex<<endl;
		cout<<"max="<<*(a+maxIndex)<<" "<<"maxindex="<<maxIndex<<endl;
		cout<<endl;
	}
	return 0;
}



void find(int *num, int n, int &minIndex, int &maxIndex)
{
	minIndex=0;
	maxIndex=0; 
	int max=*num , min=*num , i;
	for(i=0 ;i<n ; i++)
	{
		if(max < *(num+i))
		{
			max = *(num+i);
			maxIndex = i;
		}
		if (min > *(num+i))
		{
            min = *(num+i);
            minIndex = i;
		}
	}
}


