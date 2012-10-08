#include <stdio.h>
#include <math.h>

int main()
{
	int n,i;
	double p,r=0,pp=1;
	scanf("%d%lf",&n,&p);

	for (i=0;i<n;++i)
	{
		pp*=p;
	}
	r+=pp;
	for(i=0;i<n-1;++i)
	{
		pp=pp*(1-p)*(n+i)/(i+1);
		r+=pp;
	}

	printf("%.6lf\n",r);
}