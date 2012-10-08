#include <stdio.h>
#include <stdlib.h>
main()
{
	int a[10000],b[10000],n,i,j,max;
	b[0]=1;
	while(scanf("%d",&n)!=EOF)
	{
		for(i=0;i<n;++i)
		{
			scanf("%d",a+i);                
		}
		
		for(i=0;i<n;++i)
		{
			max=0;
			for(j=0;j<i;++j)
			{
				if(a[j]<a[i])
					if(max<b[j])
						max=b[j];                
			}
			b[i]=max+1;               
		}
		max=0;
		for(i=0;i<n;++i)
		{
			
		//	printf("%d ",b[i]);
			if(max<b[i])
				max=b[i];                
			
		}
		
		printf("%d\n",max);
	}
}