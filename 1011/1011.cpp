#include <iostream>

using namespace  std;

int main()
{
	int a[50];
	int n,m=1,i,sum,k;
	
	cin>>n;
	while (n!=0)
	{
		sum=0;
		k=0;
		for (i=0;i<n;++i)
		{
			cin>>a[i];
			sum+=a[i];
		}
		sum/=n;
		for (i=0;i<n;++i)
		{
			if (a[i]>sum)
			{
				k+=a[i]-sum;
			}
		}
		cout<<"Set #"<<m<<endl;
		cout<<"The minimum number of moves is "<<k<<"."<<endl<<endl;
		cin>>n;
		++m;
	}

}