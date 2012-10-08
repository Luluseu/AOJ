#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
using namespace std;
int main()
{
	int N,i;
	string s,word;
	vector<string> S;
	while(cin>>N,N)
	{
		getchar();
		while(N--)
		{
			getline(cin,s);
			//cout<<"[!]"<<s<<endl;
			S.clear();
			s+='.';
			int len=s.size();
			word="";
			for (i=0;i<len;++i)
			{
				if (s[i]<='z' && s[i]>='a' || (s[i]>='A' && s[i]<='Z'))
				{
					word+=s[i];
				}else
				{
					if (word.size()!=0)	{ if(word[0]<='z' && word[0]>='a') word[0]+='Z'-'z';S.push_back(word);}
					word="";
				}
			}
			if (S.size()==0)
			{
				cout<<"."<<endl;
				continue;
			}

			cout<<S[0];
			for (i=1;i<S.size();++i)
			{
				cout<<" "<<S[i];
			}
			cout<<"."<<endl;
		}
		cout<<endl;
	}
}