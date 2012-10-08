#include <stdio.h>

int main(){
//freopen("1.txt","r+",stdin);
//freopen("2.txt","w+",stdout);
   int n,d[10001]={0};
   if(scanf("%d",&n)!=EOF){
     printf("%d",n);
     d[n]=1;                  
                           }
   else return 0;
   while(scanf("%d",&n)!=EOF)
     {
       if(d[n]==1) continue;
       d[n]=1;                       
       printf(" %d",n);
     
     } 
    
    
    }
