#include <stdio.h>
#include <math.h>
#define O 0.0000000001
#define O2 0.000001
double a,n,c,b;

double deg(double a,double b)
{
	double begin=0,end=3.14159265358979/2;
	double th0,cha;

	while (1)
	{
		th0=(begin+end)/2;
		cha=sin(th0)*b-th0*a;
		if (cha < O2 && cha > (-1.0)*O2)
		{
			return th0;
		}
		if (cha < O2)
		{
			end=th0;
		}else
		{
			begin=th0;
		}
	}
}

int main()
{
	double degree,R;
	while (1)
	{
		scanf("%lf%lf%lf",&a,&n,&c);
		if (a > (-1-1.0*O) && a < (-1+O))
		{
			break;
		}
		
		b=(1.0+n*c)*a;
		if (a-b < O && b-a < O)
		{
			printf("0.000\n");
			continue;
		}
		degree=deg(a,b);
		R=b/2/degree;
		printf("%.3lf\n",R-R*cos(degree));
	}
}