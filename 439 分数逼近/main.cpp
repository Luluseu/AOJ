#include <iostream>
#include <math.h>
#define  eps 10e-8
#define min mmin
using namespace std;


double F,min;
int A,B,FF,D;
int nbetter;
void  go(int m,int n,int m1,int n1)
{
    int a,b;
    bool f=0;
    double t;

    while(1)
    {
        f=0;
        a=n+n1;
        b=m+m1;
        if (a+b*FF>D || b>D)
        {
            return;
        }
        t=(double)a/b-F;
        if (t<0)
        {
            f=1;
            t=-t;
        }
        if (t<min)
        {
            A=a;B=b;
            min=t;
            nbetter=0;
        }
        
        if (f)          //a/b<F
        {
            m=b;
            n=a;
        }else
        {
            m1=b;
            n1=a;
        }
    }
}


int main()
{
 //  freopen("in.txt","r",stdin);
  // freopen("outnew.txt","w",stdout);
   int m,n,m1,n1;
   while (cin>>F>>D)
   {
       B=1;
        m=m1=1;
        n=0;n1=1;
        min=1000000;
        nbetter=0;
        FF=F;           //取整数
        F-=FF;          //去小数
        if (F<eps && FF)      //处理整数
        {
            cout<<(FF<D?FF:D)<<" "<<1<<endl;
            continue;
        }
        //判断0 1
        
        if (FF && F<1-F)
        {
            A=0;
            min=F;
        }else
        {
            A=1;
            min=1-F;
        }

        go(m,n,m1,n1);

        cout<< ((A+FF*B)>D?D:(A+FF*B))<<" "<<B<<endl;
       
   }
    return 0;
}