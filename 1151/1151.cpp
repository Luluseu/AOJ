
#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
using namespace::std;

void string2vecint(string in,vector<int> &out)
{
	string::size_type i;
	int int_A;
	string stmp;
	while((i=in.size())!=0)
	{
		if(i>=4)
		{
			stmp=in.substr(i-4);
			int_A=atoi(stmp.c_str());
			out.push_back(int_A);
			in.erase(i-4,4);
		}
		else
		{
			stmp=in.substr(0);
			int_A=atoi(stmp.c_str());
			out.push_back(int_A);
			in.erase(0,in.size());
		}
		
	}
}


vector<int> func_multi(vector<int> a,int b)
{
	vector<int>::size_type i;
	for(i=0;i<a.size();i++)
	{
		a[i]*=b;
	}
	for(i=0;i<a.size();i++)
	{
		if(a[i]>=10000)
		{
			if(i==a.size()-1) a.push_back(0);
			a[i+1]+=a[i]/10000;
			a[i]=a[i]%10000;
		}
	}
	return a;
}

void func_add(vector<int> &sum,vector<int> a,int n)
{
	vector<int>::size_type i;
	for(i=0;i<a.size();i++)
	{
		if(i+n+1>sum.size()) sum.insert(sum.end(),i+n+1-sum.size(),0);
		sum[i+n]+=a[i];
	}
	// cout<<"输出add函数中sum:"<<endl; 
	// print(sum,4);
	
	for(i=0;i<sum.size();i++)
	{
		if(sum[i]>=10000)
		{
			if(i==sum.size()-1) sum.push_back(0);
			sum[i+1]+=sum[i]/10000;
			sum[i]=sum[i]%10000;
		}
	}
	
}



void mitoa(int a,char *s,int c)
{  int n,i=0;
char s2[10];

do
{
	s2[i++]=a%c+'0';       
	a=a/c;
}while(a>0);
for(n=0;n<i;n++) s[n]=s2[i-n-1];
s[n]='\0';
}

vector<int> func_multi(vector<int> a,vector<int> b)
{
	vector<int> r,tmp;
	vector<int>::size_type i;
	for(i=0;i<b.size();i++)
	{
		tmp=func_multi(a,b[i]);
		func_add(r,tmp,i);
		
	}
	return r;
}

void print(const vector<int> &sum,int nlog)
{ 
	vector<int>::size_type i;
	string s;
	int tmp;
	bool f=0;
	char ss[10]={0};
	for (i=0;i<sum.size();++i)
	{
		if (sum[i]!=0)
		{
			f=1;
			break;
		}
	}
	if (!f)
	{
		cout<<0;
	}
	else
	{
	//取头 
	mitoa(sum[sum.size()-1],ss,10);
	s+=ss;
	if(sum.size()>1){
		//取中间 
		for(i=sum.size()-2;i>0;i--)
		{
			if(sum[i]<10)
			{
				s+="000";
			}
			else if(sum[i]<100)
			{
				s+="00";
			}
			else if(sum[i]<1000)
			{
				s+="0";
			}
			mitoa(sum[i],ss,10); 
			s+=ss;
		}
		//取尾 
		if(sum[0]<10)
		{
			s+="000";
		}
		else if(sum[0]<100)
		{
			s+="00";
		}
		else if(sum[0]<1000)
		{
			s+="0";
		}
		mitoa(sum[0],ss,10); 
		s+=ss;            }
    
    
	//处理小数点
	tmp=s.size();
	if(nlog==0)
	{
		
	}
	else if(nlog>0)
	{
		s.append(nlog,'0');     
	}
	else if(nlog>-tmp)
	{
		s.insert(tmp+nlog,1,'.');
		i=s.find_last_not_of('0');
		s.erase(i+1,s.size()-i-1);
		if(s[s.size()-1]=='.') s.erase(s.size()-1,1);
	}
	else
	{
		s.insert((string::size_type)0,-(tmp+nlog),'0');
		s.insert((string::size_type)0,"0.");
		i=s.find_last_not_of('0');
		s.erase(i+1,s.size()-i-1);
		if(s[s.size()-1]=='.') s.erase(s.size()-1,1);
	}
	//删除前面的0
	i=s.find_first_not_of('0');
	s.erase(0,i); 
	cout<<""<<s;
	//  cin>>s; 
	}
}

int main()
{
	int t,i;
	vector<int> a,b,c;
	string sa,sb;
	cin>>t;
	for (i=0;i<t;++i)
	{
		cin>>sa>>sb;
		a.clear();
		b.clear();
		string2vecint(sa,a);
		string2vecint(sb,b);
		c=func_multi(a,b);
		cout<<"Case "<<i+1<<":"<<endl<<sa<<" * "<<sb<<" = ";
		print(c,0);
		cout<<endl<<endl;

	}
}