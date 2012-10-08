#include <stdio.h>
#include <math.h>
#include <string.h>

int N,Map[501][2];
double dp[501][501][2];
bool steped[501][501][2];


double dis(int a,int b)
{
	return sqrt(double((Map[a][0]-Map[b][0])*(Map[a][0]-Map[b][0])+(Map[a][1]-Map[b][1])*(Map[a][1]-Map[b][1])));
}

double getmin(double a,double b)
{
	return a<b?a:b;
}


double calc(int a,int b,int flag)
{
	if(steped[a][b][flag]) return dp[a][b][flag];

	steped[a][b][flag]=true;

	if(a==b-1) return dp[a][b][flag]=dis(a,b);
	if(a>b-1) return 0;
	
	if(flag==0)
	{
		return	dp[a][b][flag]=getmin(calc(a+1,b,0)+dis(a,a+1),
								 calc(a+1,b,1)+dis(a,b));
	}
	else
		return dp[a][b][flag]=getmin(calc(a,b-1,0)+dis(b,a),
								 calc(a,b-1,1)+dis(b,b-1));
}

int main()
{
	/*
	Map[0][0]=Map[0][1]=0;
	Map[1][0]=Map[1][1]=2;
	printf("%f",dis(Map[0],Map[1]));*/
	int i,j;

	while(~scanf("%d",&N))
	{
		for(i=0;i<N;++i)	scanf("%d%d",Map[i],Map[i]+1);
		memset(steped,0,sizeof(steped));

		printf("%.2f\n",getmin(calc(1,N-1,0)+dis(0,1),calc(1,N-1,1)+dis(0,N-1)));
	}
}