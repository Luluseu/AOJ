#include <iostream>
#include <set>

using namespace std;

int G[101][101];
int N;

int dj(int x)
{
	int g[101]={0};
	int min=100000,minp,max=0;
	set<int> p;
	p.insert(x);
	g[x]=0;

	while(p.size()!=N)
	{
		min=1000000;
		set<int>::iterator it=p.begin();
		while(it!=p.end())
		{
			for(int i=1;i<=N;++i)
			{
				if(*it==i || p.find(i)!=p.end())
					continue;
				if(!G[*it][i]) continue; //bu tong
				if(G[*it][i]+g[*it]<min)
				{
					minp=i;
					min=G[*it][i]+g[*it];
				}
			}
			++it;
		}
		if(min==1000000) return -1;
		p.insert(minp);
		g[minp]=min;
	}
	set<int>::iterator it=p.begin();
	
	for(int i=1;i<=N;++i)
		if(g[i]>max)
			max=g[i];
	return max;

}

int main()
{
	int i,j,n,p,t,min=1000000,xp,max;
	cin>>N;
	while(N!=0)
	{
		min=1000000;
		for(i=1;i<=N;++i)
		{
			for(j=1;j<N;++j)
				G[i][j]=0;
		}
		for(i=1;i<=N;++i)	//i jingliren
		{
			cin>>n;
			for(j=1;j<=n;++j)
			{
				cin>>p>>t;
				G[i][p]=t;
			}
		}

		//begin
		for(i=1;i<=N;++i)
		{
			t=dj(i);
			if(t==-1) continue;
			if(t<min)
			{
				min=t;
				xp=i;
			}
		}
		if(min==1000000)
		{
			cout<<"disjoint"<<endl;
			continue;
		}
		cout<<xp<<" "<<min<<endl;;
		//end
		cin>>N;
	}
}