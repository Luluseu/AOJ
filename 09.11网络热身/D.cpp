#include <stdio.h>
int a[2000],b[2000],stding[2000];
int main(){
    void ss(int,int);
    int t,i,j,tmp,end;
    scanf("%d",&t);
    while(t!=0){
    for(i=0;i<t;i++){
      scanf("%d%d",a+i,b+i); 
      stding[i]=i;              
                    }
                 
  /*printf("%d",stding[0]);
    for(i=1;i<t;i++) printf(" %d",stding[i]);*/
     for(i=0;i<t;i++){
         for(j=0;j<t-1;j++){
              if(a[stding[j]]<a[stding[j+1]]){
                    tmp=stding[j];stding[j]=stding[j+1];stding[j+1]=tmp;                  
                                      }             
                            
                            }             
                      
                      }
                 
   /*  printf("%d",stding[0]);
    for(i=1;i<t;i++) printf(" %d",stding[i]);*/
         end=0;
     for(i=0;i<t;i++){
            if(a[stding[i]]!=a[stding[i+1]]){
            ss(end,i);
            end=i+1;                      
                                               }            
                         
                         } 
    ss(end,t-1);
    printf("%d",stding[0]+1);
    for(i=1;i<10;i++) printf(" %d",stding[i]+1);
    printf("\n");
    scanf("%d",&t);
                }    
    }

void ss(int start,int end){
     /*printf("\n%d%d\n",start,end);*/
     int i,j,t=end-start,tmp;
     for(i=0;i<t;i++){
         for(j=start;j<end;j++){
              if(b[stding[j]]>b[stding[j+1]]){
                    tmp=stding[j];stding[j]=stding[j+1];stding[j+1]=tmp;                  
                                      }             
                            
                            }             
                      
                      }     

     }
