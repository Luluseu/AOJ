#include <iostream>
#include <queue>
#include <stack>
using namespace std;

int N,K;
int map[2001][2001]={0};
int path[2001][2]={0};
void bfs()
{
	queue<int> que;
	int i,tmp;
	que.push(1);
	path[1][1]=0;
	path[1][0]=-1;
	while(!que.empty())
	{
		tmp=que.front();
		
			for (i=1;i<=K;++i)
			{
				if (map[tmp][i] && !path[i][0])
				{
					que.push(i);
					path[i][0]=tmp;
					path[i][1]=path[tmp][1]+1;
				}
			}
		
			if (path[K][0]!=0)
			{
				break;
			}
		que.pop();
	}
}

int main()
{
	
	int a,b,i;
	stack<int> stk;
	cin>>N>>K;
	
	for (i=0;i<N;++i)
	{
		cin>>a>>b;
		map[a][b]=1;
	}
	
	bfs();
	
	if (path[K][0]==0)
	{
		cout<<"-1"<<endl;
		return 0;
	}
	else
	{
		cout<<path[K][1]+1<<endl;
		int pre=K;
		stk.push(K);
		while (path[pre][0]!=-1)
		{
			stk.push(path[pre][0]);
			pre=path[pre][0];
		}
		while(!stk.empty())
		{
			cout<<stk.top()<<endl;
			stk.pop();

		}
	}

}