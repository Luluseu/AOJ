#include <stdio.h>
#include <string.h>

int main(){
  
   char s[10000];
   int sum,i;
   gets(s);
   while(strcmp(s,"0")){

       sum=0;
       
       for(i=0;s[i]!='\0';i++){
     
         sum+=s[i]-'0';    
             
             
                            }                     
         printf("%d\n",sum);
         gets(s);                   
                            
                       }
    
    
    
    }
