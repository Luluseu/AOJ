#include <stdio.h>
#include <iostream>

using namespace  std;
int m,n,a[101][101];
int dp[101][101]={0};

int digui(int x,int y)
{
	int t=0,max=0;
	if (dp[x][y])
	{
		return dp[x][y];
	}
	
	if(x-1>=0&&a[x-1][y]<a[x][y])  t=digui(x-1,y);
	if (t>max)
	{
		max=t;
	}
	if(x+1<m&&a[x+1][y]<a[x][y])  t=digui(x+1,y);
	if (t>max)
	{
		max=t;
	}
	if(y-1>=0&&a[x][y-1]<a[x][y])  t=digui(x,y-1);
    if (t>max)
	{
		max=t;
	}
	if(y+1<n&&a[x][y+1]<a[x][y])  t=digui(x,y+1);
	if (t>max)
	{
		max=t;
	}

	dp[x][y]=max+1;
	return max+1;
	
}


int main(){

//	freopen("1.txt","r",stdin);
//	freopen("2.txt","w",stdout);

    int i,j,x,y,min=0;
   cin>>m>>n;
   while (m!=0 && n!=0)
   {
	   min=0;
	   for(i=0;i<m;i++)
		   for(j=0;j<n;j++)
		   {
			   //scanf("%d",a[i]+j);
				cin>>a[i][j];	
			   dp[i][j]=0;
		   }
		   
		   for (i=0;i<m;++i)
		   {
			   for (j=0;j<n;++j)
			   {
				   if(min<digui(i,j))
					   min=digui(i,j);
			   }
		   }
		   
		cout<<min<<endl;
		cin>>m>>n;

   }
	
	return 0;
}


