#include <iostream>
#include <algorithm>
using namespace std;

class proc
{
public:
	int a,b;
	proc(int t,int y):a(t),b(y){}
}

bool cmp1(const proc& p,const proc& q)
{
		return p.a<q.a?1:0;
}
bool cmp2(const proc& p,const proc& q)
{
		return p.a-p.b<q.a-q.b?1:0;
}

int main() {
	vector<proc> data;
	vector<proc> data2;
	int n,i,a,b;
	cin>>n;
	while(n)
	{
		data.clear();
		data2.clear();
		for(i=0;i<n;++i)
		{
			cin>>a>>b;
			if(a<b)
			data.push_back(proc(a,b));
			else
				data2.push_back(proc(a,b));
		}
		sort(data.begin(),data.end(),cmp1);
		sort(data2.begin(),data2.end(),cmp2);
		a=0;b=0;
		for(i=0;i<data.size();++i)
		{
			a+=data[i].a;
			b+=data[i].b;
		}

	cin>>n;
	}
	return 0;
}
