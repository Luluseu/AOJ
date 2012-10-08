#include <stdio.h>

struct edge
{
	double ax,ay,bx,by;
};
struct point
{
	double x,y;
};

//存储边
edge E[105];
point P[105];
int N,M;		//N边数也是点数,M待测点数

void readE()
{
	int i;
	for(i=0;i<N;++i)
		scanf("%lf%lf",&P[i].x,&P[i].y);
	for (i=0;i<N-1;++i)
	{
		E[i].ax=P[i].x;
		E[i].ay=P[i].y;
		E[i].bx=P[i+1].x;
		E[i].by=P[i+1].y;
	}
	E[N-1].ax=P[N-1].x;
	E[N-1].ay=P[N-1].y;
	E[N-1].bx=P[0].x;
	E[N-1].by=P[0].y;
}
bool EQU(const double &a,const double &b)
{
	return a-b> - 10e-8 && a-b < 10e-8;
}
bool LESS(const double &a,const double &b)
{
	return a< b-10e-8;
}
bool GREATER(const double &a,const double &b)
{
	return a > b +10e-8;
}
// 0 不相交 1交叉  2 交1上 3 交2上 4交1下 5交2下  6覆盖
int hor_cross_seg(point o,edge e)
{
	if (EQU(o.y,e.ay) && EQU(o.y,e.by))
	{
		if(o.x < e.ax-10e-8 && o.x < e.bx-10e-8)
			return 6;
		else return 0;
	}
	//上
	if (LESS(o.x,e.ax)&&EQU(o.y,e.ay)&& GREATER(o.y,e.by) )
	{
		return 2;
	}
	if(LESS(o.x,e.bx)&&EQU(o.y,e.by)&& GREATER(o.y,e.ay)) 
		return 3;
	//下
	if (LESS(o.x,e.ax)&&EQU(o.y,e.ay)&& LESS(o.y,e.by))
	{
		return 4;
	}
	if (LESS(o.x,e.bx) && EQU(o.y,e.by)&& LESS(o.y,e.ay))
	{
		return 5;
	}
	//交叉
	if (EQU(e.by,e.ay)&& !EQU(o.y,e.ay))
	{
		return 0;
	}
	if (GREATER(e.ay,o.y)  && GREATER(e.by,o.y) ||(LESS(e.ay,o.y)  && LESS(e.by,o.y)))
	{
		return 0;
	}
	double x=(o.y-e.ay)/(e.by-e.ay)*(e.bx-e.ax)+e.ax;
	if (x>o.x)
	{
		return 1;
	}
	return 0;

}
bool testPoint(point t)
{
	int i,num=0;
	int laststatus,curst;
	laststatus=hor_cross_seg(t,E[N-1]);
	for (i=0;i<N;++i)
	{
		curst=hor_cross_seg(t,E[i]);
		if (curst==0)
		{
			laststatus=curst;
		}else
		if (curst==1)
		{
			laststatus=curst;
			++num;
		}else
		if (curst==2)
		{
			if(laststatus==5)  ++num;
			laststatus=curst;
		}else
		if (curst==3)
		{
			laststatus=curst;
		}else
		if (curst==4)
		{
			if(laststatus==3)  ++num;
			laststatus=curst;
		}else
		if (curst==5)
		{
			laststatus=curst;
		}
	}

	return num%2;
}

int calc()
{
	int i,sum=0;
	point t;
	for (i=0;i<M;++i)
	{
		scanf("%lf%lf",&t.x,&t.y);
		if(testPoint(t))
			sum++;
	}
	return sum;
}



int main()
{
	while (scanf("%d",&N),N!=0)
	{
		readE();
		scanf("%d",&M);
		printf("%d\n",calc());

	}
}