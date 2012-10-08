#include <stdio.h>
#include <string.h>
int cmp(char *a,char *b){
     if(b[0]=='\0') return(1);
     if(b[0]!=a[0]) return(0);
     if(b[0]==a[0])  return(cmp(a+1,b+1));
  
     }


int main(){
    int i,p,n,flag;
    char a[120],b[120];
    scanf("%d\n",&n);
    for(i=0;i<n;i++){
        flag=0;
        gets(a);
        
        gets(b);
        for(p=0;p<strlen(a)-strlen(b)+1;p++){
           if(cmp(a+p,b)){printf("%d\n",p+1);flag=1;break;}        
           }            
           if(flag==0) printf("-1\n");
                    }
        
     } 
     

