#include <stdio.h>
#include <iostream>
int main()
{
	freopen("1.txt","r",stdin);
	freopen("2.txt","w",stdout);
	char t;
	int n=0;
	while (t=getchar())
	{
		if (t==EOF)

		{
			if (n!=0)
			{printf("%d\n",n);
			}
			
			break;
		}

		if (t!='\n')
		{
			n++;
		}
		else
		{
			printf("%d\n",n);
			n=0;
		}
		

	}
	

}