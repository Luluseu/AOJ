#include <stdio.h>
int p,q,a,std_n;
int solve;
double ans;

//sum 当前和  begin分母开始值  n当前第几个分数
void dfs(double sum,int begin,int n,int sq)
{
	int i,j,lim=1;
	//if(n>std_n) return;
	lim=a/sq;
	for (i=begin;i<=lim;++i)
	{
		if ( sum+1.0/i-ans > 10e-10 ) 	continue;
		
		if (sum+1.0/i-ans< 10e-10 && sum+1.0/i-ans> -10e-10)
		{
			solve++;
			continue;
		}		
		
		if(n<std_n )
		{
			if((std_n-n+1)*1.0/i < (ans-sum)- 10e-10) break;
			dfs(sum+1.0/i,i,n+1,sq*i);
		}

	}
}
int main()
{
	int i;
	while (1)
	{	
		scanf("%d%d%d%d",&p,&q,&a,&std_n);
		if (p==0)	break;
		solve=0;
		ans=(double)p/q;
		
		dfs(0,1,1,1);		
		printf("%d\n",solve);
	}
	return 0;
}

