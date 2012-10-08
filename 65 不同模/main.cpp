#include <bitset>
#include <cstdio>
#include <set>
using namespace std;

bitset<1000000> Is;
set<int> has;

int main()
{
	int T,N,i,j;
	int A[301];
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&N);
		for (i=0;i<N;++i)
		{
			scanf("%d",A+i);
		}
		for (i=N;i;++i)
		{
			//Is.reset();
			has.clear();
			for (j=0;j<N;++j)
			{
				int t=A[j]%i;
				if (has.find(t)!=has.end())
				{
					break;
				}else
				{
					has.insert(t);
					//Is.set(t,true);
				}
				
			}
			if (j==N)
			{
				printf("%d\n",i);
				break;
			}
		}
	}
}
