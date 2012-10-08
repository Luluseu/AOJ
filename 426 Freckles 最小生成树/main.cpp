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

double d[100][100]; 
bool pass[100][100];
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
			d[j][i]=l.d;
			d[i][j]=l.d;
			//L.push_back(l);
		}

	}
	//sort(L.begin(),L.end(),cmp);

/*	vector<link>::iterator it=L.begin();
	while(it!=L.end())
	{
		cout<<it->a<<" "<<it->b<<" "<<it->d<<endl;
		it++;
	}*/
	
	P.insert(0);
	while(P.size()!=n)
	{
		double min=10000000000;
		int pmini,pminj;
		set<int>::iterator it=P.begin();
		while(it!=P.end())
		{
			j=*it;
			for(int i=0;i<n;++i)
			{
				if(i==j) continue;
				if(pass[i][j]||pass[i][j]) continue;
				if(P.find(i)!=P.end()) continue;
				if(d[i][j]<min)
				{
					min=d[i][j];
					pmini=i;
					pminj=j;
				}
			}
			++it;
		}
		P.insert(pmini);
		len+=min;
		pass[pminj][pmini]=1;
		pass[pmini][pminj]=1;
			
		
	
			

	//	L.erase(L.begin());
	}
	//cout<<len<<endl;
	printf("%.2lf",len);
}