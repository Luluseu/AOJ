#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;

void Dtobase(int n,int base)		//十进制转换为base进制string，注意n和base均不能为0
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
				s.insert(s.begin(),1,t-10+'a');
				
			}
			else
				s.insert(s.begin(),1,t+'0');
			n/=base;
		}
		cout<<s;
	}
}


unsigned hextoint(string s)
{
	int i;
	int base=1;
	unsigned int r=0;
	for (i=7;i>=0;--i)
	{
		if (s[i]<='9' && s[i]>='0')
		{
			r+=(s[i]-'0')*base;
		}
		else
		{
			r+=(s[i]-'a'+10)*base;
		}
		base *=16;
			
	}
	return r;
}

int main()
{
	int T;
	unsigned int a;
	unsigned int t;
	int x,y;

	cin>>T;
	
	while (T--)
	{
		string s;
		char c;
		char ss[100];
		//fflush(stdin);
		scanf("%x",&a);
		//s=ss;
		//a=hextoint(s);

		cin>>c;
		cin>>x>>c>>y;
		t=1;
		t<<=x;
		t^=0xFFFFFFFF;
		a&=t;


		t=1;
		t<<=y;
		a|=t;
		t>>=1;
		a|=t;
		t>>=1;
		t^=0xFFFFFFFF;
		a&=t;
		//Dtobase(a,16);
		//cout<<endl;
		printf("%x\n",a);
	}
}