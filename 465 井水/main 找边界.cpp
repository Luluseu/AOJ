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

void input()
{
	int i,j;
	scanf("%d",&M,&N);
	for (i=0;i<N;++i)
	{
		for (j=0;j<M;++j)
		{
			scanf("%d",Map[i][j]);
			can[i][j]=1;
		}
	}
}

void findbound()
{
	int i;
	queue<point> Q;
	point p;

	for (i=0;i<N;++i)
	{
		can[i][0]=0;
		can[i][M-1]=0;
		Q.push(point(i,0,Map[i][0]));
		Q.push(point(i,M-1,Map[i][M-1]));
	}
	for (i=0;i<M;++i)
	{
		can[0][i]=0;
		can[N-1][i]=0;
		Q.push(point(0,i,Map[0][i]));
		Q.push(point(N-1,i,Map[N-1][i]));
	}
	
	while(!Q.empty())
	{
		p=Q.front();
		Q.pop();

		if (p.x>0)
		{
			if (Map[p.x][p.y]<Map[p.x-1][p.y])
			{
				can[p.x-1][p.y]=0;
				Q.push(point(p.x-1,p.y,Map[p.x-1][p.y]));
			}
		}
		if (p.y>0)
		{
			if (Map[p.x][p.y]<Map[p.x][p.y-1])
			{
				can[p.x][p.y-1]=0;
				Q.push(point(p.x-1,p.y,Map[p.x-1][p.y]));
			}
		}
	}


}

int main()
{

}
