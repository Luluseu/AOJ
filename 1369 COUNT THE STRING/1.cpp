#include <iostream>
#include <string>
using namespace std;

int main()
{
	int n,i,j,m;
	string s;
	cin>>n;
	for(i=0;i<n;++i)
	{
		cin>>s;
		m=1;
		for(j=1;j<s.size();++j)
		{
			if(s[j-1]!=s[j])
			{
				cout<<m<<s[j-1];
				m=1;
			}
			else
				m++;
		}
		cout<<m<<s[j-1]<<endl;
	}
	
	
}