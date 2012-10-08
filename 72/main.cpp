#include <stdio.h>

int main()
{
	int T,a,b,h;
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d%d%d",&a,&b,&h);
		printf("%.2f\n",(double)h*b/a);
	}
}