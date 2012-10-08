#include <stdio.h>
int N,K;
int MAX[1000001][2],top1,bottom1;
int MIN[1000001][2],top2,bottom2;
int R1[1000001],R2[1000001];

void inline push1(const int &k,const int &a)
{
	while(top1>bottom1)
	{
		if (a<MAX[top1-1][0])
		{
			MAX[top1][0]=a;
			MAX[top1++][1]=k;
			return;
		}
		top1--;
	}
	MAX[top1][0]=a;
	MAX[top1++][1]=k;
}
void inline pop1(const int &k)
{
	if (MAX[bottom1][1]<=k)
	{
		bottom1++;
	}
}
void inline pop2(const int &k)
{
	if (MIN[bottom2][1]<=k)
	{
		bottom2++;
	}
}
void inline push2(const int &k,const int &a)
{
	while(top2>bottom2)
	{
		if (a>MIN[top2-1][0])
		{
			MIN[top2][0]=a;
			MIN[top2++][1]=k;
			return;
		}
		top2--;
	}
	MIN[top2][0]=a;
	MIN[top2++][1]=k;
}

int main()
{
	int i,t;

	scanf("%d%d",&N,&K);
	for (i=0;i<K;++i)
	{
		scanf("%d",&t);
		push1(i,t);
		push2(i,t);
	}
	R1[0]=MAX[bottom1][0];
	R2[0]=MIN[bottom2][0];
	for (i=1;i<N-K+1;++i)
	{
		scanf("%d",&t);
		push1(K+i-1,t);
		push2(K+i-1,t);
		pop1(i-1);
		pop2(i-1);
		R1[i]=MAX[bottom1][0];
		R2[i]=MIN[bottom2][0];

	}
	for (i=0;i<N-K;++i)
	{
		printf("%d ",R2[i]);
	}
	printf("%d\n",R2[i]);
	for (i=0;i<N-K;++i)
	{
		printf("%d ",R1[i]);
	}
	printf("%d",R1[i]);
	scanf("%d",&t);
	return 0;
}