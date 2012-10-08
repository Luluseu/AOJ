#include <iostream>
#include <set>
#include <queue>
#include <algorithm>
using namespace std;
int need[12];
int now[12];

int main()
{
	int N,i,j,gray,n,t,gt;
	bool f;
	cin>>N;
	while(N!=0)
	{
		for(i=0;i<N;++i)
		{
			cin>>t;
			need[i]=t;
		}
		cin>>gray;
		

		n=0;
		while(1)
		{
			for(i=0;i<N;++i)
			{
				now[i]=n*50-need[i];
			}
			gt=gray;
			while(gt!=0)
			{
			t=1<gt?1:gt;
			gt-=t;
			sort(now,now+N);
			now[N-1]-=t;
			now[N-2]-=t;
			now[N-3]-=t;
			}
			f=0;
			for(i=0;i<N;++i)
			{
				if(now[i]<0)
					f=1;
			}
			if(!f) break;
			++n;
		}
		cout<<n<<endl;

		cin>>N;
	}
}