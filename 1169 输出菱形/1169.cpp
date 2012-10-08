#include <iostream>

using namespace std;

int main()
{
	int n,i,j,nn,k;
	cin>>n;
	while(n!=0)
	{
		
			nn=n/2+n%2;
			for(j=0;j<nn;++j)
			{
				for(k=0;k<nn-j-1;++k) cout<<' ';
				for(k=0;k<2*j+1;++k) cout<<'*';
				cout<<endl;
			}
			for(j=nn-1-n%2;j>=0;--j)
			{
				for(k=0;k<nn-j-1;++k) cout<<' ';
				for(k=0;k<2*j+1;++k) cout<<'*';
				cout<<endl;
			}
		


		cin>>n;
	}
}
