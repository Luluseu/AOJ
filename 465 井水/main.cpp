#include <stdio.h>
#include <queue>

using namespace std;

int Map[301][301];
bool can[301][301];
int N,M;

class point
{
public:
	int x,y,v;
	point(int a=0,int b=0,int c=0):x(a),y(b),v(c){}
};

bool operator < (const point& a,const point &b)
{
	return a.v>b.v;
}

void input()
{
	int i,j;
	scanf("%d%d",&M,&N);
	for (i=0;i<N;++i)
	{
		for (j=0;j<M;++j)
		{
			scanf("%d",&Map[i][j]);
			can[i][j]=0;
		}
	}
}

int proc()
{
	int i;
	int sum=0;
	priority_queue<point> Q;

	for (i=0;i<N;++i)
	{
		can[i][0]=1;
		can[i][M-1]=1;
		Q.push(point(i,0,Map[i][0]));
		Q.push(point(i,M-1,Map[i][M-1]));
	}
	for (i=1;i<M-1;++i)
	{
		can[0][i]=1;
		can[N-1][i]=1;
		Q.push(point(0,i,Map[0][i]));
		Q.push(point(N-1,i,Map[N-1][i]));
	}
	
	while(!Q.empty())
	{
		point p=Q.top();
		Q.pop();

		if (p.x>0)
		{
			if (!can[p.x-1][p.y])
			{
				can[p.x-1][p.y]=1;
				if (p.v>Map[p.x-1][p.y])
				{
					sum+=p.v-Map[p.x-1][p.y];
					Q.push(point(p.x-1,p.y,p.v));
				}else
				{
					Q.push(point(p.x-1,p.y,Map[p.x-1][p.y]));
				}
			}
			
		}
		if (p.y>0)
		{
			if(!can[p.x][p.y-1])
			{
				can[p.x][p.y-1]=1;
				if (p.v>Map[p.x][p.y-1])
				{
					sum+=p.v-Map[p.x][p.y-1];
					Q.push(point(p.x,p.y-1,p.v));
				}else
				{
					Q.push(point(p.x,p.y-1,Map[p.x][p.y-1]));
				}
			}
			
		}
		if (p.x<N-1)
		{
			if (!can[p.x+1][p.y])
			{
				can[p.x+1][p.y]=1;
				if (p.v>Map[p.x+1][p.y])
				{
					sum+=p.v-Map[p.x+1][p.y];
					Q.push(point(p.x+1,p.y,p.v));
				}
				else
				{
					Q.push(point(p.x+1,p.y,Map[p.x+1][p.y]));
				}
			}	
		}
		if (p.y<M-1)
		{
			if (!can[p.x][p.y+1])
			{
				can[p.x][p.y+1]=1;
				if (p.v>Map[p.x][p.y+1])
				{
					sum+=p.v-Map[p.x][p.y+1];
					Q.push(point(p.x,p.y+1,p.v));
				}
				else
				{
					Q.push(point(p.x,p.y+1,Map[p.x][p.y+1]));
				}
			}	
		}
	}

	return sum;
}

int main()
{
	//freopen("1.txt","r",stdin);
	input();
	printf("%d\n",proc());
}
