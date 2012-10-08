#include <iostream>

using namespace std;

int   dayofweek(   int   year,   int   month,   int   day   )   
{   
	int   a   =   (14-month)   /   12;   
	int   y   =   year   -   a;   
	int   m   =   month   +   12*a   -   2;   
	return   (day   +   y   +   y/4   -   y/100   +   y/400   +   (31*m)/12)   %   7;   
}  

int main()
{
	freopen("1.txt","r",stdin);
	freopen("2.txt","w",stdout);
	int y,m,d,sum,i,start,num,ys;
	int pianyi;
	int days[12]={31,28,31,30,31,30,31,31,30,31,30,31};
	char t;
	
	cin>>y;
	while (y!=0)
	{
		
	ys=y;
		cin>>t>>m>>t>>d;

//计算第一天星期几
		pianyi=dayofweek(y,m,d);
		sum=0;	
		for(i=0;i<m-1;++i) sum+=days[i];
		sum+=d;
		if(m>2&&(y%400==0||(y%4==0&&y%100!=0))) sum++;
		
		start=sum;
		
		cin>>num;

		while(num--!=0)
		{	
			cin>>y;
			cin>>t>>m>>t>>d;
			sum=0;	
			for(i=0;i<m-1;++i) sum+=days[i];
			sum+=d;
			if(m>2&&(y%400==0||(y%4==0&&y%100!=0))) sum++;

			for(i=ys;i<y;++i)
			{
				if (i%400==0||(i%4==0&&i%100!=0))
				{
					sum+=366;
				}
				else sum+=365;
			}



			cout<<"this day is the ";
			if (pianyi!=0)
			{
				cout<<(sum-start+pianyi-1)/7+1;
			}
			else
			{
				cout<<(sum-start+6)/7+1;
			}
			
			cout<<"-th week"<<endl<<endl;
			
			
		}
	cin>>y;
	}
	
	
}