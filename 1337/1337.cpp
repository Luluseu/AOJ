#include <iostream>
#include <iomanip>
#include <stdio.h>
using namespace std;

int main()
{
	int i,n,d,p,nnn=0;
	int l,v,lsum;
	double t;
	cin>>n>>d;
	while(n!=0||d!=0)
	{
		lsum=0;
		t=0;
		for (i=0;i<n;++i)
		{
			cin>>p>>l>>v;
			lsum+=l;
			t+=(double)l/v*2;
		}
		t+=d-lsum;
		cout.setf(ios::fixed);
		cout<<"Case "<<++nnn<<": ";
		cout<<setprecision(3)<<t<<endl<<endl; 
	//	printf("%.3lf",t);
		cin>>n>>d;
	}

}