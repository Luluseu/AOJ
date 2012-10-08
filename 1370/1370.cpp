#include <iostream>
#include <list>
using namespace std;

class state
{
public:
	int a,b,c;
};

bool operator ==(state a,state b)
{
	return (a.a==b.a&&a.b==b.b&&a.c==b.c);
}

list<state> exist,cur;
int a,b,c;



bool findstate(const state &t)
{
	list<state>::iterator p=exist.begin();
	while(p!=exist.end())
	{
		if(t==*p) return 1;
		++p;
	}
	return 0;
}

bool searchchild(state t)
{
	state tmp;
	int i,it;


	if(t.a!=0)
	{
		if(t.b!=b)
		{
			tmp.a=t.a>b-t.b?t.a+t.b-b:0;
			tmp.b=t.a>b-t.b?b:b-t.a-t.b;
			tmp.c=t.c;
			cur.push_front(tmp);
		}
		if(t.c!=c)
		{
			tmp.a=t.a>c-t.c?t.a+t.c-c:0;
			tmp.c=t.a>c-t.c?c:c-t.a-t.c;
			tmp.b=t.b;
			cur.push_front(tmp);
		}
	}

	if(t.b!=0)
	{
		if(t.a!=a)
		{
			tmp.b=t.b>a-t.a?t.a+t.b-a:0;
			tmp.a=t.b>a-t.a?a:a-t.a-t.b;
			tmp.c=t.c;
			cur.push_front(tmp);
		}
		if(t.c!=c)
		{
			tmp.b=t.b>c-t.c?t.b+t.c-c:0;
			tmp.c=t.b>c-t.c?c:c-t.b-t.c;
			tmp.a=t.a;
			cur.push_front(tmp);
		}
	}

	if(t.c!=0)
	{
		if(t.a!=a)
		{
			tmp.c=t.c>a-t.a?t.c+t.a-a:0;
			tmp.a=t.c>a-t.a?a:a-t.a-t.c;
			tmp.b=t.b;
			cur.push_front(tmp);
		}
		if(t.b!=b)
		{
			tmp.c=t.c>b-t.b?t.c+t.b-b:0;
			tmp.b=t.c>b-t.b?b:b-t.b-t.c;
			tmp.a=t.a;
			cur.push_front(tmp);
		}
	}
	

		return 0;
}


int main()
{
	
	
	list<state>::iterator p,p2;
	state t;
	cin>>a>>b>>c;
	
	t.a=0;
	t.b=0;
	t.c=c;

	cur.push_back(t);
	p=cur.begin();
	while(1)
	{
		if(findstate(*p))	//×´Ì¬´æÔÚ
			p=cur.erase(p)
			;
		else				//×´Ì¬²»´æÔÚ
		{
			searchchild(*p);
			p=cur.erase(p);
		}
		p2=cur.begin();
		cout<<"Cur================"<<endl;
		while(p2!=cur.end())
		{
			cout<<p2->a<<" "<<p2->b<<" "<<p2->c<<endl<<endl;
			p2++;
		}
		p2=exist.begin();
		cout<<"Exist================"<<endl;
		while(p2++!=exist.end())
			cout<<p2->a<<" "<<p2->b<<" "<<p2->c<<endl;

		if(p==cur.end())
		{
			if(cur.size!=0)
				p=cur.begin();
			else break;
		}
		
	}


	
}
