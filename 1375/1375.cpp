#include <stdio.h>
#include <iostream>
int main()
{
	freopen("1.txt","r",stdin);
	freopen("2.txt","w",stdout);
	int i,t;
	std::cin>>i;
	while (i--!=0)
	{
		std::cin>>t;
		std::cout<<(char)t;
	}
}