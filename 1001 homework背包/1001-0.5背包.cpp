#include <iostream>
using namespace std;


class cheet
{
public:
	int t,v;
};

int n,m;
cheet a[20];

double dp(double weigth,int step)
{
	double t,max;
	if (step>=n-1)
	{
		return weigth>=a[step].t?a[step].v:0;
	}
//choosed
	if (weigth>a[step].t)
	{
		max=a[step].v+dp(weigth-a[step].t,step+1);
	}
	else
		max=0;
//unchoosed
	t=dp(weigth,step+1);

	return t>max?t:max;
}

int main()
{
	int i,j;
	cin>>n>>m;
	while(n!=0&&m!=0)
	{
		for (i=0;i<n;++i)
		{
			cin>>a[i].t>>a[i].v;
		}
//		cout.setf(ios::fixed);
		cout/*<<setprecision(3)*/<<dp(m,0);
//
		cin>>n>>m;
	}
}