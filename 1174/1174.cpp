#include <iostream>

using namespace std;

int main()
{
	int i,j,m,n,sum;
	int a[1000],b[1000];

	cin>>m>>n;
	for (i=0;i<m;++i)
	{
		cin>>a[i];
	}
	for (i=0;i<n;++i)
	{
		cin>>b[i];
	}
	i=j=0;
	sum=0;
	while (i!=m&&j!=n)
	{
		if (a[i]==b[j])
		{
			sum++;
			i++;
			j++;
		}
		else
			if (a[i]>b[j])
			{
				j++;
			}
			else i++;
	}
	cout<<sum;
}