#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int n,i,j,sum;
	int a[1000],b[1000];

	cin>>n;
	while (n!=0)
	{
		for (i=0;i<n;++i)
		{
			cin>>a[i];
		}
		for (i=0;i<n;++i)
		{
			cin>>b[i];
		}

		sort(a,a+n);
		sort(b,b+n);


		i=0;
		j=0;
		sum=0;
		while (i<n&&j<n)
		{
			if (a[i]>b[j])
			{
				++sum;
				++i;
				++j;
			}
			else
			{
				++i;
			}
		}
		cout<<sum<<endl;
		if(sum>n/2.0)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
		cin>>n;
	}
}