#include <stdio.h>
#include <math.h>

int main()
{
	freopen("3.in","r",stdin);
	freopen("r.txt","w",stdout);
	int n;
	while (scanf("%d",&n),n)
	{
		printf("%d\n",((n-(1<<int(log(n+0.0)/log(2.0)+0.00000001)))<<1)+1);
	}
}