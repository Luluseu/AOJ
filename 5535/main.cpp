#include <set>
#include <cstdio>
#include <cstring>
#include <bitset>
#include <list>

using namespace  std;

struct path{
	int m[41];
};


bitset<41> st;
bool m[41][41];
path P;
set<path> R;
int N;



bool canmove(int a,int b)
{
	if (!st.test(b) && !m[a][b])
	{

	}

	return false;
}
void work()
{
	R.clear();
	st.reset();
	st.set(1);




}

int main()
{
	int C,i,j,t;

	while (scanf("%d%d",&C,&N),C)
	{
		memset(m,0,sizeof(m));

		for (i=1;i<=N;++i)
		{
			for (j=1;j<=N;++j)
			{
				scanf("%d",&t);
				if (t==1)
				{
					m[i][j]=m[j][i]=true;
				}
			}
		}

		work();
	}
	
}