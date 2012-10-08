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

void dp(int p,set<int> pset)
{
	//cout<<"step>>"<<p<<endl;
	if (p==n)
	{
		return ;
	}
	int i,max=-1,t,r;
	pset.insert(p);
	for (i=0;i<m;++i)
	{
		if (B[i].a==p&&!pset.count(B[i].b))
		{
			t=min(pos[p],B[i].w);
			if (pos[B[i].b]<t)
			{
				pos[B[i].b]=t;	
			}
			dp(B[i].b,pset);
			
		}
		else if (B[i].b==p&&!pset.count(B[i].a))
		{
			t=min(pos[p],B[i].w);
			if (pos[B[i].a]<t)
			{
				pos[B[i].a]=t;	
			}
			dp(B[i].a,pset);
			
		}
	}
	//cout<<"set"<<p<<":"<<max<<endl;
	//pos[p]=max;
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
		
		dp(1,pset);

		cout<<"Case #"<<i+1<<":"<<endl;
		cout<<pos[n]<<endl;
		for (j=1;j<n+1;++j)
		{
			cout<<pos[j]<<" ";
		}
	


	}



}