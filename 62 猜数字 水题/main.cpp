#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int T,i;
	cin>>T;
	while (T--)
	{
		//string s1,s2;
		char s1[5],s2[5];
		int num1=0,num2=0;
		
		cin>>s1>>s2;
		
		for (i=0;i<4;++i)
		{
			if(s1[i]==s2[i]) {num1++; s1[i]=s2[i]=0;}
		}

		sort(s1,s1+4);
		sort(s2,s2+4);


		for (i=3;i>=0;--i)
		{
			if (s1[i]==0)
			{
				break;
			}
			if(s1[i]==s2[i]) num2++;
		}
		cout<<num1<<'A'<<num2<<'B'<<endl;
	}
}