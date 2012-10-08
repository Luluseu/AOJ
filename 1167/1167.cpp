#include <iostream>

using namespace std;

int  main()
{
	int sco;
	while(cin>>sco)
	{
		if(sco>100||sco<0) 
		{
			cout<<"Score is error!"<<endl;
			continue;
		}
		switch (sco/10)
		{
		case 0:
		case 1:
		case 2:
		case 3:
		case 4:
		case 5:
			cout<<"E"<<endl;
			break;
		case 6:
			cout<<"D"<<endl;
			break;
		case 7:
			cout<<"C"<<endl;
			break;
		case 8:
			cout<<"B"<<endl;
			break;
		case 9:
		case 10:
			cout<<"A"<<endl;
			break;
		}
	}
}