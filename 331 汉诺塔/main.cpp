#include <stdio.h>

int b[35];

int get(int n)
{/*
	if (n==0)		return 1;
	if (n&1)
	{
		int r=get(n>>1);
		return r*r*2%9973;
	}else
	{
		int r=get(n>>1);
		return r*r%9973;
	}*/
	int r=1,i=0;
	while (n)
	{
		if(n&1)
		{
			r*=b[i];
			r%=9973;
		}
		n>>=1;
		i++;
	}
	return r;
}

int main()
{
	int n,i;
	b[0]=2;
	for (i=1;i<35;++i)
	{
		b[i]=b[i-1]*b[i-1]%9973;
	}
	while (scanf("%d",&n),n)
	{
		if (n>0)
		{
			printf("%d\n",(get(n)+9972)%9973);
		}

	}
}