#include <iostream>

using namespace std;

int main()
{
	int n,i=1;
	cin>>n;
	while(n!=1)
	{
		if(n%2==1)
		{
			n=3*n+1;
			++i;
		}
		else
		{
			n/=2;
			++i;
		}
	}
	cout<<i<<endl;
}