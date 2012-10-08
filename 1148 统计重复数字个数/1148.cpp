#include <stdio.h>
#include <map>

using namespace std;

int main()
{
	int n,t,num,nmax;
	map<int,int> a;
	map<int,int>::iterator p;
	scanf("%d",&num);
	while (num--!=0)
	{
		a.clear();
		printf("size:::%d\n",a.size());
		scanf("%d",&n);
		while (n--!=0)
		{
			scanf("%d",&t);
			if (a.count(t))
			{
				a[t]+=1;
			}
			else
				a.insert(map<int,int>::value_type(t,1));
		}
		p=a.begin();
		nmax=0;
		while (p!=a.end())
		{
			if (nmax<p->second)
			{
				nmax=p->second;
			}
			
			++p;
		}
		printf("%d\n",nmax);
	}
	
}

