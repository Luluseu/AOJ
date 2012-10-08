#include <stdio.h>


int dp[51];
int get(int N)
{
	int i,ans=0;
	if(dp[N])
		return dp[N];
	for (i=1;i<=N;i+=2)
	{
		ans+=get(N-i);
	}
	return dp[N]=ans;
}

int main()
{
	int N;
	dp[0]=dp[1]=1;
	while(~scanf("%d",&N))
	{
		printf("%d\n",get(N));
	}
}