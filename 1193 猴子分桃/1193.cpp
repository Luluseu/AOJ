#include <iostream>
#include <stdio.h>
using namespace std;

__int64 pow(int a,int b)
{
	__int64 c=1;
	while(b--!=0)
		c*=a;
	return c;

}


int main()
{
	unsigned int n,i;
	__int64 h,t;
	cin>>n;
	while(n)
	{
		t=0;
		h=pow(5,n)-4;
		printf("%I64d ",h);
		for(i=0;i<n;++i)
		{
			h-=1;
			h/=5;
			h*=4;

		}
		t+=n+h;
		printf("%I64d\n",t);

		cin>>n;
	}
}
