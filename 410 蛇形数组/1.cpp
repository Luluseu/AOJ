#include <iostream>
#include <stdio.h>
using namespace std;
int a[100][100];

int main()
{
	int n,i,j,d,s;
	
	while (cin>>n)
	{
		d=0;
		s=0;
		for (i=0;i<n;++i)
		{

			if (d)
			{
				for (j=0;j<i+1;++j)
				{
					a[j][i-j]=++s;
				}
				d=0;
			}
			else
			{
				for (j=i;j>=0;--j)
				{
					a[j][i-j]=++s;
				}
				d=1;
			}

		}

		for (i=1;i<n;++i)
		{
			
			if (d)
			{
				for (j=i;j<n;++j)
				{
					a[j][n-j+i-1]=++s;
				}
				d=0;
			}
			else
			{
				for (j=n-1;j>=i;--j)
				{
					a[j][n-j+i-1]=++s;
				}
				d=1;
			}
			
		}
		
		for (i=0;i<n;++i)
		{
			for (j=0;j<n;++j)
			{
				printf("%-3d",a[i][j]);
			}
			cout<<endl;
		}
		
	}
}