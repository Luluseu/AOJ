#include <iostream>

using namespace std;

int a[7]={100,50,20,10,5,2,1};

int  step(int n,int able,int num)
{
	int i,max,sum=0;
	if(n==0) return 1;
	if(able==1)
	{
		if(n>num) return 0;
		else return 1;
	}
	for(i=0;n-i*a[7-able]>=0&&num-i>=0;i++)
	{
		max=step(n-i*a[7-able],able-1,num-i);
		sum+=max;
		
	}
	return sum;
}

int main()
{
	int n;
	cin>>n;
	while(n)
	{
		cout<<step(n,7,100)<<endl;
		cin>>n;
	}
}