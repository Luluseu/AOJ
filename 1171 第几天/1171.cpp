#include <iostream>

using namespace std;

int main ()
{
	int y,m,d,sum,i;
	int days[12]={31,28,31,30,31,30,31,31,30,31,30,31};
	char t;
	while(cin>>y)
	{
		cin>>t>>m>>t>>d;
		sum=0;	
		for(i=0;i<m-1;++i) sum+=days[i];
		sum+=d;
		if(m>2&&(y%400==0||(y%4==0&&y%100!=0))) sum++;
		cout<<sum<<endl;


	}
	
}