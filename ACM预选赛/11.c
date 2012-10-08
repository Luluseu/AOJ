#include <stdio.h>


int  main(){
int a,i,j,x,max=1;
int r[50000]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
while(scanf("%d",&a)!=EOF){

r[0]=1;
max=1;
for(i=0;i<a;i++){
       //每4位用一个整数存放  
          
   for(j=0;j<max;j++){
        r[j]*=(i+1);              
                      }
   for(j=0;j<max;j++){
  
       if(r[j]>9999){
                    x=r[j]/10000;
                    
                   if(j==max-1) {max++;r[max-1]=0;}
                   r[j+1]+=x;
               
                   r[j]=r[j]-10000*x;
                
                   }         
                      }         
   
   
   

                 
            
       printf("%d",r[max-1]); 
   for(j=1;j<max;j++){
      if(r[max-1-j]<10) printf("000");
      else if(r[max-1-j]<100) printf("00");
      else if(r[max-1-j]<1000) printf("0");
      printf("%d",r[max-1-j]);          
                 }
                 printf("\n");
                 };

    }
