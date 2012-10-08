#include <stdio.h>

int main(){
   // freopen("1.txt","r+",stdin);
    //freopen("2.txt","w+",stdout);
    int n,a[1000],s,ss,i,m,p;

    
    while(scanf("%d%d",&n,&m)!=EOF){
        
       s=0;ss=0;
       p=1;
       for(i=1;i<=n;i++) a[i]=1;
       while(s!=n){
            if(a[p++]==0) {
                          if(p>n) p=1;
                          continue;} 
            ss++;
            
            if(ss==m){
               ss=0;
               a[p-1]=0;
               if(s==0) printf("%d",p-1);
               
               else printf(" %d",p-1);
               s++;
                     }       
             if(p>n) p=1;          
                       }         
                   
                       
               printf("\n\n");                     
                                    }
    
    
    
         }
