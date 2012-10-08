#include <iostream>

using namespace std;

int main()
{
	
	int n,i,j,max;
	int a[7000],b[7000];

	while(cin>>n)
	{
		for(i=0;i<n;++i)
		{
			cin>>a[i];
			max=0;

			for(j=0;j<i;++j)
			{
				if(a[i]>a[j]) 
					if(b[j]>max) max=b[j];			
			}
			b[j]=max+1;
		}

		for(i=0;i<n;++i)
		{
			max=0;
			if(b[i]>max) max=b[i];
		
		}
		cout<<max<<endl;
	}
}