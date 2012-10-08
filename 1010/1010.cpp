#include <iostream>
#include <vector>
using namespace std;

int main()
{
        int n,i,j;
        int a[1000];
        bool f;
        vector<int> s;
        cin>>n;
        while(n)
        {
                cin>>a[0];
                while(a[0])
                {
                        for(i=1;i<n;++i)
                                cin>>a[i];
//***********************
                        f=0;
                        for(i=0;i<n;++i)
                        {
                                s.clear();
                                for(j=i+1;j<n;++j)
                                {
                                        if(a[j]<a[i])
                                        {
                                                if(!s.empty()&&a[j]>s[s.size()-1])
                                                {
                                                        f=1;
                                                        break;
                                                }
                                                else
                                                        s.push_back(a[j]);                                        
                                        }
                                }
                                if(f)
                                        break;
                        }
                        if(f)
                                cout<<"No"<<endl;
                        else
                                cout<<"Yes"<<endl;
						

//*************************
                        cin>>a[0];
						
                }
				cout<<endl;
                cin>>n;
        }
}
