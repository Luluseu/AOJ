#include <iostream>
#include <string>

using namespace std;

int main()
{
	int n,m,i,nn,j;
	string s;
	cin>>n;
	for (i=0;i<n;++i)
	{
		cin>>m;
		nn=0;
		for (j=0;j<m;++j)
		{
			cin>>s;
			if (s=="sheep")
			{
				nn++;
			}
		}
		cout<<"Case "<<i+1<<": This list contains "<<nn<<" sheep."<<endl<<endl;
	}

}