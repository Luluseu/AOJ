#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	int n,i,a,b,sum,o;
	cin>>n;
	for(i=0;i<n;++i)
	{
		cin>>a>>b;
		sum=0;
		//cal a sum
		o=1;
		while(++o<sqrt(a)+1)
		{
			if(a%o==0)	
			{
				sum+=o;
				sum+=a/o;
			}

		}
		sum+=1;
		if(sum==b)
		{
		// b sum
			o=1;
			sum=0;
			while(++o<sqrt(b)+1)
			{
				if(b%o==0)	
				{
					sum+=o;
					sum+=b/o;
				}

			}
			sum+=1;
			if(sum==a) cout<<"YES"<<endl;
			else cout<<"NO"<<endl;
		}
		else cout<<"NO"<<endl;

	}
	return 0;
}