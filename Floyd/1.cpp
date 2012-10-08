#include <iostream>

using namespace std;
int a[100][100];


int main()
{
	int n,i,j,l,k,sum,suml,max,mmax;
	while (cin>>n)
	{
		for (i=0;i<n;++i)
		{
			for (j=0;j<n;++j)
			{
				cin>>a[i][j];
			}
		}
		mmax=0;
		for (i=0;i<n;++i)
		{
			for (j=i;j<n;++j)
			{
				max=0;
				sum=0;

				for (k=0;k<n;++k)
				{
					suml=0;
					for (l=i;l<j+1;++l)
					{
						suml+=a[k][l];
					}
					if (sum<0)
					{
						sum=suml;
					}
					else
						sum+=suml;
					if (sum>max)
					{
						max=sum;
					}
				}
				if (max>mmax)
				{
					mmax=max;
				}
			}
		}

		cout<<mmax<<endl;
	}
	
}