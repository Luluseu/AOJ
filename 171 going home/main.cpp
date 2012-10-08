#include <cstdio>
#include <iostream>

using namespace std;


#include <string.h>
#define MAXN 210
#define inf 1000000000
#define _clr(x) memset(x,-1,sizeof(int)*MAXN)

int kuhn_munkras(int m,int n,int mat[][MAXN],int* match1,int* match2){
	int s[MAXN],t[MAXN],l1[MAXN],l2[MAXN],p,q,ret=0,i,j,k;
	for (i=0;i<m;i++){
		for (l1[i]=-inf,j=0;j<n;j++)
			l1[i]=mat[i][j]>l1[i]?mat[i][j]:l1[i];
		if( l1[i] == -inf ) return -1;// 无法匹配！
	}
	for (i=0;i<n;l2[i++]=0);
	for (_clr(match1),_clr(match2),i=0;i<m;i++){
		for (_clr(t),s[p=q=0]=i;p<=q&&match1[i]<0;p++)
			for (k=s[p],j=0;j<n&&match1[i]<0;j++)
				if (l1[k]+l2[j]==mat[k][j]&&t[j]<0){
					s[++q]=match2[j],t[j]=k;
					if (s[q]<0)
						for (p=j;p>=0;j=p)
							match2[j]=k=t[j],p=match1[k],match1[k]=j;
				}
				if (match1[i]<0){
					for (i--,p=inf,k=0;k<=q;k++)
						for (j=0;j<n;j++)
							if (t[j]<0&&l1[s[k]]+l2[j]-mat[s[k]][j]<p)
								p=l1[s[k]]+l2[j]-mat[s[k]][j];
							for (j=0;j<n;l2[j]+=t[j]<0?0:p,j++);
							for (k=0;k<=q;l1[s[k++]]-=p);
				}
	}
	for (i=0;i<m;i++)
	{// if处理无匹配的情况！！
	//	if( match[i] < 0 ) return -1;
	//	if( mat[i][match[i]] <= -inf ) return -1;
		ret+=mat[i][match1[i]];
	}
	return ret;
}


int MMap[MAXN][MAXN];

int fbs(int a)
{
	if (a>0)
	{
		return a;
	}else
		return -a;
}

int main()
{
	int M,N,i,j;
	int nH=0,nM=0;
	int HS[105][2],MS[105][2];
	int Match1[MAXN],Match2[MAXN];

	while (cin>>M>>N,M||N)
	{
		nM=nH=0;
		for (i=0;i<M;++i)
		{
			for(j=0;j<N;++j)
			{
				char c;
				cin>>c;
				if (c=='m')
				{
					MS[nM][0]=i;
					MS[nM++][1]=j;
				}else if(c=='H')
				{
					HS[nH][0]=i;
					HS[nH++][1]=j;
				}
			}
		}
	//	cout<<nM<<"-"<<nH<<endl;
		for (i=0;i<nM;++i)
		{
			for (j=0;j<nH;++j)
			{
				MMap[i][j]=20000-fbs(MS[i][0]-HS[j][0])-fbs(MS[i][1]-HS[j][1]);
			}
		}
		cout<<20000*nH-kuhn_munkras(nM,nH,MMap,Match1,Match2)<<endl;
	}
}