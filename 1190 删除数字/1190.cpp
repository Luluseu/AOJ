#include <iostream>
#include <string>
using namespace std;

void proc(string &s)
{
	int i;
	for(i=0;i<s.size()-1;++i)
	{
		if(s[i]<s[i+1])
		{
			s.erase((string::size_type)i,1);
			return ;
		}
		
	}
	s.erase(s.size()-1,1);
}

int main()
{
	int n,k,j;
	string s;
	cin>>n;
	while(n--!=0)
	{
		cin>>s>>k;
		for(j=0;j<k;++j)
			proc(s);
		cout<<s<<endl;
	}
}
