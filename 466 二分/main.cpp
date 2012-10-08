#include <stdio.h>


int N,M;
int x[100001];

int main()
{
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
    int i,j,start,end,sum=0,mid,m,r;
    bool fail,once=false;
    while(scanf("%d%d",&N,&M)!=EOF)
	{
    for (i=0;i<N;++i)
    {
        scanf("%d",x+i);
        sum+=x[i];
    }
    start=1;end=sum;
    while (start<=end)
    {
        mid=(start+end)/2;
        m=0;
        sum=0;
        fail=0;
        for (j=0;j<N;++j)
        {
            sum+=x[j];
            if (sum>mid)
            {
                sum=0;
                --j;
                m+=1;
                if (m>=M)
                {
                    start=mid+1;
                    fail=1;
                    break;
                }
            }
        }
        
        if (fail)
        {
            continue;
        }else
        {
            
            r=mid;
            end=mid;
        }
        if (start==end)
        {
            if (once)
            {
                break;
            }
            once=1;
        }
    }
    printf("%d\n",r);
	}
}
