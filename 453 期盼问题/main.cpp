#include <stdio.h>
#include <string.h>
#include <iostream>

using namespace std;

#define removeAt(a,i) ((~(1<<i))&a)
#define getAt(a,i) ((a>>i)&1)

bool map[9][9];
int N,K,dp[9][256];	//dp[²ã][¹¹³É]


int sumofbit(int n)
{
	int i,bit=1,ans=0;
	for(i=0; i<N; ++i)
	{
		if(n&bit) ans++;
		bit<<=1;
	}
	return ans;
}
int calc(int row,int cons)
{
	int i,j;

	if(dp[row][cons]) return dp[row][cons];
	if(row==0) return dp[row][cons];
	//if(sumofbit(cons)>row+1) return 0;
	for(i=0; i<N; ++i)
	{
		if(map[row][i]==0 && getAt(cons,i))
			dp[row][cons]+=calc(row-1,removeAt(cons,i));
	}
	dp[row][cons]+=calc(row-1,cons);

	return dp[row][cons];

}


int solve() 
{
	int i,j,bit=1,ans=0;

	memset(dp,0,sizeof(dp));
	dp[0][0]=1;
	for(i=0;i<N;++i)
	{
		if(map[0][i]==0)
			dp[0][bit]=1;
		bit<<=1;
	}

	for(i=0;i<(1<<N);++i)
	{
		if(sumofbit(i)==K)
		{
			ans+=calc(N-1,i);
		}
	}
	return ans;
}

int main()
{
	int i,j;
	char c;
	while(cin>>N>>K&&(N!=-1||K!=-1))
	{
		for(i=0;i<N;++i)
		{
			for(j=0;j<N;++j)
			{
				cin>>c;
				if(c=='.') map[i][j]=1;
				else
					map[i][j]=0;
			}
		}
		cout<<solve()<<endl;
	}
	return 0;
}