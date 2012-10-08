#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string mrg(string s1,string s2)
{
	int i,j;
	bool f;

	if(s1.size()>s2.size())
		i=s1.size()-s2.size();
	else
		i=0;
	for(;i<s1.size();++i)
	{
		f=0;
		for(j=0;i+j<s1.size();++j)
		{
			if(s1[i+j]!=s2[j])
			{
				f=1;
				break;
			}
		}
		if(!f)
		{
			s1.erase(s1.begin()+i,s1.end());
			s1+=s2;
			return s1;
		}
	}
	s1+=s2;
	return s1;
}

int main()
{
	int N,i,min=100000;
	string s[10],st;
	cin>>N;
	for(i=0;i<N;++i)
	{
		cin>>s[i];
	}
	sort(s,s+N);
	do
	{
		st=s[0];
		for(i=1;i<N;++i)
		{
			st=mrg(st,s[i]);
		}
		if(st.size()<min)
		{
			min=st.size();
		}

	}while(next_permutation(s,s+N));
	cout<<min<<endl;
	return 0;
}
