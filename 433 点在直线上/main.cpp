#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

struct point { double x, y; };

point p0;

bool EQUAL(const double &a,const double &b)
{
	return a<b+10e-8 && a-b>-10e-8;
}

double DIS(const point &a,const point &b)
{
	double dx=b.x-a.x;
	double dy=b.y-a.y;
	return sqrt(dx*dx+dy*dy);
}

bool cmp(const point &a,const point &b)
{
	double ax=a.x-p0.x;
	double ay=a.y-p0.y;
	double bx=b.x-p0.x;
	double by=b.y-p0.y;
	
	if (EQUAL(ax*by,bx*ay))
	{
		return DIS(p0,a)<DIS(p0,b);
	}
	return bx*ay-ax*by>0;
}



bool theSameLine(point a,point b,point c)
{
	double acx=c.x-a.x;
	double acy=c.y-a.y;
	double abx=b.x-a.x;
	double aby=b.y-a.y;

	return EQUAL(acx*aby-acy*abx,0);
}

void SWAP(point &a,point &b)
{
	point t=a;
	a=b;
	b=t;
}




int main()
{
	int T,N,i,lab;
	point PT[1005],POUT[1005];
	cin>>T;
	while (T--)
	{
		cin>>N;


		

		for (i=0;i<N;++i)
		{
			cin>>PT[i].x>>PT[i].y;
			if (PT[i].y<p0.y ||(PT[i].y==p0.y && PT[i].x<p0.x) || i==0)
			{
				p0=PT[i];
				lab=i;
			}
		}
		if (N<6)
		{
			cout<<"NO"<<endl;
			continue;
		}
		SWAP(PT[0],PT[lab]);
		sort(PT+1,PT+N,cmp);	


		//ÅÐ¶Ï×îºóÒ»±ß
		int lim;
		int num=0;
		bool preInLine=false;
		bool flg=true;
		if (!theSameLine(p0,PT[N-1],PT[N-2]))
		{
			flg=false;
		}else
		{
			lim=N-2;
			while (theSameLine(p0,PT[lim],PT[lim-1]))
			{
				lim--;
				if (lim==0)
				{
					break;
				}
			}
			reverse(PT+lim,PT+N);
		}

		if (lim<2)
		{
			cout<<"NO"<<endl;
			continue;
		}


		for (i=0;i<=lim-1;++i)
		{
			//cout<<"ÅÐ¶Ï±ß"<<PT[i].x<<","<<PT[i].y<<" "<<PT[i+1].x<<","<<PT[i+1].y<<" "<<PT[i+2].x<<","<<PT[i+2].y<<endl;
			if (theSameLine(PT[i],PT[i+1],PT[(i+2)%N]))
			{
				preInLine=true;
			}else if (preInLine)
			{
				preInLine=false;
				//i++;
			}else
			{
				flg=false;
			
				break;
			}

		}

		if (flg)
		{
			cout<<"YES"<<endl;
		}else
			cout<<"NO"<<endl;
	

	}
}