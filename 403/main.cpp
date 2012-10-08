#include <iostream>
#include <stack>
#include <set>
using namespace std;
bool status[50005];
int stk[50005];

int main()
{

	set<int> S;
	char op;
	int N,M;
	int i,j,tmp,sum;
	int top=0,end=0;
	
	cin>>N>>M;
	S.insert(0);
	S.insert(N+1);
	for (i=0;i<M;++i)
	{

		getchar();
		scanf("%c",&op);
		if (op!='R')
		{

			scanf("%d",&tmp);
		}
		switch(op)
		{
		case 'D':
			status[tmp]=1;
			stk[++top]=tmp;
			S.insert(tmp);
			break;
		case 'R':
			tmp=stk[top];
			status[tmp]=0;
			S.erase(S.find(tmp));
			top--;
			break;
		case 'Q':
			sum=0;
			if (status[tmp])
			{
				cout<<0<<endl;
				break;
			}

			set<int>::iterator it;
			it=S.lower_bound(tmp);
			sum=*(it);
			sum-=*(--it)+1;
			cout<<sum<<endl;
			break;
		}
	}
	return 0;
}