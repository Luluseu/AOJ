#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main()
{
/*
	freopen("1.txt","r",stdin);
		freopen("2.txt","w",stdout);
	*/
	bool a[203]={0};
	int m,s,c,i,t,begin=-1,sum=0;
	vector<int> space;

	cin>>m>>s>>c;
	if(m>=c)
	{
		cout<<c<<endl;
		return 0;
	}
	for (i=0;i<c;++i)
	{
		cin>>t;
		a[t-1]=1;
	}
	for (i=0;i<s;i++)		//Ñ°ÕÒspace£¬²¢²åÈëvector
	{
		if (a[i]==1)
		{
			begin=i;
		}
		if (a[i]==0&&a[i+1]==1&&begin!=-1)
		{
			space.push_back(i-begin);
		}
	}
	//cout<<space.size();
	sort(space.begin(),space.end());
	/*for (i=0;i<space.size();++i)
	{
		cout<<space[i]<<" ";
	}
	*/
	sum=c;
	for (i=0;i<space.size()+1-m;++i)
	{
		sum+=space[i];
	}
	cout<<sum;

}