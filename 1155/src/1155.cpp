#include <iostream>
using namespace std;

int main() {
	string s;
	int i;
	int a[26]={2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,7,8,8,8,9,9,9,9};


	while(cin>>s)
	{
		if(s=="#") break;
		else
		{
			for(i=0;i<s.size();++i)
			{
				if(s[i]<='z'&&s[i]>='a')
				{
					s[i]='0'+a[s[i]-'a'];
				}
				else
					if(s[i]<='Z'&&s[i]>='A')
					{
						if(s[i]=='Z') s[i]='a';
						else s[i]=s[i]-'A'+'a'+1;
					}
			}
		}

		cout<<s<<endl;

	}
	return 0;
}
