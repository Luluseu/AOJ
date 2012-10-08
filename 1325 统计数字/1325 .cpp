
#include <stdio.h>
#include <map>

using namespace std;

int main()
{
	int n,t;
	map<int,int> a;
	map<int,int>::iterator p;
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
	while (p!=a.end())
	{
		printf("%d %d\n",p->first,p->second);
		++p;
	}
}
