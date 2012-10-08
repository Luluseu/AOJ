#include <cstdio>
#include <cstring>

int dp[1028][1028];
char s1[1028],s2[1028];

inline int mymin(int a,int b,int c)
{
	int t=a<b?a:b;
	return t<c?t:c;
} 

int mmin(int a,int b)
{
	return a<b?a:b;
}

int main()
{
	int i,j,len1,len2;
	while(~scanf("%s%s",s1,s2))
	{
		len1=strlen(s1);len2=strlen(s2);
	//	memset(dp,-1,sizeof(dp));
		for (i=0;i<=len1;++i) dp[i][0]=i;
		for (i=0;i<=len2;++i) dp[0][i]=i;
		for (i=1;i<=len1;++i)
		{
			for (j=1;j<=len2;++j)
			{
				if (s1[i-1]==s2[j-1])
				{
					dp[i][j]=dp[i-1][j-1];
				}else
				{
					dp[i][j]=mymin(dp[i-1][j-1],dp[i-1][j],dp[i][j-1])+1;
				}
			}
		}
		printf("%d\n",dp[len1][len2]);
	}
	
}