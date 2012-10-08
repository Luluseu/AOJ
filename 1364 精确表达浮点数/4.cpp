#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int pow(int x,int y)
{
	int i,t=x;
	for (i=1;i<y;++i)
	{
		t*=x;
	}
	return t;
}



int gcd(int a,int b)
{
	int t;
	while(1)
	{
		if(a%b==0)  return b;
		t=b;
		b=a%b;
		a=t;
	}
}


int main()
{
	freopen("float.in","r",stdin);
	freopen("3.txt","w",stdout);
	int a,b,t,i,len1=1,len2=1,n,fenzi,fenmu,gys;
	char sa[10];
	scanf("%d",&n);
	for(i=0;i<n;++i)
	{
		scanf("%s",sa);
		a=atoi(sa);
		len1=strlen(sa);
		scanf("%s",sa);
		b=atoi(sa);

		len2=strlen(sa);

		
		fenzi=b;
		fenzi+=a*(pow(10,len2)-1);

		fenmu=pow(10,len1)*(pow(10,len2)-1);


		gys=gcd(fenzi,fenmu);
		printf("%d/%d\n",fenzi/gys,fenmu/gys);
		


		
	}
	
}