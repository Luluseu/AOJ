#include <iostream>

using namespace std;

int main()
{
	freopen("1.txt","r",stdin);
	freopen("2.txt","w",stdout);
	int n,m,i,min,max,t;
	int ori[100000],ten[10000][2],han[1000][2],tho[100][2],tho10[10][2];
	cin>>n>>m;
/**********************************
输入原始串，并隔10统计
**********************************/
	for (i=0;i<n;++i)
	{
		cin>>ori[i];
		if (i%10==0)
		{
			if (i/10>0)
			{
				ten[i/10-1][0]=max;
				ten[i/10-1][1]=min;
			}
				
			max=ori[i];
			min=ori[i];
		}
		else
		{
			if (ori[i]>max)
			{
				max=ori[i];
			}
			else
			 if (ori[i]<min)
			{
				 min=ori[i];
			}
		}
	}
	ten[i/10][0]=max;
	ten[i/10][1]=min;

	for (i=0;i<n/10+1;i++)
	{
		cout<<ten[i][0]<<" "<<ten[i][1]<<endl;
	}
	/*******************************
	一百
	*******************************/
	if(n>99){
	for (i=0;i<n/10+1;++i)
	{
		if (i%10==0)
		{
			if (i/10>0)
			{
				han[i/10-1][0]=max;
				han[i/10-1][1]=min;
			}
			
			max=ten[i][0];
			min=ten[i][1];
		}
		else
		{
			if (ten[i][0]>max)
			{
				max=ten[i][0];
			}
			if (ten[i][1]<min)
			{
				min=ten[i][1];
			}
		}
	}
	han[i/10][0]=max;
	han[i/10][1]=min;

	for (i=0;i<n/100+1;i++)
	{
		cout<<han[i][0]<<" "<<han[i][1]<<endl;
	}
	}
	/************************
	千
	*************************/
	if (n>999)
	{
	for (i=0;i<n/100+1;++i)
	{
		if (i%10==0)
		{
			if (i/10>0)
			{
				tho[i/10-1][0]=max;
				tho[i/10-1][1]=min;
			}
			
			max=han[i][0];
			min=han[i][1];
		}
		else
		{
			if (han[i][0]>max)
			{
				max=han[i][0];
			}
			if (han[i][1]<min)
			{
				min=han[i][1];
			}
		}
	}
	tho[i/10][0]=max;
	tho[i/10][1]=min;
	
	for (i=0;i<n/1000+1;i++)
	{
		cout<<tho[i][0]<<" "<<tho[i][1]<<endl;
	}
	}
	/************************
	万
	*************************/
	if(n>9999){
	for (i=0;i<n/1000+1;++i)
	{
		if (i%10==0)
		{
			if (i/10>0)
			{
				tho10[i/10-1][0]=max;
				tho10[i/10-1][1]=min;
			}
			
			max=tho[i][0];
			min=tho[i][1];
		}
		else
		{
			if (tho[i][0]>max)
			{
				max=tho[i][0];
			}
			if (tho[i][1]<min)
			{
				min=tho[i][1];
			}
		}
	}
	tho10[i/10][0]=max;
	tho10[i/10][1]=min;
	
	for (i=0;i<n/1000+1;i++)
	{
		cout<<tho10[i][0]<<" "<<tho10[i][1]<<endl;
	}
				}


/*****************************

*****************************/
	int x,y,j,start,end;
	for (i=0;i<m;++i)
	{
		cin>>start>>end;
		--start;--end;
		max=ori[start];min=ori[start];
		if (start-end>10000)
		{
			x=start/10000;
			y=end/10000;
			
			for(j=x+1;j<y;j++)
			{
				if (max<tho10[j][0])
				{
					max=tho10[j][0];
				}
				if (min>tho10[j][1])
				{
					min=tho10[j][1];
				}
			}
			
		}

		if (start-end>1000)
		{
			x=start/1000;
			y=end/1000;
			
			for(j=x+1;j<(y<(x/10+1)*10?y:(x/10+1)*10);j++)
			{
				if (max<tho[j][0])
				{
					max=tho[j][0];
				}
				if (min>tho[j][1])
				{
					min=tho[j][1];
				}			
			}
			for(j=(x+1>y/10*10?x+1:y/10*10);j<y;j++)
			{
				if (max<tho[j][0])
				{
					max=tho[j][0];
				}
				if (min>tho[j][1])
				{
					min=tho[j][1];
				}			
			}
		}

		if (start-end>100)
		{
			x=start/100;
			y=end/100;
			
			for(j=x+1;j<(y<(x/10+1)*10?y:(x/10+1)*10);j++)
			{
				if (max<han[j][0])
				{
					max=han[j][0];
				}
				if (min>han[j][1])
				{
					min=han[j][1];
				}			
			}	
			
			for(j=(x+1>y/10*10?x+1:y/10*10);j<y;j++)
			{
				if (max<han[j][0])
				{
					max=han[j][0];
				}
				if (min>han[j][1])
				{
					min=han[j][1];
				}			
			}
		}

		if (start-end>10)
		{
			x=start/10;
			y=end/10;
			
			for(j=x+1;j<(y<(x/10+1)*10?y:(x/10+1)*10);j++)
			{
				if (max<ten[j][0])
				{
					max=ten[j][0];
				}
				if (min>ten[j][1])
				{
					min=ten[j][1];
				}			
			}
			
			for(j=(x+1>y/10*10?x+1:y/10*10);j<y;j++)
			{
				if (max<ten[j][0])
				{
					max=ten[j][0];
				}
				if (min>ten[j][1])
				{
					min=ten[j][1];
				}			
			}
		}

		{
			x=start;
			y=end;
			
			for(j=x-1;j<(y<(x/10+1)*10?y:(x/10+1)*10);j++)
			{
				if (max<ori[j])
				{
					max=ori[j];
				}
				if (min>ori[j])
				{
					min=ori[j];
				}			
			}
			
			for(j=(x-1>y/10*10?x-1:y/10*10);j<y;j++)
			{
				if (max<ori[j])
				{
					max=ori[j];
				}
				if (min>ori[j])
				{
					min=ori[j];
				}			
			}
		}

		cout<<max-min<<endl;
		

	}




}