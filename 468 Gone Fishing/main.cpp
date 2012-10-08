/*
2010-12-3 10:59
*/

#include <iostream>
#include <queue>
using namespace std;

class LAKE
{
public:
	int CUR,DEC,id;
};

bool operator < (const LAKE &a,const LAKE &b)
{
	if (a.CUR==b.CUR)
	{
		return a.id>b.id;
	}
	return a.CUR<b.CUR;
}

priority_queue<LAKE> PQ;

int main()
{
	int N,T,j,i;
	int SP[25];
	bool f=false;
	LAKE lakes[26];

	while (cin>>N,N)
	{
		cin>>T;
		T*=12;
		for (i=0;i<N;++i)
		{
			cin>>lakes[i].CUR;
			lakes[i].id=i;
		}
		for (i=0;i<N;++i)
		{
			cin>>lakes[i].DEC;
		}
		for (i=0;i<N-1;++i)
		{
			cin>>SP[i];
		}
		int sum=0,maxsum=-1,fishnum;
		int usesumtime=0;
		int TIME[26]={0},maxTime[26]={0};
		for (i=0;i<N;++i)	//most far lake id
		{
			while (!PQ.empty())
			{
				PQ.pop();
			}
			for (j=0;j<=i;++j)
			{
				if (lakes[j].CUR>0)
				PQ.push(lakes[j]);
				TIME[j]=0;
			}
			int lefttime=T-sum;
			fishnum=0;
			while (lefttime-- && !PQ.empty())
			{
				LAKE l=PQ.top();
				PQ.pop();
				fishnum+=l.CUR;
				TIME[l.id]+=5;
				l.CUR-=l.DEC;
				if (l.CUR>0)
				{
					PQ.push(l);
				}
			}
			//TIME[0]+=lefttime*5+5;
			usesumtime=0;
			if (fishnum>maxsum)
			{
				maxsum=fishnum;
				for (j=0;j<=i;++j)
				{
					maxTime[j]=TIME[j];
					usesumtime+=TIME[j];
				}
				maxTime[0]+=((T-sum)*5-usesumtime);
			}
			if ((sum+=SP[i])>=T)
			{
				break;
			}
		}
		if (f)
		{
			cout<<endl;
		}
		f=true;
		for (j=0;j<N-1;++j)
		{
			cout<<maxTime[j]<<", ";
		}
		cout<<maxTime[j]<<endl;
		cout<<"Number of fish expected: "<<maxsum<<"\n";
	}
}