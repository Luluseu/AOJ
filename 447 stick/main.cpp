#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#define  max mmax
using namespace  std;

int max,sum,mmin=10000000;
vector<int> stick;
void statistics()
{
	int i;
	sum=0;
	max=0;
	mmin=100000000;
	for (i=0;i<stick.size();++i)
	{
		sum+=stick[i];
		if (stick[i]>max)
		{
			max=stick[i];
		}
		if (stick[i] < mmin)
		{
			mmin=stick[i];
		}
	}
}

int status[200];
int last_chocie[200];

bool dfs(int cur,int n)		//cur ��ǰ�ڼ���С��,n��BIGľ��
{
	int i,j;
	if (cur==stick.size()-1)
	{
		return true;
	}
/*
	for (i=0;i<n;++i)
	{
		if (status[i]==stick[cur])		//��֦1 ����������� ��ֻ�����������Ĳ���ö����
		{
			status[i] -= stick[cur];
			last_chocie[cur]=0;
			return dfs(cur+1,n);
		}
	}
*/
	i=0;
/*
	if (cur && stick[cur]==stick[cur-1])		//��֦3�������һ������һ����ͬ��ֻ����ϴ�λ�ÿ�ʼö��
	{
		i=last_chocie[cur-1];
	}*/
	for (;i<n;++i)						
	{
		bool f=0;
		//if (cur && stick[cur]==stick[cur-1])
		for (j=0;j<i;++j)						//��֦4����ֻͬ�ŵ�һ��λ��
		{
			if (status[j]==status[i])
			{
				f=1;
				break;
			}
		}
		if (f)
		{
			continue;
		}

		if (status[i]==stick[cur])
		{
			status[i] -= stick[cur];
			return dfs(cur+1,n);
		}
		if (status[i]>stick[cur])
		{
			status[i] -= stick[cur];
	
			if (status[i] && status[i] < mmin)		//��֦2 ���ʣ����޷����� ��С�ģ��޽�
			{
				status[i] += stick[cur];
				continue;
			}
			last_chocie[cur]=i;
			if (dfs(cur+1,n))
			{
				return true;
			}
			status[i] += stick[cur];
		}
	}
	return false;
}

bool can(int n)				//i ÿ����ľ���ĳ���
{
	int i;
	for (i=0;i<sum/n;++i)
	{
		status[i]=n;
	}

	return dfs(0,sum/n);

}

int main()
{

	freopen("1.txt","r",stdin);
	freopen("2.txt","w",stdout);
	int N,i,j,t,min;
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
/*		for(i=0;i<stick.size();++i)
		{
			cout<<stick[i]<<" ";
		}
		cout<<endl;
		cout<<"sum="<<sum<<"  max="<<max<<"   min="<<mmin<<endl;*/
		sort(stick.begin(),stick.end(),greater<int>());

/*		for(i=0;i<stick.size();++i)
		{
			cout<<stick[i]<<" ";
		}
		cout<<endl;
		cout<<"sum="<<sum<<"  max="<<max<<"   min="<<mmin<<endl;*/		
		begin=sum/max;
		f=0;
		for (i=begin;i>1;--i)
		{	
			if (sum%i==0)
			if (can(sum/i))
			{
				f=1;
				break;
			}
		}


		cout<<sum/i<<endl;
		
	}
}