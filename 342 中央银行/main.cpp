#include <stdio.h>
#include <math.h>

int dp[500001];
int m[101],N,MAX;

int main()
{
	int i,j,ooo;
	double value=0;

	scanf("%d%d",&N,&MAX);
	for(i=0;i<N;i++) {scanf("%d",m+i);dp[m[i]]=1;}
	for(i=0;i<N;++i)
	{
		for(j=m[i]+1;j<=MAX;++j)
		{
			if(dp[j-m[i]] !=0  && (dp[j] > dp[j-m[i]]+1 || dp[j]==0))
			{
				dp[j]=dp[j-m[i]]+1;
			}
		}
	}
	for (i=1;i<=MAX;++i)
	{
		if ((ooo=dp[i])>100)
		{
			ooo=100;
		}
		if (ooo==0)  continue; 
		value+=1/(double)ooo;
	}

	printf("%.4f\n",1/log(double(N+1))*log(2.0)/log(MAX+1.71828)*value);
}