#include <iostream>
using namespace std;
int main()
{
    int a,b,c,d,e,f,g,sum,num,n;
    cin>>n;
    while(n)
    {
            num=0;
            for(a=0;a<n/100+1;a++)
            for(b=0;b<(n-100*a)/50+1;b++)             
            for(c=0;c<(n-100*a-50*b)/20+1;c++)
            for(d=0;d<(n-100*a-50*b-20*c)/10+1;d++)
            for(e=0;e<(n-100*a-50*b-20*c-10*d)/5+1;e++)
            for(f=0;f<(n-100*a-50*b-20*c-10*d-e*5)/2+5;f++)
            {
             sum=100*a+50*b+20*c+10*d+5*e+2*f;
             if(sum<=n)
             if(a+b+c+d+e+f+n-sum<=100)
             {
             num++;
             cout<<a<<" "<<b<<" "<<c<<" "<<d<<" "<<e<<" "<<f<<" "<<n-sum<<endl;
             }
                           
            }
      ex:
            cout<<num<<endl; 
            
            cin>>n;
    }
}
