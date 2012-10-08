#include <iostream>
#include <string>

using namespace std;

bool isPal(string num)
{
	int i;
	bool r=true;
	for(i=0;i<num.size()/2;++i)
	{
		if(num[i]!=num[num.size()-i-1])
		{
			r=false;
			break;

		}
	}
	return r;
}



int main()
{
	int n,s,t,i,j,x;
	string num;
	cin>>n>>s;
	for(i=0;i<n;++i)
	{
		x=0;
		for(j=2;j<11;++j)
		{
			t=s+i+1;
			num.erase(num.begin(),num.end());
			while(t/j!=0)
			{
				num.insert(num.begin(),(unsigned int)1,(char)('0'+t%j));
				t/=j;
			}
			num.insert(num.begin(),(unsigned int)1,(char)('0'+t%j));
			//cout<<"base:"<<j<<" "<<num<<endl;
			if(isPal(num)) ++x;
			if(x==2) 
			{
				cout<<s+i+1<<endl;
				break;
			}
		}
	}
}
