#include <iostream>
#define MAXSTEP 10000
using namespace  std;

char map[10][10];
int M,N;
int nleft;
int mmin,depth;

int dfs(int m,int n)
{
    int i,j;

    char old[2][2];
    int min=0,num=0;
    if(n==N-1)
    {
        m+=1;
        n=0;
    }
    if(m==M-1) return 0;
    if (nleft==0)
    {
        if (mmin>depth)
        {
            mmin=depth;
        }
        return 0;
    }
    // 覆盖1
    if (map[m][n]=='o') num++;
    if (map[m][n+1]=='o') num++;
    if (map[m+1][n]=='o') num++;
    if (map[m+1][n+1]=='o') num++;
    
    if (num==nleft)
    {

        if (mmin>depth+1)
        {
            
            mmin=depth+1;
        }

        return 1;
    }
    
    
    if ((map[m][n]=='o' ||(n==N-2 && map[m][n+1]=='o') || ( m==M-2 && map[m+1][n]=='o')|| (n==N-2 && m==M-2 && map[M-1][N-1]=='o')) || 
		!(map[m][n]=='.'&&map[m][n+1]=='.' || map[m][n]=='.'&&map[m+1][n]=='.'))
    {
        //如果xxx, 必须覆盖
		
			old[0][0]=map[m][n];
			old[0][1]=map[m][n+1];
			old[1][0]=map[m+1][n];
			old[1][1]=map[m+1][n+1];
			
			map[m][n]='.';
			map[m][n+1]='.';
			map[m+1][n]='.';
			map[m+1][n+1]='.';
			
			nleft-=num;
			depth+=1;
			
			min=dfs(m,n+1);
			depth-=1;
			nleft+=num;
			
			map[m][n]=old[0][0];
			map[m][n+1]=old[0][1];
			map[m+1][n]=old[1][0];
			map[m+1][n+1]=old[1][1];
			
	  
    }

	
	if (map[m][n]=='o' ||(n==N-2 && map[m][n+1]=='o') || ( m==M-2 && map[m+1][n]=='o')|| (n==N-2 && m==M-2 && map[M-1][N-1]=='o'))
	{

	}
	else //不覆盖0
    {
        int t=dfs(m,n+1);
        if (!min || t<min+1)    //min=0表示跳过了放
        {
           return t;
        }
    }
	
	
    return min+1;
}


int main()
{

	freopen("in.txt","r",stdin);
	freopen("myout.txt","w",stdout);
	
    int i,j;
    while(cin>>M>>N)
    {
		if (!M)
		{
			break;
		}
        nleft=0;
        mmin=100000;
        depth=0;

        for (i=0;i<M;++i)
        {
            for (j=0;j<N;++j)
            {
                cin>>map[i][j];
                if (map[i][j]=='o')
                {
                    nleft++;
                }
            }
        } 
        cout<<dfs(0,0)<<endl;
   //     dfs(0,0);
    //    cout<<mmin<<endl;
    
    }
    return 0;
}