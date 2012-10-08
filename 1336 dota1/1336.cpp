#include <stdio.h>

int main()
{
	int n,hp1,dps1,hp2,dps2,i,t1,t2;
	scanf("%d",&n);
	for (i=0;i<n;++i)
	{	
		scanf("%d %d %d %d",&hp1,&dps1,&hp2,&dps2);
		if (dps1==0)
		{
			printf("Run away!\n");
		}
		else
		if (dps2==0)
		{
			printf("Kill him!\n");
		}
		else
		{
			t1=hp2/dps1+(hp2%dps1>0);
			t2=hp1/dps2+(hp1%dps2>0);
			if (t1>=t2)
			{
				printf("Run away!\n");
			}
			else printf("Kill him!\n");

		}
		
	}
	return 0;
}