#include <iostream>

using namespace std;

int main()
{
	unsigned int  n,i;
	double t;
	cin>>n;
	while (n!=0)
	{
		i=0;
		t=1;
		if (n==1)
		{
			cout<<0<<endl;
		}
		else
		{
		while(++i)
		{
			t*=3;
			if (t>=n)
			{
				break;
			}
		}
		cout<<i<<endl;
		}
		cin>>n;
	}
}