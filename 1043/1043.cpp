#include <iostream>
#include <algorithm>
using namespace std;
float med(int p[],int a,int b);
void out(float q1,float q2,float q3,float q4,float q5);
int main()
{
	int i,j,n,a[105],q1,q5;
	float q2,q3,q4;
	cin>>n;
	while(n)
	{
		for (i=0;i<n;++i)
		{
			cin>>a[i];
		}
		sort(a,a+n);
		q1=a[0];
		q5=a[n-1];
		q3=med(a,0,n-1);
		
		if ((n-1)%2==1)//≤ª…·med
		{
			q2=med(a,0,n/2-1);
			q4=med(a,n/2,n-1);
		}
		else
		{
			if (n==1)
			{
				q2=a[0];
				q4=a[0];
			}
			else
			{
				q2=med(a,0,(n-1)/2-1);
				q4=med(a,(n-1)/2+1,n-1);

			}
			
		}
		cout<<q1<<" "<<q2<< " "<<q3<<" "<<q4<<" "<<q5<<" ";
		out(q1,q2,q3,q4,q5);
		cin>>n;
	}
}

float med(int p[],int a,int b)
{
	if (a==b)
	{
		return p[a];
	}
	if ((a+b)%2==1)
	{
		return ((float)p[(a+b)/2]+p[(a+b)/2+1])/2;
	}
	return p[(a+b)/2];
}

void out(float q1,float q2,float q3,float q4,float q5)
{
	float a,b,c,d;
	a=q3-q1;
	b=q3-q2;
	c=q4-q3;
	d=q5-q3;
	if (a-d>-0.00001&&a-d<0.00001)
	{
		if (b-c>-0.00001&&b-c<0.00001)
		{
			cout<<"symmetric"<<endl;
			return;
		}
		if (b-c>0)
		{
			cout<<"left-skewed"<<endl;
			return;
		}
		else
		{
			cout<<"right-skewed"<<endl;
			return;
		}
	}
	if (a<d)
	{
		cout<<"right-skewed"<<endl;
		return;
	}
	else
	{
		cout<<"left-skewed"<<endl;
		return;
	}
	
}