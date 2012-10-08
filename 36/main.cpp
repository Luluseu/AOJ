#include <stdio.h>
#include <string.h>

bool getnum(char a,char b)
{


	if (a=='0' || b=='0')
	{
		return false;
	}
	if (a=='1' || (a=='2' && b<='6'))
	{
		return true;
	}
	return false;

	return (10*(a-'0')+b-'0')>26;
}
int main()
{
	int num1,num2;
	char a,b;
	while ((a=getchar())!='0')
	{
		num1=1;num2=1;
		while(b=getchar(),b>='0' && b<='9')
		{
			if( a=='0')
			{
				a=b;
				num1=num2;
				continue;
			}
			if( b=='0')
			{
				a=b;
				int t=num2;
				num2=num1;
				num1=t;
				continue;
			}
			if(a=='1' || (a=='2' && b<='6'))
			{
				int t=num1;
				num1=num2;
				num2=t+num2;
				a=b;
				continue;
			}
			a=b;
			num1=num2;

		}
		printf("%d\n",num2);
	}
}