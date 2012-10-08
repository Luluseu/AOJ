#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main()
{
	
	bool  f=0;
	
	string s,s2;
	string::iterator it;
	
	while(getline(cin,s))
	{
		//cout<<"[*"<<s<<"*]";
		if(s[0]=='#'||s[0]=='\n'||s[0]=='\t')
			continue;
		
		{
			stringstream sst(s);
			//sst<<s;
			sst>>s2;
			if(s2[0]!='0')
				continue;
			cout<<s2<<"\t";
			sst>>s2;
			cout<<s2;
			sst>>s2;//##
			f=0;
			while(sst>>s2)
			{
				if(s2=="<CJK>")
					break;
				it=s2.begin();
				while(it!=s2.end())
				{
					if((*it<(char)('Z'+1))&&(*it>(char)('A'-1)))
						*it-='A'-'a';
					++it;
				}
				s2[0]+='A'-'a';
				if (!f)
				{
					cout<<"\t";
					f=1;
				}
				else
				cout<<' ';
				cout<<s2;
			}
			cout<<endl;
		}
		
	}
}
