#include <iostream>
#include <string>
using namespace  std;

int main()
{
	bool a[32][32]={0};
	int i,j,n,x,y,k;
	string s;

	cin>>n;
	for (i=0;i<n;++i)
	{
		cin>>x>>y;
		cin>>s;
		for (j=0;j<s.size()-1;++j)
		{
			switch(s[j])
			{
			case 'E':
				a[32-y][x]=1;
				++x;
				break;
			case 'W':
				a[31-y][x-1]=1;
				--x;
				break;
			case 'N':
				a[31-y][x]=1;
				++y;
				break;
			case 'S':
				a[32-y][x-1]=1;
				--y;
				break;
			}
		}

		cout<<"Bitmap #"<<i+1<<endl;
		for (j=0;j<32;++j)
		{
			for (k=0;k<32;++k)
			{
				if (a[j][k])
						cout<<"X";
				else 
						cout<<".";
			}
			cout<<endl;
		}
		for (j=0;j<32;++j)
		{
			for (k=0;k<32;++k)
			{
				a[j][k]=0;
			}
		}
		cout<<endl;

	}
}