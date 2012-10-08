#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace  std;

struct point
{
	int x,y;
	int highest;
};
bool cmp(const point&a,const point &b)
{
	if (a.x==b.x)return a.y<b.y;
	return a.x<b.x;
}

point PP[102],P[102];

int main()
{
	int N,A,i,j,k,dis;
	cin>>N>>A;
	for (i=0;i<N;++i)
	{
		cin>>PP[i].x>>PP[i].y;
	}
	sort(PP,PP+N,cmp);
	//��������Ҫ�ĵ�
	int prex=-1;
	int n=0;
	for (i=0;i<N;++i)
	{
		if (PP[i].x==prex)
		{
			P[n-1].y=PP[i].y;
		}else
		{
			prex=P[n].x=PP[i].x;
			P[n++].y=PP[i].y;
		}
	}
	//�������󸲸Ƕ�ĵ�
	int sum=0;
	for (i=0;i<N;)
	{
		//ö�ٸ߶ȣ�ʹ���Ǹ���ĵ�
		sum++;
		int farest=i;
		for (j=P[i].highest;j<=A;++j)
		{
			dis=P[i].x+A/j; //����
			for (k=i+1;k<N;++k)
			{
				if (P[k].x<=dis && P[k].y<=j )
				{
					if (k>farest)
					{
						farest=k;
					}
				}else
					break;
			}
		}
		i=farest+1;
	}
	cout<<sum<<endl;

}