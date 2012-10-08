#include <iostream>

using namespace std;

int N,P;
int hash[1000000];
int next(int n)
{
    int r=0;
    int l,i,k;
    while(n)
    {
        l=1;
        k=n%10;
        for (i=0;i<P;++i)
        {
            l*=k;
        }
        r+=l;
        n/=10;
    }
    return r;
}


int main()
{
    
    int i=0,temp;

    cin>>N>>P;
    
    temp=N;
    hash[N]=-1;
    while (!hash[(temp=next(temp))])
    {
        i++;
        hash[temp]=i;
    }
    if (hash[temp]==-1)
    {
        cout<<0<<endl;
        return 0;
    }
    cout<<hash[temp]<<endl;
    return 0;
}