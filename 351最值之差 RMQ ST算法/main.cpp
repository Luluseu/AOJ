#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string>


using namespace std;
//*****************
// A存储原始数据 A[1..N]
//******************
long A[100005],N,M;
long dp[100005][18][2];

#define mymin(a,b) (a)<(b)?(a):(b)
#define mymax(a,b) (a)>(b)?(a):(b)

void st_pre()
{
	long i,j,lim;
	lim=log(double(N))/log(2.0)+0.01;

	for(i=1;i<=N;++i)
	{
		dp[i][0][0]=A[i];
		dp[i][0][1]=A[i];
	}	
	for(j=1;j<=lim;++j)
	{
		for(i=1; (i+(1<<j)-1)<=N ;++i)
		{
			dp[i][j][0]=mymin(dp[i][j-1][0],dp[i+(1<<(j-1))][j-1][0]);
			dp[i][j][1]=mymax(dp[i][j-1][1],dp[i+(1<<(j-1))][j-1][1]);
		}	
	}
}


long st_min(const long &a,const long &b)
{
	long len;
	if(a==b) return dp[a][0][0];
	len=log(double(b+1-a))/log(2.0);
	return mymin(dp[a][len][0],dp[b-(1<<len)+1][len][0]);
}
long st_max(const long &a,const long &b)
{
	long len;
	if(a==b) return dp[a][0][1];
	len=log(double(b+1-a))/log(2.0);
	return mymax(dp[a][len][1],dp[b-(1<<len)+1][len][1]);
}

int main()
{
	string filename;
	long i,a,b;
	cin>>N>>M;
	for(i=1;i<=N;++i)
		scanf("%ld",A+i);
	st_pre();
	for(i=0;i<M;++i)
	{
		scanf("%ld%ld",&a,&b);
		printf("%ld\n",st_max(a,b)-st_min(a,b));
	}
}