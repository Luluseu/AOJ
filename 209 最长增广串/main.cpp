#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int N,dp[1001];
string org,dic[1001];


bool include(string a,string b)
{
	int i=0,j=0,flag=0;;
	while(i<a.size() && j<b.size())
	{
		if(a[i]!=b[j]) {i++;flag++;}
		else {++i;++j;}
	}
	if(flag>1) return false;
	return true;
}

bool cmp(const string &a,const string &b)
{
	return a.size()<b.size();
}

int main()
{/*
	string s1,s2;
	while(cin>>s1>>s2) cout<<include(s1,s2)<<endl;
*/

	int i,j;
	string s;
	cin>>N>>org;
	for(i=0;i<N;++i)
	{
		cin>>dic[i];
		
	}
	sort(dic,dic+N,cmp);
	for(i=0;i<N;++i)
		if(dic[i]==org) {dp[i]=true;break;}
	for(i=0;i<N;++i)
	{
		for(j=0;j<i;++j)
		{
			if(dic[j].size()+1==dic[i].size() && dp[j])
				if(include(dic[i],dic[j])) dp[i]=true;
		}
	}
	for(i=N-1;i>=0;--i)
		if(dp[i]) {cout<<dic[i]<<endl;break;}
}