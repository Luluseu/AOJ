#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>


using namespace std;

int N,dp[2000005];
#define  MAX 2000000
bool bsushu[MAX+1];//MAX以内的素数 1000001
int sushu[MAX/10];
int len;
void dabiao()
{
	int i,j;
	int bound=sqrt(MAX+0.0);
	for (i=2;i<=MAX;i+=2)
	{
		bsushu[i]=1;
	}
	for (i=3;i<bound;i+=2)
	{
		if(!bsushu[i])
			for (j=i+i;j<=MAX;j+=i)
			{
				bsushu[j]=1;
			}	
	}
	sushu[0]=2;
	j=0;
	for (i=3;i<MAX+1;i+=2)
	{
		if (!bsushu[i])
		{
			sushu[++j]=i;
		}
	}
	len=j+1;
}
int  solve(int n)
{
	int m=1000,t;
	if (!n)
		return 0;
	if (dp[n])
		return dp[n];

	int i,lim=sqrt(n+0.0)+0.5;
	for (i=0;sushu[i]<lim;++i)
	{
		int ss=sushu[i];
		t=solve(n/ss)+solve(ss)+solve(n%ss);
		if (t<m) m=t;
	}
	/*
	for (i=0;sushu[i]<n/2;++i)
	{
		
		if (binary_search(sushu,sushu+len,n-sushu[i]) != -1)
		{
			t=solve(sushu[i])+solve(n-sushu[i]);
			if (t<m) m=t;
		}
	}
	*/
	return dp[n]=m;
}

int main()
{
	dabiao();
	scanf("%d",&N);
	dp[1]=1;dp[2]=2,dp[3]=3;dp[4]=4,dp[5]=5,dp[6]=5;
	printf("%d\n",solve(N));
	/*
	while (~scanf("%d",&N))
	{
		printf("%d\n",solve(N));
	}*/
}