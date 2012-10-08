#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool isF(const string &s,const vector<string> &Set)
{
	int i,j;
	for (i=0;i<Set.size();++i)
	{
		int lim=s.size()<Set[i].size()?s.size():Set[i].size();

		bool f=true;
		for (j=0;j<lim;++j)
		{
			if (s[j]!=Set[i][j])
			{
				f=false;
				break;
			}
		}
		if (f)
		{
			return true;
		}
	}
	return false;
}

int main()
{
	string s;
	vector<string> Set;
	bool flag=true;
	int id=0;
	while (cin>>s)
	{
		

		if (s=="9")
		{
			id++;
			Set.clear();
			
			if (flag)
			{
				cout<<"Set "<<id<<" is immediately decodable"<<endl;
			}else
				cout<<"Set "<<id<<" is not immediately decodable"<<endl;
			flag=true;
		}else
		{
			if (flag)
			{
				if (isF(s,Set))
				{
					flag=false;
				}else
					Set.push_back(s);
			}
			
		}
	}
}