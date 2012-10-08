#include <iostream>

using namespace std;



int main()
{

	int y,m,d,sum,i,start,num,ys;

	int days[12]={31,28,31,30,31,30,31,31,30,31,30,31};
	char t;


	while (cin>>y)
	{

	ys=y;
		cin>>m>>d;

//计算第一天星期几

		sum=0;
		for(i=0;i<m-1;++i) sum+=days[i];
		sum+=d;
		if(m>2&&(y%400==0||(y%4==0&&y%100!=0))) sum++;

		start=sum;


			cin>>y;
			cin>>m>>d;
			sum=0;
			for(i=0;i<m-1;++i) sum+=days[i];
			sum+=d;
			if(m>2&&(y%400==0||(y%4==0&&y%100!=0))) sum++;

			for(i=ys;i<y;++i)
			{
				if (i%400==0||(i%4==0&&i%100!=0))
				{
					sum+=366;
				}
				else sum+=365;
			}




				cout<<sum-start<<endl;

	}


}
