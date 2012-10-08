#include <iostream>
#include <algorithm>
using namespace std;

int L,N;
int corner[1000001][2];

int max(const int & a,const int & b)
{
    return a<b?b:a;
}
int min(int  a,int  b)
{
    return a>b?b:a;
}


  int comp(const void *a,const void *b)
  {
      return ((int *)a)[0]-((int *)b)[0];
  }

int main()
{
    int i,maxv=1,curv=1,last,last2,vnew,v;
    cin>>L>>N;
    for (i=0;i<N;++i)           //[1]记录 最大速度
    {
        cin>>corner[i][0]>>corner[i][1];
    }

    qsort(corner,N,sizeof(int)*2,comp);

    last=0;
    for (i=0;i<N;++i)           //[0]记录变为，与前转角的距离
    {
        last2=corner[i][0];
        corner[i][0]-=last;
        last=last2;
    }
    //倒着计算出每个点的最大速度
    for (i=N-2;i>=0;--i)
    {
        corner[i][1]=min(corner[i][1],corner[i+1][1]+corner[i+1][0]);
    }
    for (i=0;i<N;++i)
    {
        vnew=min(corner[i][1],curv+corner[i][0]);

        v=(corner[i][0]+vnew+curv)/2;
        if (v>maxv)
        {
            maxv=v;
        }
        curv=vnew;
    }
    vnew=curv+L-last;
    v=(L-last+vnew+curv)/2;
    if (v>maxv)
    {
        maxv=v;
    }
    cout<<maxv<<endl;


}