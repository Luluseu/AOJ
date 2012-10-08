#include <stdio.h>

int main(){
      freopen("in.txt","r",stdin);
      freopen("out.txt","w",stdout);
    long m,n,i,j,x,flag;
    long a[5]={6,28,496,8128,33550336};
    scanf("%d %d",&m,&n);
    while(m!=0||n!=0){
      flag=0;
     for(x=0;a[x]<m;x++) if(x==4) {flag=1;break;};
     i=x;
     for(x=4;a[x]>n;x--) if(x==0) {flag=1;break;};               
     j=x;
      if(flag)  printf("No\n");
      else{
      if(j<i) printf("No\n");
      else{
      for(;i<j+1;i++) {printf("%d",a[i]);if (i!=j) printf(" ");}
           printf("\n");    }        
              }  
           
     scanf("%d %d",&m,&n);                 
                      
                      }
    

    }
