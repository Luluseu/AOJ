#include <stdio.h>

int main()
{
	int c1,c2,m1,m2,i,j,p1,p2,r;
	while (~scanf("%d%d%d%d",&c1,&c2,&m1,&m2))
	{
		if (m1==0 || c1==0)
		{
			r=c2<m2?c2:m2;
			printf("%d\n",r);
			continue;
		}
		if (m2==0 || c2==0)
		{
			r=c1<m1?c1:m1;
			printf("%d\n",r);
			continue;
		}
		p1=c1/m1+((c1%m1)>0?1:0);p2=c2/m2+((c2%m2)>0?1:0);

		if (p1<=c2+1 && p1>=p2-1 || (p2<=c1+1 && p2>=p1-1))
		{
			r=c1+c2;
			printf("%d\n",r);
			continue;
		}


		if (p1>c2)
		{
			r=c2+(c2+1)*m1;
		}
		if (p2>c1)
		{
			r=c1+(c1+1)*m2;
		}
		printf("%d\n",r);
	}
}
