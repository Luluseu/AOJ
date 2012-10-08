#include <iostream>
#include <string>
using namespace std;

class memberclass
{
public:
	memberclass():killed(0),kill(0),most(0),now(0){}
	int killed,kill;
	int most;
	int now;
};

bool operator >(const memberclass &a,const memberclass &b)
{
	if(a.most>b.most) return 1;
	else if(a.most==b.most)
	{
		if(a.kill>b.kill) return 1;
		else if(a.kill==b.kill)
		{
			if(a.killed<b.killed)
				return 1;
			else return 0;
		}
		else return 0;
	}
	else return 0;
}

int main()
{
	freopen("1.txt","r",stdin);
	freopen("2.txt","w",stdout);
	memberclass member[10];
	string s1,s2,s3;
	bool f=0;
	char *name[10]={"Killing Spree","Dominating","Mega Kill","Unstoppedable",
		"Wicked Sick","Monster Kill","God Like","Holy Shit"};
	int p1=0,p2=0,i,t=0,mvp=0;
	while(cin>>s1>>s2)
	{
	if(s2=="GG")
	{
		if(f)
		{
             cout<<endl;
        }
        f=1;
		if(s1=="A")
		{
			cout<<"F"<<" win the game, the point is "<<p1<<":"<<p2<<"."<<endl;
			
		}
		else
		{
			cout<<"A"<<" win the game, the point is "<<p1<<":"<<p2<<"."<<endl;
		}
		for(i=0;i<10;++i)
			{
				if(member[i].most>10) member[i].most=10;
			}
		for(i=0;i<10;++i)
			{
				if(member[i]>member[mvp]) mvp=i;
			}
				
		cout<<char('A'+mvp)<<" is the MVP, he got a "<<name[member[mvp].most-3>7?7:member[mvp].most-3]<<"!"<<endl;

        p1=0;p2=0;mvp=0;
for(i=0;i<10;++i)
{
	
//	cout<<member[i].kill<<" "<<member[i].killed<<" "<<member[i].most<<" "<<endl;
member[i].kill=0;
	member[i].killed=0;
	member[i].most=0;
	member[i].now=0;

}

	}
	else if(s2=="KILLED")
	{
		cin>>s3;
		member[s1[0]-'A'].kill++;
		member[s1[0]-'A'].now++;
		if(member[s1[0]-'A'].now>member[s1[0]-'A'].most) member[s1[0]-'A'].most++;
		member[s3[0]-'A'].killed++;
	    member[s3[0]-'A'].now=0;
		if(s1[0]<='E')
			p1++;
		else p2++;
		
	}
	}
}
