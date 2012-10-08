#include <iostream>
#include <stack>
using namespace std;
bool status[50001];
int main()
{
	stack<int> stk;
	char op;
	int N,M;
	int i,j,tmp,sum;
	
	cin>>N>>M;
	for (i=0;i<M;++i)
	{
		cin>>op;
		if (op!='R')
		{
			cin>>tmp;
		}
		switch(op)
		{
		case 'D':
			status[tmp]=1;
			stk.push(tmp);
			break;
		case 'R':
			status[stk.top()]=0;
			stk.pop();
			break;
		case 'Q':
			sum=0;
			if (status[tmp])
			{
				cout<<0<<endl;
				break;
			}
			for (j=tmp-1;j>0;--j)
			{
				if (status[j])
				{
					break;
				}
				sum++;
			}
			for (j=tmp+1;j<=N;++j)
			{
				if (status[j])
				{
					break;
				}
				sum++;
			}
			cout<<sum+1<<endl;
			break;
		}
	}
	return 0;
}