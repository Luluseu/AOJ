#include <iostream>
using namespace std;
int a[100][100];
int b[100],c[100];
int main()
{
	int i,j,n,sum,s,x,y;
	cin>>n;
	while(n)
	{
		for(i=0;i<n;++i)
		{
			for(j=0;j<n;++j)
			{
				cin>>a[i][j];
			}
		}
		for(i=0;i<n;++i)
		{
			sum=0;s=0;
			for(j=0;j<n;++j)
			{
				sum+=a[i][j];
				s+=a[j][i];
			}
			b[i]=sum%2;
			c[i]=s%2;
		}
		sum=0;
		s=0;
		for(j=0;j<n;++j)
			{
				
				if(b[j]) 
				{
					x=j;
					sum+=b[j];
				}
				
				if(c[j])
				{
						y=j;
						s+=c[j];
				}
			}
		if(sum==1&&s==1)
			cout<<"Change bit ("<<x+1<<","<<y+1<<")"<<endl;
		else
		if(sum==0&&s==0)
			cout<<"OK"<<endl;
		else
			cout<<"Corrupt"<<endl;
		cin>>n;
	}
}