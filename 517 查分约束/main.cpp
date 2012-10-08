#include <stdio.h>
#include <string.h>
#include <vector>
#include <queue>

using namespace  std;

#define  MAXN 1005
struct edge
{
	int a,b,v;
};
struct pd
{
	int id;
};

int N=0;

vector<edge> E[MAXN];
int DIS[MAXN];
int HASH[MAXN],ANTIHASH[MAXN];
edge adj[MAXN];
bool inque[MAXN];


int spfa(int start,int end)
{
	queue<pd> Q;
	pd t;
	int i;

	t.id=0;
	Q.push(t);
	inque[0]=true;
	DIS[0]=0;
	while (!Q.empty())
	{
		pd p=Q.front();
		Q.pop();
		inque[p.id]=false;
		
		for (i=0;i<E[p.id].size();++i)
		{
			t.id=E[p.id][i].b;
			if (DIS[E[p.id][i].a]+E[p.id][i].v > DIS[t.id])
			{
				if(!inque[t.id])
						Q.push(t);
				inque[t.id]=true;
				DIS[t.id]=DIS[E[p.id][i].a]+E[p.id][i].v;
			}

		}

	}
	return DIS[end];
}

int main()
{
	int i,j,n,a,b,v,end=0;
	edge e,e0={0,0,0};
	scanf("%d",&n);

	for(i=0;i<n;++i)
	{
		scanf("%d%d%d",&e.a,&e.b,&e.v);
		e.b++;
		HASH[e.a]=HASH[e.b]=1;
		adj[i]=e;
	}
	for (i=0;i<MAXN;++i)
	{
		if (HASH[i])
		{
			HASH[i]=++N;
			ANTIHASH[N]=i;
		}
	}

	memset(DIS,-1,sizeof(DIS));
	for (i=1;i<=N;++i)
	{
		for (j=1;j<i;++j)
		{
			e.a=i;
			e.b=j;
			e.v=ANTIHASH[j]-ANTIHASH[i];
			E[e.a].push_back(e);
			e.a=j;
			e.b=i;
			e.v=0;
			E[e.a].push_back(e);
		}
	}
	for (i=0;i<n;++i)
	{
		e=adj[i];
		e.a=HASH[e.a];
		e.b=HASH[e.b];
		E[e.a].push_back(e);
		e.b=e.a;
		e.a=0;
		e.v=0;
		E[e.a].push_back(e);
	}

	printf("%d\n",spfa(0,N));
}