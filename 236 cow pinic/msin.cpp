#include <stdio.h>
#include <string.h>

int K,N,M;
int P[105];
bool Map[1005][1005];
int R[1005];
bool steped[1005];


void bfs(int s)
{
	int i;
	for (i=1;i<=N;++i)
	{
		if (!steped[i] && Map[s][i])
		{
			R[i]++;
			steped[i]=true;
			bfs(i);
		}
	}
}

void search(int start)
{
	memset(steped,0,sizeof(steped));

	R[start]++;
	steped[start]=true;
	bfs(start);
}

int main()
{
	int i,a,b,ans=0;
	scanf("%d%d%d",&K,&N,&M);
	for(i=0;i<K;++i)
		scanf("%d",P+i);
	for(i=0;i<M;++i)
	{
		scanf("%d%d",&a,&b);
		Map[a][b]=true;
	}
	for (i=0;i<K;++i)
	{
		search(P[i]);
	}
	for (i=1;i<=N;++i)
	{
		if (R[i]==K)
		{
			ans++;
		}
	}
	printf("%d\n",ans);
}