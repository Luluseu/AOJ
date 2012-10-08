#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
int sushu[80000];


int search(int sushu[],int len,int ob)
{
	int start=0,end=len-1;
	while (1)
	{
		if (end==start)
		{
			if (sushu[end]==ob)
			{
				return end;
			}
			else return -1;
			
		}
		if (sushu[(end+start)/2]==ob)
		{
			return	(end+start)/2;
		}
		if(sushu[(end+start)/2]>ob)
		{
			end=(end+start)/2;
			continue;
		}
		else if(sushu[(end+start)/2]<ob)
		{
			start=(end+start)/2+(end-start)%2;
			continue;
		}
	}
}





int main()
{
	
    int i=3,j,len=1;
    bool flag;
	
    sushu[0]=2;
    while(i!=900000-1)
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
		i+=2;
		
    }
//	cout<<len<<endl;
	i=0;
	/*
	while (i!=100)
	{
		cout<<sushu[i]<<" ";
		++i;
	}
*/
	int a,b;
	while (cin>>a)
	{
		cin>>b;
		cout<<upper_bound(sushu,sushu+len,b)-lower_bound(sushu,sushu+len,a)
			<<endl;
	}



}