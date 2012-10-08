#include <stdio.h>
#include <string.h>
#define ROW  101
#define MAXN 101
#define MOD 9999997

int dp[ROW][MAXN];

int main()
{
	freopen("datain.txt","r",stdin);
	freopen("dataout.txt","w",stdout);
	int M,N,i,j,k;
	while (~scanf("%d%d",&M,&N))
	{
		memset(dp,0,sizeof(dp));
		dp[0][0]=1;
		for (i=1;i<=N;++i)
		{
			for (j=0;j<=M;++j)
			{
				for (k=0;k<=j;++k)
				{
					dp[i][j]+=dp[i-1][k];
					dp[i][j]%=MOD;
					
				}
				
			}
		}
		printf("%d\n",dp[N][M]);
	}
}