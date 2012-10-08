#include <stdio.h>
#include <string.h>

int dp[10005];
bool steped[10005];

int main()
{

	freopen("6.in","r",stdin);
	freopen("6.txt","w",stdout);

	int N,M,V,i,j,L;
	double m,n;
	while (~scanf("%d%lf",&N,&m))
	{
		M=(m+0.00001)*10;
		memset(dp,0,sizeof(dp));
		memset(steped,0,sizeof(steped));
		steped[0]=true;
		for (i=0;i<N;++i)
		{
			scanf("%lf%lf",&m,&n);
			L=(m+0.00001)*10;
			V=(n+0.00001)*10;
			for (j=M;j-L>=0;--j)
			{
				if(steped[j-L] && dp[j]<dp[j-L]+V)
				{
					steped[j]=true;
					dp[j]=dp[j-L]+V;
				}
			}
		}
		int mmax=0;
		for (j=M;j>=0;--j)
		{
			if (dp[j]>mmax)
			{
				mmax=dp[j];
			}
		}
		printf("%.1f\n",((double)mmax)/10+0.00001);
	}


}