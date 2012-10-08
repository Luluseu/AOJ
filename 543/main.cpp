#include <stdio.h>

#define INF 100000000

int N,L,ans;
int c[205][205];
int cal[1005];
int dp[2][205][205];


void copy2(int a,int b)
{
	int i,j;

	for (i=1;i<=L;++i)
	{
		for (j=1;j<=L;++j)
		{
			dp[b][i][j]=dp[a][i][j];
		}
	}
}
void clr(int cur)
{
	int i,j;

	for (i=1;i<=L;++i)
	{
		for (j=1;j<=L;++j)
		{
			dp[cur][i][j]=INF;
		}
	}
}

void work()
{
	int i,j,cur,k,pre;

	//initial
	clr(0);

	cal[0]=1;
	dp[0][2][3]=0;

	//work
	for (k=1;k<=N;++k)
	{
		cur=k%2;
		pre=1-cur;

		//两次重叠
		if (cal[k] == cal[k-1])
		{
			copy2(pre,cur);
			continue;
		}

		//清理
		clr(cur);
		//non 
		for (i=1;i<=L;++i)
		{
			for (j=i+1;j<=L;++j)
			{
				if (dp[pre][i][j] == INF) continue;
				if (i == cal[k-1]  || j==cal[k-1]) continue;
				if (cal[k]==i)
				{
					if (j<cal[k-1] && dp[pre][i][j]<dp[cur][j][cal[k-1]])
					{
						dp[cur][j][cal[k-1]]=dp[pre][i][j];
					}else if (j>cal[k-1] && dp[pre][i][j]<dp[cur][cal[k-1]][j])
					{
						dp[cur][j][cal[k-1]]=dp[pre][i][j];
					}
				}
				if (cal[k]==j)
				{
					if (i<cal[k-1] && dp[pre][i][j]<dp[cur][i][cal[k-1]])
					{
						dp[cur][i][cal[k-1]]=dp[pre][i][j];
					}else if (i>cal[k-1] && dp[pre][i][j]<dp[cur][cal[k-1]][i])
					{
						dp[cur][i][cal[k-1]]=dp[pre][i][j];
					}
				}
				//other
				if (cal[k-1] < i)
				{
					if (dp[pre][i][j]+c[i][cal[k]] < dp[cur][cal[k-1]][j])
					{
						dp[cur][cal[k-1]][j]=dp[pre][i][j]+c[i][cal[k]];
					}
					if (dp[pre][i][j]+c[j][cal[k]] < dp[cur][cal[k-1]][i])
					{
						dp[cur][cal[k-1]][i]=dp[pre][i][j]+c[j][cal[k]];
					}
					if (dp[pre][i][j]+c[cal[k-1]][cal[k]] < dp[cur][i][j])
					{
						dp[cur][i][j] = dp[pre][i][j]+c[cal[k-1]][cal[k]];
					}
				}else if ( cal[k-1] < j)
				{
					if (dp[pre][i][j]+c[i][cal[k]] < dp[cur][cal[k-1]][j])
					{
						dp[cur][cal[k-1]][j]=dp[pre][i][j]+c[i][cal[k]];
					}
					if (dp[pre][i][j]+c[j][cal[k]] < dp[cur][i][cal[k-1]])
					{
						dp[cur][i][cal[k-1]]=dp[pre][i][j]+c[j][cal[k]];
					}
					if (dp[pre][i][j]+c[cal[k-1]][cal[k]] < dp[cur][i][j])
					{
						dp[cur][i][j] = dp[pre][i][j]+c[cal[k-1]][cal[k]];
					}
				}else
				{
					if (dp[pre][i][j]+c[i][cal[k]] < dp[cur][j][cal[k-1]])
					{
						dp[cur][j][cal[k-1]]=dp[pre][i][j]+c[i][cal[k]];
					}
					if (dp[pre][i][j]+c[j][cal[k]] < dp[cur][i][cal[k-1]])
					{
						dp[cur][i][cal[k-1]]=dp[pre][i][j]+c[j][cal[k]];
					}
					if (dp[pre][i][j]+c[cal[k-1]][cal[k]] < dp[cur][i][j])
					{
						dp[cur][i][j] = dp[pre][i][j]+c[cal[k-1]][cal[k]];
					}
				}
			}
		}
	}

	ans=INF;
	for (i=1;i<=L;++i)
	{
		for (j=1;j<=L;++j)
		{
			if (dp[cur][i][j] < ans)
			{
				ans=dp[cur][i][j];
			}
		}
	}

}

int main()
{
	int i,j;
	
	scanf("%d%d",&L,&N);

	for (i=1;i<=L;++i)
	{
		for (j=1;j<=L;++j)
		{
			scanf("%d",c[i]+j);
		}
	}
	for (i=1;i<=N;++i)
	{
		scanf("%d",cal+i);
	}
	work();
	printf("%d",ans);
}