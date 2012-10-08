#include <stdio.h>
#include <math.h>
int map[250][250],min[250][250][8],max[250][250][8];
int N,B,K;

int getmax(int a,int b,int c,int d)
{
	int r=a;
	if (b>r) r=b;
	if (c>r) r=c;
	if (d>r) r=d;
	return r;
}
int getmin(int a,int b,int c,int d)
{
	int r=a;
	if (b<r) r=b;
	if (c<r) r=c;
	if (d<r) r=d;
	return r;
}
void RMQ()
{
	int i,j,k;
	for(i=0;i<N;++i) for (j=0;j<N;++j) 
	{
		max[i][j][0]=map[i][j];
		min[i][j][0]=map[i][j];
	}
	for(i=1;i<log((double)N)/log(2.0);++i)
	{
		for(j=0;j<=N-pow(2.0,i)+0.1;++j)
		{
			for(k=0;k<N-pow(2.0,i)+0.1;++k)
			{
				max[j][k][i]=getmax(max[j][k][i-1],max[j+(1<<(i-1))][k][i-1],max[j][k+(1<<(i-1))][i-1],max[j+(1<<(i-1))][k+(1<<(i-1))][i-1]);
				min[j][k][i]=getmin(min[j][k][i-1],min[j+(1<<(i-1))][k][i-1],min[j][k+(1<<(i-1))][i-1],min[j+(1<<(i-1))][k+(1<<(i-1))][i-1]);
			}
		}
	}
}

int main()
{
	int i,j,k,x,y;

	scanf("%d%d%d",&N,&B,&K);
	for (i=0;i<N;++i) for (j=0;j<N;++j) scanf("%d",map[i]+j);

	RMQ();

	for (i=0;i<K;++i)
	{
		scanf("%d%d",&x,&y);
		x--;y--;
		int half=log((double)B)/log(2.0)+0.1;
		printf("%d\n",getmax(max[x][y][half],max[x+B-(1<<half)][y][half],max[x][y+B-(1<<half)][half],max[x+B-(1<<half)][y+B-(1<<half)][half])
			-getmin(min[x][y][half],min[x+B-(1<<half)][y][half],min[x][y+B-(1<<half)][half],min[x+B-(1<<half)][y+B-(1<<half)][half]));
	}

}