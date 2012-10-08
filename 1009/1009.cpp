#include <iostream>
#include <string>
using namespace std;

int main()
{
	string a;
	char t;
	int len,i,j;

	while (getline(cin,a))
	{	


		len=a.size();
		for (i=len/2-1;i>=0;--i)
		{
			if (i%2==0)				//ÆæÊý
			{
				j=i;
				t=a[j];
				while (j+i+1<len)
				{
					a[j]=a[j+i+1];
					j+=i+1;
				}
				a[j]=t;
			}
			else					//Å¼Êý
			{
				j=i+(len/(i+1)-1)*(i+1);
				t=a[j];
				while (j-(i+1)>=0)
				{
					a[j]=a[j-i-1];
					j-=i+1;
				}
				a[j]=t;

			}


		}
		cout<<a<<endl;
	}
}
