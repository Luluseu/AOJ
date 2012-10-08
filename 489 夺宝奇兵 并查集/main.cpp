/*
2010-11-29 12:38
*/
#include <iostream>
#include <cstdio>
using namespace std;

#define MAXN 1000005

int A[MAXN];
int UFS[MAXN];

void UFS_init(int n)
{
	for (int i=1;i<=n;++i) UFS[i]=i;
}
/*
int UFS_Father(int a)
{
	while (UFS[a]!=a) a=UFS[a];
	return a;
}*/
int UFS_Father(int a)
{
	if (UFS[a]==a)
	{
		return a;
	}
	return UFS[a]=UFS_Father(UFS[a]);
}
bool UFS_same(int a,int b)
{
	return UFS_Father(a)==UFS_Father(b);
}

void UFS_union(int a,int b)	//union a to b
{
	int k,l;
	k=UFS_Father(a);
	l=UFS_Father(b);
	if (k!=l)
	{
		UFS[k]=l;
	}
}

int main()
{
	int N;
	scanf("%d",&N);
	for (int i=1;i<=N;++i)
	{
		scanf("%d",A+i);
	}

	UFS_init(N);
	for (int j=1;j<=N;++j)
	{
		UFS_union(A[j],j);	
	}
	int num=0;
	for (int k=1;k<=N;++k)
	{
		if (UFS[k]==k)
		{
			num++;
		}
	}

	printf("%d\n",num);
}