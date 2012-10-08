#include <iostream>
bool a[10000000]={0};

using namespace std;
main()
{
	int i,j,t,n;
	a[1]=true;
	for(i=2;i<3400;i++)
	{
		if (a[i]==false)
		{
			j=i+i;
			while(j<10000001)
			{
				a[j]=true;
				j+=i;
			}
		}
	}

//	cout<<"done"<<endl;
	cin>>t;
	while(t!=0)
	{
		n=0;
		for (i=2;i<t+1;++i)
		{
			if (a[i]==false)
			          n++;
		}
		cout<<n<<endl;


		cin>>t;
	}

  }
  
  
  
/*	for (i=2;i<10000000;i++)
	{
		cout<<(a[i]?1:0)<<" ";
	}
*/