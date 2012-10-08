#include <iostream>
#include <string>
using namespace std;

string S,T;

void digui(int a,string stk,string r,string pro)
{
	
	if (a==S.size() && stk=="")
	{	
			if (r==T)
			{
				cout<<pro<<endl;
			}
			return;
	}
	if (a!=S.size())
	{
		digui(a+1,stk+S[a],r,pro+"i ");
	}
	if(stk!="")
	{
		char c=stk[stk.size()-1];
		if(T[r.size()]!=c) return; //¼ôÖ¦
		stk.erase((string::size_type)(stk.size()-1),1);
		digui(a,stk,r+c,pro+"o ");
	}
}

int main()
{
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
	while (cin>>S>>T)
	{
		cout<<"["<<endl;
		if (S.size()==T.size())
		{
			digui(0,"","","");
		}
		
		cout<<"]"<<endl;
	}
	return 0;
}