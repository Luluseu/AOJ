#include <cstdio>
int main()
{
	int n,m,i,r;
	while (~scanf("%d%d",&n,&m))
	{
		int num=n,i,t=0;
		bool Q[1001]={0};
		i=0;
		while (num)
		{
			if (!Q[i])
			{
				t++;
				if (t==m)
				{
					Q[i]=1;
				/*	if (num==1)
					{
						printf("%d\n",i+1);
						break;
					}*/
					printf("%d ",i+1);
					num--;
					t=0;
				}
			}
			i=(i+1)%n;	
		}
		printf("\n\n");
	}
}