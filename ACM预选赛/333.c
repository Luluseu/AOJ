#include <stdio.h>
int main(){
int a,i,j,x,max=1;
int r[50]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
scanf("%d",&a);

r[0]=1;
for(i=0;i<a;i++){
       //每4位用一个整数存放  
          
   for(j=0;j<max;j++){
        r[j]*=2;              
                      }
   for(j=0;j<max;j++){
  
       if(r[j]>9999){
                    x=r[j]/10000;
                    
                   if(j==max-1) max++;
                   r[j+1]+=x;
               
                   r[j]=r[j]-10000*x;
                
                   }         
                      }         
   
   
   

                 
                 
                 }
       printf("%d",r[max-1]); 
   for(j=1;j<max;j++){
      if(r[max-1-j]<10) printf("000");
      else if(r[max-1-j]<100) printf("00");
      else if(r[max-1-j]<1000) printf("0");
      printf("%d",r[max-1-j]);          
                 }
system("pause");
   return 0; 
    
    }
