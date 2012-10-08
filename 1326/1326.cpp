#include <iostream>
#include <string>
using namespace std;

bool similar(char a,char b)
{
	if(a<='9'&&a>='0'&&b<='9'&&b>='0')
		return true;
	if(a<='z'&&a>='a'&&b<='z'&&b>='a')
		return true;
	if(a<='Z'&&a>='A'&&b<='Z'&&b>='A')
		return true;
	return false;
}

char convert(const char &c,int f)
{
	if (f==2)
	{
		if (c<='9'&&c>='0'||(c<='Z'&&c>='A'))
		{
			return c;
		}
		else
		{
			return c+'A'-'a';
		}
	}
	else if (f==1)
	{
		if (c<='9'&&c>='0'||(c<='z'&&c>='a'))
		{
			return c;
		}
		else
		{
			return c+'a'-'A';
		}
	}
}

int main()
{
	int p1,p2,p3;
	//p1（1 2 3）小写 大写 *
	//p2 重复个数
	//p3 顺逆
	int i,j,k,a,b;
	string s;
	freopen("1.txt","r",stdin);
	freopen("2.txt","w",stdout);
	cin>>p1>>p2>>p3;
	cin>>s;

	for(i=0;i<s.size();++i)
	{
		if(s[i]!='-') cout<<s[i];
		else if(similar(s[i-1],s[i+1]))
		{
			if(similar(s[i-1],s[i+1])&&s[i-1]==s[i+1]-1)
				continue;
			else if(similar(s[i-1],s[i+1])&&s[i-1]<s[i+1]-1)
			{
				if(p1==3)
					for(j=0;j<(s[i+1]-s[i-1]-1)*p2;++j) cout<<'*';
				else	//非*
				{
					if(p3==1)	//顺序
					{
						for(j=0;j<s[i+1]-s[i-1]-1;++j)	//输出
						{
							for(k=0;k<p2;++k)	//重复
							{
								cout<<convert(s[i-1]+j+1,p1);
							}
						}
					}
					else if(p3==2)		//逆序
					{
						for(j=s[i+1]-1;j>s[i-1];--j)	//输出
						{
							for(k=0;k<p2;++k)	//重复
							{
								cout<<convert(j,p1);
							}
						}
					}
				}
			}
			else cout<<s[i];
		}
		else cout<<s[i];
	}
	



}