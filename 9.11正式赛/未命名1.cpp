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
    printf("m[]=%d",m[0]);
    for(i=1;i<max+1;i++) {
           if(digui(0,i,n))   {si+=1/min;printf(" min=%f ",min);}  
                         }       
    printf(" si=%f",si);
    value=1/log2(n+1)/log(max+1.71828)*si;
    printf(" v=%f ",value);
    getchar();getchar();getchar();getchar();
          }
    
int digui(int step,int sum,int n){
    printf("step=%d ",step);
    int i,t;
    for(i=0;i<n;i++){
       if (sum==m[i])  {min=step+1; return 1;}
       if (sum>m[i])  t=digui(step+1,sum-m[i],n);             
       if(t) return 1;             
                     }
     return 0;
     
     
     
     }
