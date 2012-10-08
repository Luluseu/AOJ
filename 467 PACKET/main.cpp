#include <iostream>

using namespace std;

int main()
{
	int a1,a2,a3,a4,a5,a6;
	int sum;
	while (cin>>a1>>a2>>a3>>a4>>a5>>a6,a1||a2||a3||a4||a5||a6)
	{
		sum=a6;
		sum+=a5;
		a1-=a5*11;
		sum+=a4;
		if (a4*5<=a2)
		{
			a2-=a4*5;
		}else
		{
			a1-=(a4*5-a2)*4;
			a2=0;
		}
		sum+=a3/4+1;
		if (a3%4==0)
		{
			sum--; //Î´¶à³ö
		}else if (a3%4==1)
		{
			if (a2>=5)
			{
				a2-=5;
				a1-=7;
			}else
			{
				a1-=27-a2*4;
				a2=0;
			}
		}else if (a3%4==2)
		{
			if (a2>=3)
			{
				a2-=3;
				a1-=6;
			}else
			{
				a1-=18-a2*4;
				a2=0;
			}
		}else if (a3%4==3)
		{
			if (a2>=1)
			{
				a2-=1;
				a1-=5;
			}else
			{
				a1-=9-a2*4;
				a2=0;
			}
		}
		if (a2>0)
		{
			sum+=a2/9;
			if (a2%9)
			{
				sum+=1;
				a1-=36-a2%9*4;
			}
		}
		if (a1>0)
		{
			sum+=a1/36;
			if (a1%36)
			{
				sum+=1;
			}
		}
		
		cout<<sum<<endl;
	}
}