#include <iostream>
#include <math.h>
using namespace std;
 
int main()
{
    int n;
    int i;
    while(cin>>n)
    {
         
        i=2;
        bool f=1;
        while (i<sqrt(n)+1)
        {
            if (n%i==0)
            {
        if(f)
        {
        cout<<i;
        f=0;
         }else       cout<<' '<<i;
                n/=i;
            }
            else i++;
        }
if(n!=1)
 {
 if(!f)
            cout<<' ';
            cout<<n<<endl;
            }
            else
            cout<<endl;
             
         
    }
}
