#include  <stdio.h>
int main(){
    int m,i,a[3],t;
    scanf("%d",&m);
    for(i=0;i<m;i++){
        scanf("%d%d%d",a,a+1,a+2); 
        if(a[0]>a[1])  {t=a[0];a[0]=a[1];a[1]=t;}
        if(a[1]>a[2])  {t=a[1];a[1]=a[2];a[2]=t;}
        if(a[0]>a[1])  {t=a[0];a[0]=a[1];a[1]=t;}
                    
    if(a[0]+a[1]<=a[2]) printf("Wrong\n");
    else printf("%d\n",a[0]+a[1]+a[2]);
     }

    
    
    }
