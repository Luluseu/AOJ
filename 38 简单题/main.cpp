#include <stdio.h>

int main()
{
	int h,u,d,t;
	while(scanf("%d%d%d",&h,&u,&d)!=EOF)
	{
		if (h==0)
		{
			break;
		}
		if (u>=h)
		{
			printf("1\n");
		}else
		{
			printf("%d\n",((h-u)/(u-d)+(((h-u)%(u-d))>0))*2+1);
		}
	}
	return 0;
}