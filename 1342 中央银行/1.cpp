#include <stdio.h>
#include <math.h>
double si=0;
int m[110];
int num[500010];
int n;

int min(int sum);

int main(){
    int i,j,max,t,ooo;
    float value;
    scanf("%d%d",&n,&max);
    for(i=0;i<n;i++) scanf("%d",m+i);
    for(i=0;i<n;i++){
		for(j=0;j<n-1;j++){
			if(m[j]<m[j+1]){
				t=m[j];m[j]=m[j+1];m[j+1]=t;                  
				
			}                                                                                      
		}               
	}

	for (i=1;i<=max;++i)
	{
		if ((ooo=min(i))>100)
		{
			ooo=100;
		}
	//	printf("%d %d\n",i,ooo);
		if (ooo==-1)  continue;
		
		si+=1/(double)ooo;
	}



    value=1/log(n+1)*log(2)/log(max+1.71828)*si;
    printf("%.4f",value);

}


int min(int sum)
{
	int i;
	int r=-1,flag=0;
	for (i=0;i<n;++i)
	{
		if (sum==m[i])
		{
			return 1;
		}
	}
	
	for(i=0;i<n;++i)
	{
		if (sum-m[i]<0)  continue;

		if (num[sum-m[i]]==0)
		{
			num[sum-m[i]]=min(sum-m[i]);
		}

		if (num[sum-m[i]]==-1) continue;

		if (num[sum-m[i]]<r||flag==0)
		{
			flag=1;
			r=num[sum-m[i]];
		}
	}
	if (r!=-1)
	{
		return r+1;
	}
	else return -1;


}



