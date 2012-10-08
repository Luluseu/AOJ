#include <stdio.h>
int main(){
int a,i,j,max=1;
int r[50];
scanf("%d",&a);
a--;
r[0]=1;
for(i=0;i<a;i++){
       //每2位用一个整数存放          
   for(j=0;j<max;j++){
        r[j]*=2;              
                      }
   for(j=0;j<max;j++){
      //如果大于100，进位 
       if(r[j]>99){
                   if(j==max-1) max++;
                   r[j+1]+=1;r[j]-=100;}           
                      }         
                 
                 
                 }
       printf("%d ",r[max-1]); 
   for(j=1;j<max;j++){
      if(r[max-1-j]<10) printf("0");
      printf("%d ",r[max-1-j]);          
                 }
   printf("\n%d",max); 
  
   return; 
    
    }
