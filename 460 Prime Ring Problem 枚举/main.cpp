#include <iostream>

using namespace std;
bool isP[41]=
{0,
0,1,1,0,1,0,1,0,0,0,
1,0,1,0,0,0,1,0,1,0,
0,0,1,0,0,0,0,0,1,0,
1,0,0,0,0,0,1,0,0,0
};
bool isP2[41];
bool used[21];
int path[21];
int n;

void digui(int i)
{
	int k,j;

	if(i==n+1)
	{
		if (isP[1+path[i-1]])
		{
			cout<<1;
			for (k=2;k<=n;++k)
			{
				cout<<" "<<path[k];
			}
			cout<<endl;
		}
		
		return ;
	}
	
	if (i%2==0)
	{
		for(k=2;k<=n;k+=2)
		{
			if (!used[k] && isP[k+path[i-1]])
			{
				used[k]=1;
				path[i]=k;
				digui(i+1);
				used[k]=0;
			}
		}
	}
	else
	{
		for(k=3;k<=n;k+=2)
		{
			if (!used[k] && isP[k+path[i-1]])
			{
				path[i]=k;
				used[k]=1;
				digui(i+1);
				used[k]=0;
			}
		}
	}

}


int main()
{
//	freopen("1.txt","r",stdin);
//	freopen("2.txt","w",stdout);
	int i,j,count=0;
	bool oushu;
	bool f=0;


	while(cin>>n)
	{
		

		count++;
		for(i=2;i<=n;++i)
			used[i]=0;
		used[1]=1;
		oushu=1;
		cout<<"Case "<<count<<":"<<endl;

		path[1]=1;

		if (n%2)
		{
			//cout<<1<<endl;
		}else
		if (n%2==0)
		{
				digui(2);
					
		}
	cout<<endl;
	
		
	}
}