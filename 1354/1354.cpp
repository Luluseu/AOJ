#include <iostream>
using namespace std;

int a[20][20];
int cur=0;

void insert(int m,int n)	//mÎªÈ¦£¬nÎª±ß³¤
{
	int i;
	for(i=0;i<n;++i)
	{
		a[m+i][m]=++cur;
	}
	for(i=1;i<n;++i)
	{
		a[m+n-1][m+i]=++cur;
	}
	for(i=1;i<n;++i)
	{
		a[m+n-i-1][m+n-1]=++cur;
	}
	for(i=2;i<n;++i)
	{
		a[m][m+n-i]=++cur;
	}
}

int main()
{
	int n;
	int i,j;

	while(cin>>n)
	{
	cur=0;
	for(i=0;i<n/2+n%2;++i)
	{
		insert(i,n-i*2);
	}

	for(i=0;i<n;++i)
	{
		for(j=0;j<n;++j)
		{
			printf("%d",a[i][j]);
			if(a[i][j]<100) printf(" ");
			if(a[i][j]<10) printf(" ");
		}
		printf("\n");
	}
	}
	


}