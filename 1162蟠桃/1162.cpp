#include <iostream>
using namespace std;

int main()
{
	unsigned long  n,i,m;
	cin>>n;
	while(n)
	{
		m=1;
		for(i=1;i<n;++i)
		{
			m=(m+1)*2;
		}
		cout<<m;
		cin>>n;
	}
}
