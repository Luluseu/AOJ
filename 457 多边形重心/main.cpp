#include <cstdio>

struct point { double x, y; };
point bcenter(point pnt[], int n){
	point p, s;
	double tp, area = 0, tpx = 0, tpy = 0;
	p.x = pnt[0].x; p.y = pnt[0].y;
	for (int i = 1; i <= n; ++i) { // point: 0 ~ n-1
		s.x = pnt[(i == n) ? 0 : i].x;
		s.y = pnt[(i == n) ? 0 : i].y;
		tp = (p.x * s.y - s.x * p.y); area += tp / 2;
		tpx += (p.x + s.x) * tp; tpy += (p.y + s.y) * tp;
		p.x = s.x; p.y = s.y;
	}
	s.x = tpx / (6 * area); s.y = tpy / (6 * area);
	return s;
}

point PP[1000005];
int main()
{
	int T,N,i;
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&N);
		for (i=0;i<N;++i)
		{
			scanf("%lf%lf",&PP[i].x,&PP[i].y);
		}
		point p=bcenter(PP,N);
		printf("%.2lf %.2lf\n",p.x,p.y);
	}
}
