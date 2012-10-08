#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

#define removeat(a,p) ((~(1<<p))&a)
#define testat(a,p) ((a>>p)&1)

#define inf 100000000

inline bool include (const string &a,const string &b)
{
	if (a.size()<b.size())   return false;
	if (a.find(b)!=b.npos)  return true;
	return false;
}

int dis(const string &a,const string &b)
{
	int i,j;
	int maxdis=0;
	for(i=0;i<a.size();++i)
	{
		bool flg=true;
		for(j=0;j<b.size() && j+i<a.size();++j)
		{
			if(a[j+i]!=b[j])
			{
				flg=false;
				break;
			}
		}
		if(flg)
		{
			return b.size()-(a.size()-i);
		}
	}

	return b.size();
}
string merg(const string &a,const string &b)
{
	string  r;
	int i,j;

	for(i=0;i<a.size();++i)
	{
		bool flg=true;
		for(j=0;j<b.size() && j+i<a.size();++j)
		{
			if(a[j+i]!=b[j])
			{
				flg=false;
				break;
			}
		}
		if(flg)
		{
			if(a.size()-i<b.size())
			{
				return a.substr(0,i)+b;
			}else
				return a;
		}
	}
	return a+b;
}
int map[13][13];
int N;
vector<string> S;
int dp[1<<13][13];
string mins[1<<13][13]={string(201,'\0')},R;


void createmap()
{
	int i,j;
	//下表后移 1-N
	//S.insert(S.begin(),"");

	for (i=0;i<N;++i)
	{
		for (j=0;j<N;++j)
		{
			map[i][j]=dis(S[i],S[j]);
		}
	}
}


int TSP()
{
	int i,j,k;
	for (i=0;i<N;++i)
	{
		dp[1<<i][i]=S[i].size();
		mins[1<<i][i]=S[i];
	}

	for (i=1;i<(1<<N);++i)
	{
		for (j=0;j<N;++j)
		{
			if (testat(i,j) && i!= (1<<j))    //跳过只有一位为1的
			{
				int min=inf;
				for (k=0;k<N;++k)
				{
					if (testat(i,k) && k!=j)
					{
						if (dp[removeat(i,j)][k]+map[k][j]<min)
						{
							min=dp[removeat(i,j)][k]+map[k][j];
							mins[i][j]=merg(mins[removeat(i,j)][k],S[j]);
						}else if(dp[removeat(i,j)][k]+map[k][j]==min)
						{
							string s=merg(mins[removeat(i,j)][k],S[j]);
							if(s<mins[i][j])
								mins[i][j]=s;
						}
					}
				}

				dp[i][j]=min;
			}
		}
	}
	int min=inf;
	for (i=0;i<N;++i)
	{
		if (dp[(1<<N)-1][i] <min)
		{
			min=dp[(1<<N)-1][i];
			R=mins[(1<<N)-1][i];
		}else if(dp[(1<<N)-1][i] == min)
		{
			if (mins[(1<<N)-1][i] <R)
			{
				R=mins[(1<<N)-1][i];
			}
		}
	}
	return min;
}

int main()
{

	string str;
	bool f;
	int i,j;
	cin>>N;
	for(i=0;i<N;++i)
	{
		cin>>str;
		f=true;
		for (j=0;j<S.size();++j)
		{
			if (include(str,S[j]))
			{
				S[j]=str;
				f=false;
				break;
			}else if(include(S[j],str))
			{
				f=false;
				break;
			}

		}
		if (f)
		{
			S.push_back(str);
		}
	}
	N=S.size();

	createmap();
	TSP();
	cout<<R<<endl;
}