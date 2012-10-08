#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main()
{
	freopen("1.txt","r",stdin);
	freopen("2.txt","w",stdout);

	string name;
	int max,min,a[7],i,sum;
	while(!cin.eof())
	{
		if(!(cin>>a[0])) break;
		max=a[0];min=a[0];
		sum=a[0];
		for(i=1;i<7;++i)
		{
			cin>>a[i];
			sum+=a[i];

			if(a[i]>max)
				max=a[i];
			else
				if(a[i]<min)
					min=a[i];
		}
		sum=sum-max-min;
		//cout<<sum<<endl;
		cin>>name;
		cout.setf(ios::fixed);

		cout<<name<<" "<<setprecision(2)<<(double)sum/5.00<<endl;

	}
}
