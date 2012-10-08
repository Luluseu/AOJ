#include <string.h>
#include <stdio.h>

int main()
{
	int i,j,size1,size2,dp[2][1000],sum,pre,cur,ans;
	char s[10]="hello",str[1001];
	size1=strlen(s);

	while (~scanf("%s",str))	{		size2=strlen(str);		memset(dp,0,sizeof(dp));		for (i=0;i<size1;++i)		{						pre=(i+1)%2;			cur=i%2;			if (i==0) sum=1;			else sum=0;			for (j=0;j<size2;++j)			{				if (str[j]==s[i])
				{
					dp[cur][j]=sum;
				}else					dp[cur][j]=0;				sum+=dp[pre][j];			}		}		ans=0;		for (i=0;i<size2;++i)
		{
			ans+=dp[cur][i];
		}				printf("%d\n",ans);	}


}