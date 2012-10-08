#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	int sushu[100000];
	int i=2,j,len=1,n,sum,x;
	bool flag;
	sushu[0]=2;
    while(++i!=100000)
    {
		flag=false;
		for(j=0;j<len&&sushu[j]<sqrt(i)+1;j++)
		{
			if (i%sushu[j]==0)
			{
				flag=true;
				break;
			}			
		}
		if (!flag)
		{
			sushu[len++]=i;
		}
		
    }
	/*for(i=0;i<len;i++)
		cout<<sushu[i]<<" ";
		*/
	while(cin>>n)
	{
		if(n==0) break;
		x=0;
		for(i=0;i<n/2+1;++i)
		{
			sum=0;
			for(j=i;;++j)
			{
				sum+=sushu[j];
				if(sum==n)
				{
					x+=1;
					break;
				}
				if(sum>n)
					break;
			}
		}

		cout<<x<<endl;
	}

	


}