
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
const double oo=1e-11;
int p,q,a,n;
int ans;
void dfs(int start,double sum,int pp,int rem)
{
	int i;
	if(sum<-1*oo)return;
	if(sum<=oo&&sum>=-1*oo)
	{
		ans++;
		return;
	}
	else
	{
		for(i=start;rem*1.0/i>=sum-oo&&i*pp<=a;i++)
		{
				dfs(i,sum-1*1.0/i,i*pp,rem-1);
		}
	}
}
int main()
{
		while(scanf("%d%d%d%d",&p,&q,&a,&n)!=EOF)
		{
		if(p==0&&q==0)
		break;
		ans=0;
		dfs(1,p*1.0/q,1,n);
		printf("%d\n",ans);
		}
	return 0;
}