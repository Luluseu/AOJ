#include <iostream>
using namespace std;

char maze[202][202]={0};
int dp[202][202]={0};
bool steped[202][202]={0};
int w,h;

bool pass(int y,int x,int di) //x: lie y: hang
{

switch(di)
{
case 0: //up
if(y-2>0&&maze[y-1][x]!='-')
return 1;
else return 0;

case 1:
if(y+2<2*h&&maze[y+1][x]!='-')
return 1;
else return 0;

case 2: //left
if(x-2>0&&maze[y][x-1]!='|')
return 1;
else return 0;

case 3:
if(x+2<2*w&&maze[y][x+1]!='|')
return 1;
else return 0;

default:
return 0;
}
}

int step(int y,int x) //x: lie y: hang
{
	steped[y][x]=1;

	int i,j;
	cout<<endl<<"dp:"<<endl;
	for(i=1;i<2*h;i+=2)
	{
		for(j=1;j<2*w;j+=2)
			cout<<dp[i][j];
		cout<<endl;
	}
	cout<<endl;
	for(i=1;i<2*h;i+=2)
	{
		for(j=1;j<2*w;j+=2)
			cout<<steped[i][j];
		cout<<endl;
	}
	


int min=0,tmp;
if(dp[y][x]!=0) 
{
	steped[y][x]=0;
	return dp[y][x];
}


if(y==1)
if(maze[0][x]==' ') 
{
dp[y][x]=1;
steped[y][x]=0;
return 1;
}

if(x==1)
if(maze[y][0]==' ') 
{
dp[y][x]=1;
steped[y][x]=0;
return 1;
}

if(y==2*h-1)
if(maze[y+1][x]==' ') 
{
dp[y][x]=1;
steped[y][x]=0;
return 1;
}

if(x==2*w-1)
if(maze[y][x+1]==' ') 
{
dp[y][x]=1;
steped[y][x]=0;
return 1;
}

if(pass(y,x,0))
	if (!steped[y-2][x])
		min=step(y-2,x);
if(pass(y,x,1))
{
	if (!steped[y+2][x])
	{
		tmp=step(y+2,x);
		if (min==0)
		{
			min=tmp;
		}
		else
		{
			if (tmp!=0)
				if(min>tmp)
				min=tmp;
		}
		
	}

}
if(pass(y,x,2))
{
	if (!steped[y][x-2])
	{
		tmp=step(y,x-2);
		if (min==0)
		{
			min=tmp;
		}else
		{
			if (tmp!=0)
				if(min>tmp)
					min=tmp;
		}
		
	}

}
if(pass(y,x,3))
{
	if (!steped[y][x+2])
	{
		tmp=step(y,x+2);
		if (min==0)
		{
			min=tmp;
		}else
		{	
			if (tmp!=0)
				if(min>tmp)
				min=tmp;
		}
		
	}

}
if (min!=0)
{
	dp[y][x]=min+1;
	steped[y][x]=0;
	return min+1;
}
else
{
	steped[y][x]=0;
	return 0;
}
 
}

int main()
{
freopen("1.txt","r",stdin);
freopen("2.txt","w",stdout);
int i,j,max=0;

cin>>w>>h;
getchar();
for(i=0;i<2*h+1;++i)
{
for(j=0;j<2*w+1;++j)
{
maze[i][j]=getchar();
}
getchar();
}
//*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*
/*
for(i=0;i<2*h+1;++i)
{
for(j=0;j<2*w+1;++j)
cout<<maze[i][j];
cout<<endl;
}
cout<<"========================="<<endl;
*/
for(i=1;i<2*h;i+=2)
for(j=1;j<2*w;j+=2)
{
if(max<step(i,j))
max=step(i,j);
}

cout<<max;



}