#include <stdio.h>

int main()
{
	int x1,x2,y1,y2,x,y,ans,a;
	while (~scanf("%d%d%d%d",&x1,&y1,&x2,&y2))
	{
		x=x1-x2;
		y=y1-y2;
		if (x<0) x=-x;
		if (y<0) y=-y;
		if(x>y) {x1=x;x=y;y=x1;}
		ans=0;

		if(x>y/2.0)	//¿¿Ð±Ïß
		{
			ans+=-x+y;
			x=2*x-y;
			y=x;
			ans+=x/3*2;
			x=x%3;
			switch(x)
			{
				case 0: break;
				case 1: ans+=2;break;
				case 2: ans+=3;break;
			}
		}else if (x==y/2 && y%2==0)
		{
			ans=x;
		}else	//¿¿ÊúÏß
		{
			ans+=x;
			x=0;
			y=y-x*2;
			ans+=y/4;
			y=y%4;
			switch(y)
			{
			case 0:break;
			case 1:ans+=3;break;
			case 2:ans+=2;break;
			case 3:ans+=3;break;
			}

		}
		printf("%d\n",ans);

	}
}