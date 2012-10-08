#include <iostream>

using namespace std;

int main()
{
	int n,k,sum;
	while (cin>>n)
	{
		cin>>k;
		sum=0;
		while (n>=k)
		{
			sum+=k;
			n-=k;
			n+=1;
		}
		sum+=n;
		cout<<sum<<endl;
	}
	return 0;
}