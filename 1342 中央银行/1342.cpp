#include <stdio.h>
#include <math.h>
float min,si;
int m[100];

int main(){
    int digui(int,int,int);
    int i,j,n,max,t;
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
	// for(i=0;i<n;i++) printf("m[%d]=%d ",i,m[i]);
    for(i=1;i<max+1;i++) {
		if(digui(0,i,n))   {
			if (min>100)
			{
				min=100;
			}
			si+=1/min;/*printf(" min=%f \n",min);*/
							}  
	}       
	// printf(" si=%f",si);
    value=1/log(n+1)*log(2)/log(max+1.71828)*si;
    printf("%.4f",value);
    getchar();getchar();
}

int digui(int step,int sum,int n){
	// printf("step=%d sum=%d n=%d",step,sum,n);
    int i,t=0;
    for(i=0;i<n;i++){
		t=0;
		if (sum==m[i])  {min=step+1;/*printf(" ||min=%f ",min); */return 1;}
		if (sum>m[i])  t=digui(step+1,sum-m[i],n);             
		if(t) return 1;             
	}
	return 0;
	
	
	
}

