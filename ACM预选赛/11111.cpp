#include <stdio.h>
int main(){
int a,i,j,x,max=1;
int r[50]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
scanf("%d",&a);


r[0]=1;
for(i=0;i<a;i++){
       //ÿ4λ��һ���������  
      //  printf("���е�%d��\n",i+1);        
   for(j=0;j<max;j++){
        r[j]*=(i+1);              
                      }
   for(j=0;j<max;j++){
      //�������10000����λ 
       if(r[j]>9999){
                    x=r[j]/10000;
                   // printf("��λ\n"); 
                   if(j==max-1) {max++;r[max-1]=0;}
                   r[j+1]+=x;
                 //  printf("qianr[j]=%d\n",r[j]); 
                   r[j]=r[j]-10000*x;
                //   printf("r[j]=%d\n",r[j]); 
                   }         
                      }         
   
   
   
  // printf("���%d ",r[max-1]); 
  /* for(j=1;j<max;j++){
      if(r[max-1-j]<10) printf("000");
      if(r[max-1-j]<100) printf("00");
      if(r[max-1-j]<1000) printf("0");
      printf("%d",r[max-1-j]);          
                 }
                 */
   //printf("\nλ����%d",max);
   
                 
                 
                 }
       printf("%d",r[max-1]); 
   for(j=1;j<max;j++){
      if(r[max-1-j]<10) printf("000");
      if(r[max-1-j]<100) printf("00");
      if(r[max-1-j]<1000) printf("0");
      printf("%d",r[max-1-j]);          
                 }
  // printf("\n%d",max); 
 printf("\n");

    
    }
