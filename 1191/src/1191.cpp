
#include <iostream>
using namespace std;

int main() {
	char c;
	while((c=getchar())!=EOF)
	{
		switch(c)
		{
		case '<': cout<<"&lt;";
		break;
		case '>':cout<<"&gt;";
		break;
		case ' ':cout<<"&nbsp;";
		break;
		case '\t':cout<<"&#9;";
		break;
		default:
			cout<<c;
		}
	}
}
