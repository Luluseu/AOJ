#include <iostream>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

class P
{
public:
	bool passed;
	int n;
	P(){passed=0;n=0;};
};

class user
{
public:
	string name;
	int num;
	int th,tm,ts;
	map<string,P> problem;
	int rank;

	user(){
	num=0;th=0;tm=0;ts=0;
	};
};

bool cmp(const user &a,const user &b)
{
	if(a.num>b.num)
		return 1;
	if(a.num<b.num)
		return 0;
	if(a.th<b.th)
		return 1;
	if(a.th>b.th)
		return 0;
	if(a.tm<b.tm)
		return 1;
	if(a.tm>b.tm)
		return 0;
	if(a.ts<b.ts)
		return 1;
	if(a.ts>b.ts)
		return 0;
	if(a.name<b.name)
		return 1;
	else return 0;
}

int main()
{
	freopen("1.txt","r",stdin);
	freopen("2.txt","w",stdout);

	map<string,user> data;
	map<string,user>::iterator it;
	vector<user> udata;
	vector<user>::iterator it2;
	string ss,sp,sr,s;
	char t;
	int th,tm,ts,i;
	while(getline(cin,s))
	{
		//cout<<"["<<s<<"]"<<endl;
		stringstream sst(s);
		sst>>ss>>sp>>th>>t>>tm>>t>>ts>>sr;
		//cout<<"canshu...."<<ss<<sp<<th<<t<<tm<<t<<ts<<sr<<endl;
		//if(data.find(ss)!=data.end())//finded
		{
			//if(data[ss].problem.find(sp)!=data[ss].problem.end())
			{
				/*if(data[ss].problem.find(sp)==data[ss].problem.end())
					data[ss].problem[sp].n=0;*/
				if(sr=="Accepted")
				{
					//cout<<"chushi...:::"<<data[ss].th<<":"<<data[ss].tm<<":"<<data[ss].ts<<endl<<endl;
					if(data[ss].problem[sp].passed==1)
						continue;
					data[ss].problem[sp].passed=1;
					data[ss].num+=1;

					data[ss].ts+=ts;
					i=data[ss].ts/60;
					data[ss].ts%=60;
					/*cout<<"TTTT<< "<<20*data[ss].problem[sp].n+tm+i;
					cout<<" ???TTT<< "<<data[ss].problem[sp].n;
					cout<<"  TTTT<< "<<tm;
					cout<<"  TTTT<< "<<i;
					*/
					data[ss].tm+=20*data[ss].problem[sp].n+tm+i;
					i=data[ss].tm/60;
					data[ss].tm%=60;

					data[ss].th+=th+i;

					//cout<<"time:::"<<data[ss].th<<":"<<data[ss].tm<<":"<<data[ss].ts<<endl<<endl;

				}else
				{
					data[ss].problem[sp].n+=1;
				}

			}
		}
	}
	it=data.begin();
	while(it!=data.end())
	{
		it->second.name=it->first;
	
		///////
		//cout<<it->second.name<<" "<<it->second.num<<" "<<it->second.th<<":"<<it->second.tm<<":"<<it->second.ts<<endl;
		//////

		udata.push_back(it->second);
		++it;
	}
	sort(udata.begin(),udata.end(),cmp);
	it2=udata.begin();
	i=1;
	while(it2!=udata.end())
	{
		
		if(it2->num==0) cout<<"- ";
		else
		{
			if(it2==udata.begin())
				it2->rank=1;
			else
			{
				if(it2->num==(it2-1)->num&&it2->th==(it2-1)->th&&it2->tm==(it2-1)->tm&&it2->ts==(it2-1)->ts)
					it2->rank=(it2-1)->rank;
					//it2->rank=i;
				else
					it2->rank=++i;
			}
			cout<<it2->rank<<" ";
		}
		 cout<<it2->name<<" "<<it2->num<<" ";
	
		 cout<<it2->th<<":";
		 if(it2->tm<10) cout<<"0";
		 cout<<it2->tm<<":";
		 if(it2->ts<10) cout<<"0";
		 cout<<it2->ts<<endl;
		
		 ++it2;
	}
}

