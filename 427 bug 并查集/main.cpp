#include <stdio.h>
#include <string.h>
int M,N;
int bingcha[2001];
int rev_sex[2001];
void init()
{
	int j;
	for (j=0;j<=N;++j)
	{
			bingcha[j]=j;
			rev_sex[j]=0;
	}
}
void unionit(int a,int b)
{
	int pa=a,pb=b;
	while (bingcha[pb]!=pb)
	{
		pb=bingcha[pb];
	}
	while (bingcha[pa]!=pa)
	{
		pa=bingcha[pa];
	}
	if (pa!=pb)
	{
		bingcha[pb]=pa;
	}
}
int find(int a)
{
	while (bingcha[a]!=a)
	{
		a=bingcha[a];
	}
	return a;
}

int main()
{
	int T,i,j,a,b;
	bool f=0;
	scanf("%d",&T);
	for (i=0;i<T;++i)
	{
		scanf("%d%d",&N,&M);
		init();
		f=0;
		for (j=0;j<M;++j)
		{
			scanf("%d%d",&a,&b);
			if (f)
			{
				continue;
			}
			if (find(a)==find(b))
			{
				f=1;
				continue;
			}

			if (rev_sex[a])
			{
				unionit(rev_sex[a],b);
			}else
			{
				rev_sex[a]=b;
			}
			if (rev_sex[b])
			{
				unionit(rev_sex[b],a);
			}else
			{
				rev_sex[b]=a;
			}		
		}

		printf("Scenario #%d:\n",i+1);
		if (f)
		{
			printf("Suspicious bugs found!\n\n");
		}else
		{
			printf("No suspicious bugs found!\n\n");
		}
	}
}