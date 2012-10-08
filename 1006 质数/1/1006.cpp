#include <iostream>
#include <vector>
#include <string>
#include <math.h>

using namespace std;
int sushu[10000000];
int main()
{
    //memset(sushu,-1,sizeof(sushu));
	
    int n,i=2,j,len=1;
	bool flag;
    sushu[0]=2;

    while(++i!=10000000)
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


	cout<<len<<endl;
/*
	for (j=0;j<sushu.size();j++)
	{
		cout<<sushu[j]<<" ";
	}
*/    
    
	return 0;
}

