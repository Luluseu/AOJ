#include <iostream>
#include <queue>
#include <algorithm>
#include <set>
using namespace std;

class bridge
{
public:
	int a,b,w;
};

bool cmp(const bridge&a,const bridge&b)
{
	return a.a<b.a?true:false;
}

 int min(const int &a,const int &b)
{
	return a<b?a:b;
}
 int max(const int &a,const int &b)
{
	return a>b?a:b;
}

bridge B[5000];
int pos[101],n,m;

int dp(int p,set<int> pset)
{
//	cout<<"step>>"<<p<<endl;
	int i,max=-1,t,r;
	if (pos[p]!=-1)
	{
		return pos[p];
	}
	pset.insert(p);
	for (i=0;i<m;++i)
	{
		if (B[i].a==p&&!pset.count(B[i].b))
		{
			r=dp(B[i].b,pset);
			if (min(r,B[i].w)>max)
			{
				max=min(r,B[i].w);
			}
		}
		else if (B[i].b==p&&!pset.count(B[i].a))
		{
			r=dp(B[i].a,pset);
			if (min(r,B[i].w)>max)
			{
				max=min(r,B[i].w);
			}
		}
	}
//	cout<<"set"<<p<<":"<<max<<endl;
	//pos[p]=max;
	return max;
}

int main()
{
	freopen("1.txt","r",stdin);
	freopen("2.txt","w",stdout);
	int T,i,j;

	set<int> pset;

	cin>>T;
	for (i=0;i<T;++i)
	{
		cin>>n>>m;
		for (j=0;j<m;++j)
		{
			cin>>B[j].a>>B[j].b>>B[j].w;

		}
	//	sort(B,B+m,cmp);
		for (j=2;j<101;++j)
		{
			pos[j]=-1;
		}
		pos[1]=1000002;

		pset.clear();
		pset.insert(n);
		
		pos[n]=dp(n,pset);

		cout<<"Case #"<<i+1<<":"<<endl;
		cout<<pos[n]<<endl;
	/*	for (j=1;j<n+1;++j)
		{
			cout<<pos[j]<<" ";
		}
	*/


	}



}