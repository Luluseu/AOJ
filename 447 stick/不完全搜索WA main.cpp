#include <iostream>
#include <vector>
using namespace  std;

int max,sum;
vector<int> stick;
void statistics()
{
	int i;
	sum=0;
	max=0;
	for (i=0;i<stick.size();++i)
	{
		sum+=stick[i];
		if (stick[i]>max)
		{
			max=stick[i];
		}
	}
}

bool can2(int begin,int n,bool *steped)
{
	
	if (begin==stick.size())
	{
		return false;
	}
	if (steped[begin])
	{
		return can2(begin+1,n,steped);
	}
	steped[begin]=1;
	if (n-stick[begin]==0)
	{
		return true;
	}else
	if (n > stick[begin])
	{
		if (can2(begin+1,n-stick[begin],steped))
		{
			return true;
		}
	}
	steped[begin]=0;
	if(can2(begin+1,n,steped))
	{
		return true;
	}
	else
	{
		//steped[begin]=0;
		return false;
	}
}

bool can(int n)
{
	bool steped[65]={0};
	int i;
	for (i=0;i<stick.size();++i)
	{
		if (steped[i])
		{
			continue;
		}else
			steped[i]=1;

		if(n==stick[i] || can2(i+1,n-stick[i],steped))
		{

		}else
			return false;

	}
	return true;
}

int main()
{

	int N,i,j,t;
	int begin;
	bool f;
	while (cin>>N,N)
	{
		stick.clear();
		for (i=0;i<N;++i)
		{
			cin>>t;
			stick.push_back(t);
		}
		statistics();
		
		begin=sum/max;
		f=0;
		for (i=begin;i>1;--i)
		{	
			if (sum%i==0)
			if (can(sum/i))
			{
				f=1;
				cout<<sum/i<<endl;
				break;
			}
		}
		if (!f)
		{
			cout<<sum<<endl;
		}
	}
}