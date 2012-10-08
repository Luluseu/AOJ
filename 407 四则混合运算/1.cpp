#include <iostream>
#include <stack>
#include <string>
using namespace std;
stack<float> num;
stack<char> op;

int minop(char a,char b)
{
	int i,j;
	switch(a)
	{
	case '+':i=0;break;
	case '-':i=0;break;
	case '*':i=1;break;
	case '/':i=1;break;
	case '(':i=2;break;
	case ')':i=-1;break;
	case '#':i=-2;break;
	}
	switch(b)
	{
	case '+':j=0;break;
	case '-':j=0;break;
	case '*':j=1;break;
	case '/':j=1;break;
	case '(':j=2;break;
	case ')':j=-1;break;
	case '#':j=-2;break;
	}

	if (i<j)
	{
		return 1;
	}
	else return 0;
}

float cpt(float a,float b,char c)
{
	switch(c)
	{
	case '+':return a+b;break;
	case '-':return a-b;break;
	case '*':return a*b;break;
	case '/':return a/b;break;
	default: return 0;
	}
}

void PROC(char c)
{
//	cout<<"proc::::"<<c<<endl;
/*	if (!num.empty())
	{
		cout<<"numstack:"<<num.top();
	}
	else cout<<"numstack:     ";
	if (!op.empty())
	{
		cout<<"opstack:"<<op.top()<<endl;
	}
	else cout<<"opstack:     "<<endl;
*/
	float a,b;
	if (c<='9'&&c>='0')
	{
		num.push(c-'0');
	}
	else//操作符
	{
		if (minop(op.top(),c))//前面的<刚进的
		{
			op.push(c);
		}
		else
		{
			if (op.top()=='('&&c==')')
			{
				op.pop();
				return ;
			}
			else
			if (op.top()=='(')
			{
				op.push(c);
				return;
			}
			if (op.top()=='#'&&c=='#')
			{
				return;
			}
			b=num.top();
			num.pop();
			a=num.top();
			num.pop();
			num.push(cpt(a,b,op.top()));
			op.pop();
			PROC(c);
		}
	}
}


int main()
{
	string s;
	int i;
	while (cin>>s)
	{
		i=0;
		while (!num.empty()) num.pop();
		while (!op.empty()) op.pop();
		op.push('#');
		for (i=0;i<s.size();++i)
		{
			PROC(s[i]);
		}
		PROC('#');
		cout<<num.top()<<endl;
	}
}