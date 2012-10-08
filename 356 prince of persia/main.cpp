#include <iostream>
#include <cstring>
using namespace std;

int dp[101][101][101];
int A[101];
int N,M;

int main()
{
	int T,i,j,k;
	cin>>T;
	while (T--)
	{
		cin>>N>>M;
		memset(dp,-1,sizeof(dp));
		for (i=0;i<N;++i)	cin>>A[i];
		for(i=A[0];i<=M;++i) dp[0][i][1]=1;
		for(i=0;i<=M;++i) dp[0][i][0]=0;
		for (i=1;i<N;++i)
		{
			for (j=0;j<=M;++j)
			{
				for (k=0;k<=i+1;++k)
				{
					
					if (dp[i][j][0]<dp[i-1][j][k])
					{
						dp[i][j][0]=dp[i-1][j][k];
					}
					if (j-A[i]>=0)
						if(dp[i-1][j-A[i]][k-1]!=-1)
						dp[i][j][k]=dp[i-1][j-A[i]][k-1]+2*k-1;
				}
			}
		}
		int maxx=0;
		for (i=0;i<=N;++i)
		{
			if (dp[N-1][M][i]>maxx)
			{
				maxx=dp[N-1][M][i];
			}
		}
		cout<<maxx<<endl;
	}
}