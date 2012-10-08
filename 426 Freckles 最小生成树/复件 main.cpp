#include <iostream>
#include <stdio.h>
#include <math.h>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

class link
{
public:
	int a,b;
	float d;
};

bool cmp (const link & A,const link& B)
{
	return A.d<B.d;
}

//float d[100][100]; 

int main()
{
	vector<link> L;
	set<int>  P;
	int n,i,j,nL=0;
	double x,y,len=0;
	double p[101][2];
	link l;
	cin>>n;
	for(i=0;i<n;++i)
	{
		cin>>p[i][0]>>p[i][1];
		
		for(j=0;j<i;++j)
		{
			l.a=j;
			l.b=i;
			x=p[i][0]-p[j][0];y=p[i][1]-p[j][1];

			l.d=sqrt(x*x+y*y);
			L.push_back(l);
		}

	}
	sort(L.begin(),L.end(),cmp);

	vector<link>::iterator it=L.begin();
	while(it!=L.end())
	{
		cout<<it->a<<" "<<it->b<<" "<<it->d<<endl;
		it++;
	}
	

	while(P.size()!=n)
	{
		int a,b;
		bool f=0;
		a=L.begin()->a;
		b=L.begin()->b;
		if(P.find(a)==P.end()&&P.find(b)==P.end())
		{
			P.insert(a);
			P.insert(b);
			len+=L.begin()->d;
			nL+=1;
		}
		else if(P.find(a)==P.end()&&P.find(b)==P.end())
		{
			P.insert(a);
			P.insert(b);
			len+=L.begin()->d;

		}
	
			

		L.erase(L.begin());
	}
	//cout<<len<<endl;
	printf("%.2lf",len);
}