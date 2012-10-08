#include <iostream>

using namespace std;

int main()
{
    int T,n,s,sum;
    cin>>T;
    while (T--)
    {
        cin>>n;
        sum=1-n;
        while (n--)
        {
            cin>>s;
            sum+=s;
        }
        cout<<sum<<endl;
    }
    return 0;
}