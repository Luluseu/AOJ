#include <iostream>
using namespace std;

int fbs(int a)
{
	return  a>0?a:-a;
}

int main()
{
	int m,n,i,j,f[1000],g[1000],min;
	cin>>m>>n;

	for(i=0;i<m;++i)
		cin>>f[i];
	for(i=0;i<n;++i)
			cin>>g[i];
	i=0;j=0;
	min=fbs(f[0]-g[0]);
	while(i<m&&j<n){
		if(fbs(f[i]-g[j])<min)
			min=fbs(f[i]-g[j]);
		if(!min) break;
		if(f[i]<g[j])
		{
			i++;
			continue;
		}
		if(f[i]>g[j])
				{
					j++;
					continue;
				}
	}
	cout<<min;
}
