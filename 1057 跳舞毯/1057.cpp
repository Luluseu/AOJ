#include <iostream>

using namespace std;

int main()
{
	int n,i,a[1001][3]={0},t[3],max=1;
	a[1][0]=0;a[1][1]=1;a[1][2]=1;
	cin>>n;
	while(n)
	{
		if(n>max)
		{

			for(i=max;i<n;++i)
			{
				t[0]=a[i][1]+a[i][2];
				t[1]=a[i][0]+a[i][2];
				t[2]=a[i][1]+a[i][0];
				a[i+1][0]=t[0]%10000;
				a[i+1][1]=t[1]%10000;
				a[i+1][2]=t[2]%10000;
			}
			max=n;

		}
		cout<<a[n][0]<<endl;
		cin>>n;

	}


}
