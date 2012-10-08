#include <stdio.h>
int main(){
    int num=0,i,j,a[1000],b[1000],m,n;
    scanf("%d%d",&m,&n);
    for(i=0;i<m;i++) scanf("%d",&a[i]);
    for(i=0;i<n;i++) scanf("%d",&b[i]);
    i=0;j=0;
    do{
     if(a[i]==b[j]){
     num++;
     i++;j++;
     }                            
     else if(a[i]>b[j]) j++;               
      else i++;               
                     
    }while(i<m&&j<n);
    printf("%d",num);
//system("pause");    
    }
