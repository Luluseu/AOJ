#include <iostream>

using namespace std;

int main()
{
	int T,i,j,k,v,s,min=10000000;
	cin>>T;
	while (T--)
	{
		cin>>v;
		s=0;
		min=10000000;
		for (i=1;i<=v;++i)
		{
			if(v%i==0)
			for (j=1;j<=v/i;++j)
			{
				if (v/i%j==0)
				{
					k=v/i/j;
					s=2*(i*j+j*k+i*k);
					if (s<min)
					{
						min=s;
					}
				}
			}
		}

		cout<<min<<endl;
	}
}