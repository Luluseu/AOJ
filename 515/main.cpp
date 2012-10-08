#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace  std;

bool can(const string &a,const string &b)
{
	int i;
	if (a.size() < b.size())
	{
		return false;
	}
	for (i=0;i<b.size();++i)
	{
		if (a[i]!=b[i])
		{
			break;
		}
	}
	return i==b.size();
}

int main()
{
	int i,j,N;
	vector<string> S,R;
	string str,T;

	cin>>N;
	int t=N;
	while(t--)
	{
		cin>>str;
		S.push_back(str);
	}
	cin>>T;
	for(i=0;i<N;++i)
	{
		if (can(S[i],T))
		{
			R.push_back(S[i]);
		}
	}
	sort(R.begin(),R.end());
	for (i=0;i<R.size();++i)
	{
		cout<<R[i]<<endl;
	}
}