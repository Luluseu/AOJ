#include <stdio.h>

int sushu[50];
void getsushu(int N)
{
	int len=1,n=3,i;
	sushu[0]=2;
	while (n<=N)
	{
		i=0;
		bool f=true;
		while (sushu[i]<n && i<len)
		{
			if (n%sushu[i]==0){f=false;break;}
			i++;
		}
		if(f) sushu[len++]=n;
		n++;
	}
}

int main()
{
	freopen("4.in","r",stdin);
	freopen("4.txt","w",stdout);
	int i;
	unsigned int N,r;
	getsushu(200);
	while(scanf("%u",&N),N)
	{
		r=1;i=0;
		while(r*sushu[i]<=N)
		{
			r*=sushu[i++];
		}
		printf("%u\n",r);
	}

}