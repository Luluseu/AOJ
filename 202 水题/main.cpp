#include <stdio.h>

int main()
{
	int sum=0,i,p;
	char c;
	for(i=0;i<9;++i)
	{
		c=getchar();
		if(c=='?') p=10-i;
		else sum+=(10-i)*(c-'0');
	}
	c=getchar();
	if(c=='X') sum+=10;
	else if(c=='?') p=1;
	else sum+=c-'0';
	for(i=0;i<10;++i)
	{
		if(0==(sum+i*p)%11) {printf("%d\n",i);	return 0;}
	}
	if(p==1 && 0==(sum+10*p)%11) printf("X\n");
	else printf("-1\n");
	return 0;
}