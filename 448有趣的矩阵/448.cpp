#include <stdio.h>

bool map[16][300];
bool cur[300];
int M,N;				//MÐÐ NÁÐ

void add(int n)
{
	int i;
	for (i=0;i<N;++i)
	{
		cur[i]|=map[n][i];
	}
}
bool  check(int n)
{
	for (int i=0;i<N;++i)
	{
		if (cur[i] && map[n][i])
		{
			return false;
		}
	}
	return true;
}
bool isOK()
{
	for (int i=0;i<N;++i)
	{
		if(cur[i]==false) return false;
	}
	return true;
}




bool dfs(int n)
{
	if (isOK())
	{
		return true;
	}
	if (n==M)
	{
		return false;
	}
	bool old[300];
	int i;
	for (i=0;i<N;++i)
		old[i]=cur[i];
	
	if (check(n))
	{
		add(n);
		if (dfs(n+1))
		{
			return true;
		}
		for (i=0;i<N;++i)
			cur[i]=old[i];
	}
	if (dfs(n+1))
	{
		return true;
	}
	return false;
	
	

}

int main()
{
	int i,j,t;
	while (scanf("%d%d",&M,&N)!=EOF)
	{
		for (i=0;i<M;++i)
		{
			for (j=0;j<N;++j)
			{
				scanf("%d",&t);
				if (t)
				{
					map[i][j]=1;
				}else map[i][j]=0;
			}
		}
		for (j=0;j<N;++j)
			cur[j]=0;
		if(dfs(0))
			printf("Yes, I found it\n");
		else
			printf("It is impossible\n");
	}
}