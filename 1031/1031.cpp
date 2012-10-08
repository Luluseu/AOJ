#include <iostream>

using namespace std;

int powbase(int base,int i)
{
	int r=1;
	while (i--!=0)
	{
		r*=base;
	}
	return r;
}

int baseTo10(int a,int base)
{
	int r=0,i;
	for(i=0;a!=0;++i)
	{
		r+=a%10*powbase(base,i);
		a/=10;
	}
	return r;

}

int base_maybe(int a)
{
	int i,n,r=0;
	for(i=0;a!=0;++i)
	{
		n=a%10;
		a/=10;
		if(n>r) r=n;
	}
	return r+1;
}


int main()
{
	int n,a[5],b[5],i,j,maybe=0;
	bool f;
	while (1)
	{
		cin>>n;
		if (n==0)
		{
			break;
		}
		maybe=0;
		for (i=0;i<n;++i)
		{
			cin>>a[i];
			if (base_maybe(a[i])>maybe)
			{
				maybe=base_maybe(a[i]);
			}
			
		}

		for (i=maybe;i<11;++i)
		{
			
			for(j=0;j<n;++j)
			{
				b[j]=baseTo10(a[j],i);
				
			}
			f=true;
			for(j=0;j<n-2;++j)
			{
				if (b[j+1]-b[j]!=b[j+2]-b[j+1])
				{
					f=false;
					break;		
				}
			}
			if (f)
			{
				cout<<"Minimum base = "<<i<<"."<<endl;
				break;
			}
			if (i==10)
			{
				cout<<"No base <= 10 can be found."<<endl;
				break;
			}
		}
	}
	
}
