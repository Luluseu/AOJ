#include <iostream>
#include <string>
#include <algorithm>
using namespace std;


int getbitnum(int n)
{
	int ans=0;
	int t=1,i;
	for (i=0;i<31;++i)
	{
		if(t&n) ans++;
		t<<=1;
	}
	return ans;
}

int main()
{
	int N,T,a,b,c;
	bool num[33]={0,0,0,1,1,1};

	cin>>T;
	while(T--)
	{
		cin>>a>>b>>c;

		while (next_permutation(num,num+6))
		{
			int i;
			for (i=0;i<10;++i)
			{
				cout<<num[i]<<" ";
			}
			cout<<endl;	
		}
	}

}