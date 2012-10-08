#include <stdio.h>
#include <string.h>
int dp[2][1000005];
int A[55];

inline int hash(const int &a)
{
	return a+500002;
}
inline int mmax(const int &a,const int &b)
{
	return a>b?a:b;
}

int main()
{
	int N,i,j,LIM=0;
	int pre,cur;
	scanf("%d",&N);
	for(i=0;i<N;++i) {scanf("%d",A+i);LIM+=A[i];}
	LIM/=2;
	LIM+=10;
	if (N<=1)
	{
		printf("%d\n",-1);
		return 0;
	}
	memset(dp,-1,sizeof(dp));
	dp[0][hash(A[0])]=A[0];
	dp[0][hash(-A[0])]=A[0];
	dp[0][hash(0)]=0;dp[1][hash(0)]=0;

	for(i=1;i<N;++i)
	{
		pre=(i+1)%2;
		cur=i%2;

		for(j=-LIM;j<=LIM;++j)
		{
			int m=0,n=0;
			if (~dp[pre][hash(j-A[i])])
			{
				m=dp[pre][hash(j-A[i])]+A[i];

			}
			if (~dp[pre][hash(j+A[i])])
			{
				n=dp[pre][hash(j+A[i])]+A[i];
			}
			int t=mmax(m,n);
			dp[cur][hash(j)]=mmax(t,dp[pre][hash(j)]);
		}
	}
	int ans;
	if (ans=dp[(N+1)%2][hash(0)]/2)
	{
	}else
		ans=-1;
	printf("%d\n",ans);

}