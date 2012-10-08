#include <iostream>

using namespace std;
int imin,m,n,a[10][10];
bool f;

void step(int y,int x,int sum)
{
	if (y==m-1)
	{
		if (x==n-1)
		{
			if (sum+a[y][x]>0&&(!f||sum+a[y][x]<imin))
			{
				imin=sum+a[y][x];
				f=1;
				return ;
			}		
		}	
	}
	if (y!=m-1)
	{
		step(y+1,x,sum+a[y][x]);
	}
	if (x!=n-1)
	{
		step(y,x+1,sum+a[y][x]);
	}
	
}

int main()
{
	int i,j;
	while(cin>>m)
	{
		cin>>n;
		for (i=0;i<m;++i)
		{
			for (j=0;j<n;++j)
			{
				cin>>a[i][j];
			}
		}
		imin=-1;
		f=0;
		step(0,0,0);
		if (imin>0)
		{
			cout<<imin<<endl;
		}
		else cout<<-1<<endl;
		


	}
}

