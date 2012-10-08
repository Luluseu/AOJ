#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;


class cheet
{
public:
	int t,v;
};

int n,m;
cheet a[20];

bool cmp(const cheet& a,const cheet& b)
{
	return (double)a.v/a.t>(double)b.v/b.t?1:0;
}

int main()
{
	int i,j,t;
	double sum;
	cin>>n>>m;
	while(n!=0&&m!=0)
	{
		for (i=0;i<n;++i)
		{
			cin>>a[i].t>>a[i].v;
		}
		
		sort(a,a+n,cmp);
		sum=0;t=0;
		for (i=0;i<n;++i)
		{
			if (t+a[i].t<=m)
			{
				sum+=a[i].v;
				t+=a[i].t;
			}
			else
			if (t==m)
			{
				break;
			}
			else
			{
				sum+=(double)a[i].v*(m-t)/a[i].t;
				break;
			}
		}

		cout.setf(ios::fixed);
		cout<<setprecision(2)<<sum<<endl;

		cin>>n>>m;
	}
}