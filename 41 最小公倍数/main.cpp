#include <stdio.h>
#include <iostream>

using namespace std;
int lcm(int a,int b)
{
	int q=a,w=b;
	if (q<w)
	{
		int t=q;
		q=w;
		w=t;
	}
	while(q%w)
	{
		int t=q;
		q=w;
		w=t%w;
	}
	return a/w*b;
}

int main()
{
	int a,R,T;
	cin>>T;
	while(T--)
	{
		R=1;		
		while(scanf("%d",&a))
		{
			R=lcm(R,a);
			if(getchar()=='\n')
				break;
		}
		cout<<R<<endl;
	}
}