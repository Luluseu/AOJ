
#include <stdio.h>


int main()
{
	long n,i;
	while (1)
	{
		scanf("%d",&n);
		if (n==0)	break;
		i=0;
		while(n/5>0)
		{
			i+=n/5;
			n/=5;
		}
		
		printf("%d\n",i);
	}
}