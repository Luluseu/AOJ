#include <iostream>

using namespace std;

int main()
{
	int list[10000],i,j,p,t,n,m;

	cin>>m;
	while(m!=0)
	{
	list[0]=1;
	cout<<1<<endl;
	for (i=1;i<m;i++)	//第i+1行，下标i,0-i
	{
		p=1;
		for(j=1;j<i;j++)
		{
			t=list[j];
			list[j]=list[j]+p;
			p=t;
		}
		list[i]=1;

		for (j=0;j<i+1;j++)
		{
			cout<<list[j]<<" ";
		}
		cout<<endl;

	}
	cout<<endl;
	/*
	for (j=0;j<m-1;j++)
	{
		cout<<list[j]*n<<" ";
	}
		cout<<list[j]*n<<endl;
		*/
		cin>>m;
	}

}
