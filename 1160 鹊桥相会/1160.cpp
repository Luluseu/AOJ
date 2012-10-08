#include <iostream>

using namespace std;

int main()
{
	int w,n,v,p,vmax;
	cin>>w>>n;
	while(w!=0||n!=0)
	{
		vmax=0;
		while(n-- >0)
		{

			cin>>p>>v;
			if(p==0)
			{
				if(v>vmax) vmax=v;
			}
		}
		if(vmax)
			cout<<1000*w/vmax<<endl;
		else
			cout<<"Can't Solve"<<endl;
		cin>>w>>n;
	}
}
