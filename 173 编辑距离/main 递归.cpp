#include <cstdio>
#include <cstring>

int dp[1028][1028];
char s1[1028],s2[1028];

inline int mymin(int a,int b,int c)
{
	int t=a<b?a:b;
	return t<c?t:c;
} 

int go(int p1,int p2)
{
	if (p1==-1) return p2+1;
	if (p2==-1) return p1+1;
	if (dp[p1][p2]!=-1)
		return dp[p1][p2];
	if (s1[p1]==s2[p2]) return dp[p1][p2]=go(p1-1,p2-1);
	return dp[p1][p2]=mymin(go(p1-1,p2-1),go(p1,p2-1),go(p1-1,p2))+1;
	
}
int main()
{
	int i,j,len1,len2;
	while(~scanf("%s%s",s1,s2))
	{
		len1=strlen(s1);len2=strlen(s2);
		memset(dp,-1,sizeof(dp));
		printf("%d\n",go(len1-1,len2-1));
	}
	
}