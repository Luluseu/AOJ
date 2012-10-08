/*
ID:dingyag1
LANG:C++
TASK:fracdec
*/

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int done[100001];

class re
{
public:
	int shang;
	int yushu;
};
vector<re> vec;

int find(int yushu)
{
	return done[yushu];
}

int main()
{
	freopen("1.txt","r",stdin);
	freopen("2.txt","w",stdout);

	re r;
	int i,start,end;
	int a,b;
	int t=0;
	bool zhengchu=0;
	char ss[100];
	string s;
	while(cin>>a>>b)
	{
		if(a+b==0)
		{break;
		}
		if (a==b)
		{
			cout<<"."<<endl<<"This expansion terminates."<<endl;
			continue;
		}
	s="";
	zhengchu=0;
	t=0;
	vec.clear();
	for (i=0;i<=b;++i)
	{
		done[i]=-1;
	}
	//sprintf(ss,"%d",a/b);
	//s+=ss;
	s+='.';
	a%=b;
	r.shang=a/b;
	r.yushu=a%b;
	vec.push_back(r);
	done[r.yushu]=0;
	for(i=1;;++i)
	{
		a*=10;
		r.shang=a/b;
		r.yushu=a%b;
		a=r.yushu;
		if (a==0)
		{
			zhengchu=1;
			vec.push_back(r);
			done[r.yushu]=i;
			break;
		}
		if ((start=find(r.yushu))!=-1)
		{
			end=i;
			vec.push_back(r);
			done[r.yushu]=i;
			break;
		}
		vec.push_back(r);
		done[r.yushu]=i;
	}
	if (zhengchu)
	{
		for (i=1;i<vec.size();++i)
		{
			s+=vec[i].shang+'0';
		}


		goto lend;
	
	}

		for (i=1;i<=start;++i)
		{
			s+=vec[i].shang+'0';
		}

//	s+='(';
	for (i=start+1;i<=end;++i)
	{
		s+=vec[i].shang+'0';
	}
//	s+=')';
	
lend:
		
	cout<<s<<endl;
	if (zhengchu)
	{
		cout<<"This expansion terminates."<<endl;
	}else
		cout<<"The last "<<end-start<<" digits repeat forever."<<endl;
	}
	return 0;
}

