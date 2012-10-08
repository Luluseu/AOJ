#include <cstdio>

long long prime[2000]={2,3};
int total,t,nprime=2;
long long N;

void getprime()
{
	int i,j;
	for(i=5;i<11000;++i)
	{
		for(j=0;j<nprime;++j)
		{
			if(i%prime[j] ==0)
				break;
		}
		if (j==nprime)
			prime[nprime++]=i;
	}
}
void calc(int begin,long long product,int sign)
{
	if (product*prime[begin]>N)
	{
		return;
	}

	if(prime[begin]*prime[begin] >N) 
	{
		t=begin;
		return;
	}

	total += sign*N/(product*prime[begin]);
	calc(begin+1,product*prime[begin],-sign);
	calc(begin+1,product,sign);
}

int main()
{
	int i,j;
	getprime();
	//for(i=0;i<nprime;++i) printf("%lld ",prime[i]);
	while(scanf("%lld",&N),N)
	{
		total = 0;
		t=0;
		calc(0,1,1);
		printf("%lld\n",N-total+t-1);
		//printf("%lld\n",N-total-1);
	}
}