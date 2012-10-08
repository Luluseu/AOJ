#include <iostream>
#include <algorithm>
using namespace std;

int N1,N;
long long M,ans;
int A1[10],A[10];
bool T[11];

int lcm(int a,int b)
{
	int t,aa=a,bb=b;
	while (1)
	{
		if (a%b==0)
		{
			break;
		}
		t=a;
		a=b;
		b=t%b;
	}
	return aa/b*bb;
}

void digui(int deep)
{
	if (deep==N)
	{
		int i,n=0;
		long long base=1;
		for (i=0;i<N;++i)
		{
			if (T[i])
			{
				n++;
				base=lcm(base,A[i]);
			}
		}
		if (base>M || n==0) return;
		if (n%2==1)
		{
			ans+=M/base;
		}else
			ans-=M/base;
	}else
	{
		T[deep]=0;
		digui(deep+1);
		T[deep]=1;
		digui(deep+1);
	}
}

void work()
{
	ans=0;
	digui(0);
}

int main()
{
	int i,j,f;
	/*
	5 22379
	9 7 7 10 6
	*/
	//freopen("in.in","r",stdin);
	//freopen("my.out","w",stdout);

	while (cin>>N1)
	{
		cin>>M;
		for (i=0;i<N1;++i)
		{
			cin>>A1[i];
		}
		sort(A1,A1+N1);

		f=0;N=0;

		for (i=0;i<N1;++i)
		{
			f=0;
			for (j=0;j<i;++j)
			{
				if(A1[i]%A1[j]==0)
				{
					f=1;break;
				}
			}
			if (!f)
			{
				A[N++]=A1[i];
			}
		}

/*
		for (i=0;i<N;++i)
		{
			cout<<A[i]<<" ";
		}
		cout<<endl;*/

		work();
		cout<<ans<<endl;
	}


}