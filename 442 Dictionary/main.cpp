#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace  std;

bool can(string s1,string s2)
{
	int i;
	if (s2.size()<s1.size())
	{
		return false;
	}
	for (i=0;i<s1.size();++i)
	{
		if (s1[i]!=s2[i])
		{
			return false;
		}
	}
	return true;
}

int main()
{

	freopen("1.txt","r",stdin);
	freopen("2.txt","w",stdout);

	string s;
	set<string> SS;
	vector<string> r;
	set<string>::iterator it;
	int N,M,i;
	while(cin>>N)
	{
		SS.clear();
		r.clear();

		while (N--)
		{
			cin>>s;
			SS.insert(s);
		}
		cin>>M;
		while (M--)
		{
		cin>>s;
		r.clear();

		if (SS.find(s)==SS.end())	//ц╩сп
		{
			SS.insert(s);
			it=SS.find(s);
			
				for (i=0;i<6;++i)
				{
					it++;
					if (it==SS.end())
					{
						break;
					}
					if (can(s,*it))
					{
						r.push_back(*it);
					}
					else
						break;
	
				}
			

			SS.erase(SS.find(s));
		}
		else
		{
			it=SS.find(s);
			r.push_back(s);
			for (i=0;i<5;++i)
			{
				it++;
				if (it==SS.end())
				{
					break;
				}
				if (can(s,*it))
				{
					r.push_back(*it);
				}
				else
					break;
				
			}

		}

		for (i=0;i<r.size();++i)
		{
			cout<<r[i]<<endl;
		}
		}
	

	}
}
