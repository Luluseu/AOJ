#include <iostream>
#include <string>
using namespace std;
void Dtobase(int n,int base)
{
	int t;
	string s;
	if (base<11)
	{
		while (n!=0)
		{
			s.insert(s.begin(),1,n%base+'0');
			n/=base;
		}
		cout<<s;
	}
	else
	{
		while (n!=0)
		{
			t=n%base;
			if (t>9)
			{
				s.insert(s.begin(),1,t-10+'A');
				
			}
			else
				s.insert(s.begin(),1,t+'0');
			n/=base;
		}
		cout<<s;
	}
}


int main()
{
	int t,n,base;
	cin>>t;
	while (t--!=0)
	{
		cin>>n>>base;
		if (n==0)
		{
			cout<<0;
		}
		else
			Dtobase(n,base);
			cout<<endl;
	}
}
