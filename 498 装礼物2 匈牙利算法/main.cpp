#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace  std;

#define  MAXN 201

bool Map[MAXN][MAXN],steped[MAXN];
int A[MAXN],B[MAXN],N1,N2;
int G[MAXN][3],BB[MAXN][3];

bool dfs(int s)
{
	int i;
	for (i=0;i<N2;i++)
	{
		if (Map[s][i] && !steped[i])
		{
			steped[i]=true;
			if (B[i]==-1 || dfs(B[i]))
			{
				A[s]=i;
				B[i]=s;
				return true;
			}
		}
	}
	return false;
}

int hungary()
{
	int i,ans=0;
	memset(A,-1,sizeof(A));memset(B,-1,sizeof(B));
	for (i=0;i<N1;++i)
	{
		memset(steped,0,sizeof(steped));
		if (dfs(i)) ans++;
	}
	return ans;
}

inline void sort(int a[])
{
	int t;
	if (a[0]<a[1])
	{
		t=a[0];
		a[0]=a[1];
		a[1]=t;
	}
	if (a[0]<a[2])
	{
		t=a[0];
		a[0]=a[2];
		a[2]=t;
	}
	if (a[1]<a[2])
	{
		t=a[1];
		a[1]=a[2];
		a[2]=t;
	}
}
void input()
{
	int i;
	for(i=0;i<N1;++i)
	{
		scanf("%d%d%d",&G[i][0],&G[i][1],&G[i][2]);
		sort(G[i]);	
	}
	for(i=0;i<N2;++i)	
	{
		scanf("%d%d%d",&BB[i][0],&BB[i][1],&BB[i][2]);
		sort(BB[i]);
	}
}

void createmap()
{
	int i,j;
	memset(Map,0,sizeof(Map));
	for(i=0;i<N1;++i)
	{
		for(j=0;j<N2;++j)
		{
			if(G[i][0]<=BB[j][0]&&G[i][1]<=BB[j][1]&&G[i][2]<=BB[j][2])
			{
				Map[i][j]=true;
			}
		}
	}
}

int main()
{
	while(cin>>N1>>N2,N1)
	{
		input();
		createmap();
		printf("%d\n",hungary());
	}
	return 0;
}