#include <iostream>
#include <math.h>

using namespace std;

int main()
{

    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    double F,rbest=100,t;
    int D;
    int abest,bbest,a,b,lim;
    bool f;
    
    while (cin>>F>>D)
    {
        rbest=1000;
        abest=1;
        bbest=1;
        if (F>1)
        {
            lim=D/F;
        }else
            lim=D;
        for (b=1;b<=lim;++b)
        {
            f=0;
            for (a=(b*F<1?1:b*F);a<=D;++a)
            {
                                   
                t=(double)a/b-F;
                
                if (t<0)
                {
                    t=-t;
                }else
                {
                    if (!f)
                    {
                        f=1;
                    }else
                        break;
                }
                if (t<rbest )
                {
                    abest=a;
                    bbest=b;
                    rbest=t;
                }
            }
        }

        cout<<abest<<" "<<bbest<<endl;
    }

}