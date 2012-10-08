#include <iostream>
#include <string>
#include <map>
#include <set>
using namespace std;


int G[100][100]={0};
int sh[100]={0};
bool U[100]={0};

int main()
{
	freopen("1.txt","r",stdin);
	freopen("2.txt","w",stdout);
	int N;
	int i,t,j=0,t1,t2,ii;
	char s1,s2,c;
	string ss1,ss2;
	
	
	map<char,int> ALL;
	map<int,char> index;

	cin>>N;
	for(i=0;i<N;++i)
	{
		cin>>ss1>>ss2>>t;
		s1=ss1[0];s2=ss2[0];

		if(ALL.count(s1))
			t1=ALL[s1];
		else
		{
			t1=j;
			index[j]=s1;
			ALL[s1]=j++;
		}
		if(ALL.count(s2))
			t2=ALL[s2];
		else
		{
			t2=j;
			index[j]=s2;
			ALL[s2]=j++;
		}
		if (G[t1][t2]==0)
		{
			G[t1][t2]=t;
			G[t2][t1]=t;
		}
		else if(G[t1][t2]>t)
		{
		G[t1][t2]=t;
		G[t2][t1]=t;
		}
	}
	/********************************/
	U[ALL['Z']]=1;

	for(i=0;i<j;++i)
	{
		if(G[ALL['Z']][i]!=0)
		{
			if (sh[i]==0)
			{
				sh[i]=G[ALL['Z']][i];
			}
			else 
			{
				if(sh[i]>G[ALL['Z']][i])
					sh[i]=G[ALL['Z']][i];
			}
			
		}
	}
	/********************************/
	for(ii=0;ii<j;++ii)
	{
		int min=100000000,dn;
		for(i=0;i<j;++i)
		{
			if(sh[i]!=0&&!U[i])
				if(sh[i]<min)
				{
					min=sh[i];
					dn=i;
				}
		}


		//**????????????????
		{
			
			if(index[dn]<'Z'&&index[dn]>='A')
			{
						cout<<index[dn]<<" "<<min<<endl;
						break;
			}

		}
		//**
		U[dn]=1;
		for(i=0;i<j;++i)
		{
			if(G[dn][i]!=0)
			{
				if(sh[i]==0)
					sh[i]=G[dn][i]+min;
				else
				{
					if(G[dn][i]+min<sh[i])
						sh[i]=G[dn][i]+min;
				}
			}
		}
	}

	/********************************/

}
