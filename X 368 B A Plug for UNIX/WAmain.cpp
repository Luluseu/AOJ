/*
ID:dingyag1
LANG:C++
TASK:stall4
*/

#include <stdio.h>
#include <iostream>
#include <string>
#include <queue>
#include <map>
using namespace std;

#define  inf		1000000000
int N,M,sum;
int mmap[800][800];
int path[100000][2];		//0 前一个的坐标   1 max-flow

int min(const int &a, const int &b)
{
	return a<b?a:b;
}

void bfs()
{
	queue<int> que;
	int i,tmp;
	path[M][0]=0;
	path[1][1]=inf;
	path[1][0]=-1;
	for (i=2;i<=M;++i)
	{
		path[i][0]=0;
	}
	que.push(1);
	while (!que.empty())
	{
		tmp=que.front();
		for (i=1;i<=M;++i)
		{
			if (i!=tmp && mmap[tmp][i]>0 && !path[i][0])
			{
				path[i][0]=tmp;
				path[i][1]=min(mmap[tmp][i],path[tmp][1]);
				que.push(i);
			}
		}	
		que.pop();
	}
}

int max_flow()
{
	int maxv=0;
	int cur;
	while (1)
	{
		bfs();
		if (path[M][0]==0)
		{
			return maxv;
		}
		else
		{
			maxv+=path[M][1];
		}	
		//按照path 更改mmap
		cur=M;
		while (path[cur][0]!=-1)
		{
			mmap[path[cur][0]][cur] -= path[M][1];
			mmap[cur][path[cur][0]] += path[M][1];
			cur=path[cur][0];
		}
	}	
}


int main()
{
	freopen("1.txt","r",stdin);
	freopen("2.txt","w",stdout);
	
	int i,n,a,b,c,j;
	string s1,s2;
	map<string,int> index;
	N=0;
	cin>>a;
	for (i=0;i<a;++i)
	{	
		
		cin>>s1;
		if (index.count(s1)==0)
		{
			N++;
			index[s1]=N+1;
		}
	}
	cin>>b;
	for (i=0;i<b;++i)
	{
		cin>>s1>>s2;
		if (index.count(s1)==0)
		{
			N++;
			index[s1]=N+1;
		}
		mmap[1][index[s1]]=1;
		if (index.count(s2)==0)
		{
			N++;
			index[s2]=N+1;
		}
		mmap[index[s1]][index[s2]]=1;
	}
	cin>>c;
	for (i=0;i<c;++i)
	{
		cin>>s1>>s2;
		if (index.count(s1)==0)
		{
			N++;
			index[s1]=N+1;
		}
		if (index.count(s2)==0)
		{
			N++;
			index[s2]=N+1;
		}
		mmap[index[s1]][index[s2]]=inf;
	}

	for (i=2;i<a+2;++i)
	{
		mmap[i][N+2]=1;
	}

	M=N+2;
	int r=b-max_flow();
	if (r<0)
	{
		r=0;
	}
	cout<<r<<endl;
	return 0;
}
