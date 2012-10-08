#include <iostream>
#include <set>
using namespace std;

class bridge
{
public:
	int a,b,w;
};



 int min(const int &a,const int &b)
{
	return a<b?a:b;
}


bridge B[5000];
int pos[101][2],n,m;


int main()
{
	freopen("1.txt","r",stdin);
	freopen("2.txt","w",stdout);
	int T,i,j,k;


	set<int> pset;

	cin>>T;
	for (i=0;i<T;++i)
	{
		cin>>n>>m;
		for (j=0;j<m;++j)
		{
			cin>>B[j].a>>B[j].b>>B[j].w;

		}

		for (j=2;j<101;++j)
		{
			pos[j][0]=0;
			pos[j][1]=-1;
		}
		pos[1][1]=0;
		pos[1][0]=1;

		pset.clear();
	
		pset.insert(1);
		for (j=0;j<m;++j)
		{
			if (B[j].a==1)
			{
				pos[B[j].b][1]=B[j].w;
			}
			else if (B[j].b==1)
			{
				pos[B[j].a][1]=B[j].w;
			}
		}
	
		while (1)
		{
			int tmp=0,num=0;
			for (j=2;j<=n;++j)
			{
				if (pos[j][0]==0)
				{
					if (pos[j][1]>tmp)
					{
						tmp=pos[j][1];
						num=j;
					}
				}
			}
			if (num==0)
			{
				break;
			}

				pset.insert(num);
				pos[num][0]=1;
				pos[num][1]=tmp;
				
				for (k=0;k<m;++k)
				{
					if (B[k].a==num)
					{
						if (!pset.count(B[k].b))
						{
							if (pos[B[k].b][1]<min(tmp,B[k].w))
							{
								pos[B[k].b][1]=min(tmp,B[k].w);
							}
						}
												
					}
					else if (B[k].b==num)
					{
						
						if (!pset.count(B[k].a))
						{
							if (pos[B[k].a][1]<min(tmp,B[k].w))
							{
								pos[B[k].a][1]=min(tmp,B[k].w);
							}
						}
					
					}
				}
				
				
				
			
		}
		
		
		
		cout<<"Case #"<<i+1<<":"<<endl;
		cout<<pos[n][1]<<endl<<endl;



	}



}