#include <iostream>
using namespace std;
int win[51][4];
bool ed[51];

int main()
{
	int n,i,j,r;
	while(cin>>n,n)
	{
		r=0;
		for(i=0;i<n;++i)
		{
			//d[i]=false;
			cin>>win[i][0]>>win[i][1]>>win[i][2]>>win[i][3];
		}
		for(i=0;i<n;++i)
		{
			for(j=0;j<n;++j)
			{
				//if(i!=j && ((win[j][0]>=win[i][0] &&win[j][0]<win[i][0]+win[i][3] && win[j][1]>=win[i][1] &&win[j][1]<win[i][1]+win[i][2])
				//	||(win[i][0]>=win[j][0] &&win[i][0]<win[j][0]+win[j][3] && win[i][1]>=win[j][1] &&win[i][1]<win[j][1]+win[j][2])))
				if(i!=j && !(win[j][0]+win[j][3]<=win[i][0] || win[i][0]+win[i][3]<=win[j][0] || win[j][1]+win[j][2]<=win[i][1] || win[i][1]+win[i][2]<=win[j][1]))
				{
					//ed[i]=ed[j]=true;
					r++;
					break;
				}
			}
		}
		//for(i=0;i<n;++i) if(ed[i]) r++;
		cout<<r<<endl;
	}
}