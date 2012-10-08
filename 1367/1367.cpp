#include <iostream>

using namespace std;

int gcd(int a,int b)
{
	int t;
	while(1)
	{
		if(a%b==0)  return b;
		t=b;
		b=a%b;
		a=t;
	}
}

int sq(int i,int n)
{
	int r=1;
	int k;
	for(k=0;k<n;++k)
	{
		r*=i;
	}
	return r;
}

int main()
{
	int n,m,i,j,k,sum,gys,gbs,tmp;
	bool flg,flag;
	int l[10];
	int c[10],len;

	while(cin>>n)
	{
		cin>>m;

		sum=0;
		//cout<<gcd(n,m)<<endl;
		for(i=0;i<n;++i)
		{
			cin>>l[i];
			//筛选倍数
			flag=0;
			for(j=0;j<i;++j) 
			{
			   if(l[i]%l[j]==0)
               {
                   flag=1;
         
               }
			   else
                if(l[j]%l[i]==0)
               {
                   flag=1;
                   l[j]=l[i];
               }
            }
            if(!flag)
			    ;
			else 
			   {
                  --n;
                  --i;             
               }
		}


	//	sum+=m/l[i]
		 
		for (i=0;i<n;++i)
		{
			sum+=m/l[i];
		}

	//	cout<<sum<<endl;

		for(i=2;i<n+1;++i)
		{
			//n进制，取i位，实现C(n,i)
			for(j=1;j<sq(n,i);++j)
			{
				tmp=j;
				for(k=0;k<i;++k)
				{
					c[k]=tmp%n;//存贮的是排列，低位为地位
					tmp/=n;

				}
				//判断排列是否超出范围
				if (c[i-1]>n-i)
				{
					continue;
				}
				//判断排列是否重复
				flg=0;
				for(k=0;k<i-1;++k)
				{
					if(c[k]<=c[k+1]) 
					{
						flg=1;
						break;
					}
				}
/*
				for(k=0;k<i;++k)
				{
					cout<<c[i-1-k]<<" ";
				}
				cout<<endl;
*/

				if (flg)
				{
					continue;
				}

				gys=l[c[0]];
				gbs=l[c[0]];
				for(k=0;k<i-1;++k)
				{
					gbs*=l[c[k+1]];
					gys=gcd(gys,l[c[k+1]]);
				}
				
				gbs=gbs/gys;

				if(i%2==0)
				{
					sum-=m/gbs;
				}
				else
				{
					sum+=m/gbs;
				}

			}

		}

		cout<<sum<<endl;








	}




	return 0;
}


