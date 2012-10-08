#include <stdio.h>

bool map[101][101];
char ss[103];
int M,N;

void fill(int i,int j)
{
	map[i][j]=false;
	if(i>0 && map[i-1][j] ) fill(i-1,j) ;
	if(i<M-1 && map[i+1][j]  ) fill(i+1,j) ;
	if(j>0 && map[i][j-1]) fill(i,j-1) ;
	if(j<N-1 && map[i][j+1]) fill(i,j+1) ;

	if(i>0 && j>0 && map[i-1][j-1]) fill(i-1,j-1) ;
	if(i<M-1 && j>0 && map[i+1][j-1]) fill(i+1,j-1) ;
	if(i>0 && j<N-1 && map[i-1][j+1] ) fill(i-1,j+1) ;
	if(i<M-1 && j<N-1 && map[i+1][j+1] ) fill(i+1,j+1) ;
}

int main()
{
	int i,j,num=0;
	scanf("%d%d",&M,&N);
	for(i=0;i<M;++i)
	{
		scanf("%s",ss);
		for(j=0;j<N;++j)
		{
			if(ss[j]=='W') map[i][j]=true;
		}
	}

	for(i=0;i<M;++i)
		for(j=0;j<N;++j)
		{
			if(map[i][j]) {fill(i,j);num++;}
		}
	printf("%d\n",num);
}