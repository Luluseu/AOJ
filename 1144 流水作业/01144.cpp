#include <stdio.h>
#include <memory.h>
#include <algorithm>
using namespace std;

const int MAXN=10005;

struct TNode
{
	int s1,s2;
}ws[MAXN];

int topf,tops;
int n;

bool operator<(TNode x,TNode y)
{
	if (x.s1<x.s2&&y.s1>=y.s2) return true;
	if (x.s1<x.s2&&y.s1<y.s2) return x.s1<y.s1;
	if (x.s1>=x.s2&&y.s1>=y.s2) return x.s2>y.s2;
	return false;
}

int max(int x,int y)
{
	return x>y?x:y;
}

void Work()
{
	sort(ws,ws+n);
	int i,t1=0,t2=0;
	for (i=0;i<n;i++)
	{
		t1+=ws[i].s1;
		t2=max(t1,t2)+ws[i].s2;
	}
	printf("%d\n",t2);
}

void Read()
{
	int i;
	while (scanf("%d",&n)&&n)
	{
		for (i=0;i<n;i++)
			scanf("%d%d",&ws[i].s1,&ws[i].s2);
		Work();
	}
}

int main()
{
	Read();
	return 1;
}