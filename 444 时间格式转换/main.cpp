#include <stdio.h>
#include <iostream>

using namespace  std;
int main()
{
	int T;
	int y,m,d,h,mm,s;
	char c;
	bool f;
	cin>>T;
	while (T--)
	{
		cin>>y>>c>>m>>c>>d>>c>>h>>c>>mm>>c>>s;
		f=0;
		if (m<10)
		{
			cout<<0;
		}
		cout<<m<<"/";
		if (d<10)
		{
			cout<<0;
		}
		cout<<d<<"/";
		if (y<1000)
		{
			cout<<0;
		}
		if(y<100)
			cout<<0;
		if (y<10)
		{
			cout<<0;
		}
		cout<<y<<"-";
		
		if (h>12)
		{
			h-=12;
			f=1;
		}
		if (h==12)
		{
			f=1;
		}
		if(h==0)
		{
			f=0;
			h=12;
		}
		if (h<10)
		{
			cout<<0;
		}
		cout<<h<<":";
		if (mm<10)
		{
			cout<<0;
		}
		cout<<mm<<":";
		if (s<10)
		{
			cout<<0;
		}
		cout<<s;
		if (f)
		{
			cout<<"pm"<<endl;
		}
		else
			cout<<"am"<<endl;

	}

}