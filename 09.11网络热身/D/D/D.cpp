// D.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdio.h>
int a[1000],b[1000],stding[1000];
int _tmain(int argc, _TCHAR* argv[])
{
    void ss(int,int);
    int t,i,j,tmp,end;
    scanf("%d",&t);
    while(t!=0){
    for(i=0;i<t;i++){
      scanf("%d%d",a+i,b+i); 
      stding[i]=i+1;              
                    }
    printf("%d",stding[0]);
    for(i=1;i<t;i++) printf(" %d",stding[i]);

     for(i=0;i<t;i++){
         for(j=0;j<t-1;j++){
              if(a[stding[j]]<a[stding[j+1]]){
                    tmp=stding[j];stding[j]=stding[j+1];stding[j+1]=tmp;                  
                                      }             
                            
                            }             
                      
                      }

    printf("%d",stding[0]);
    for(i=1;i<t;i++) printf(" %d",stding[i]);

         end=t-1;
     for(i=end;i>-1;i--){
            if(a[stding[i]]!=a[stding[i-1]]){
            ss(i,end);
            end=i-1;                      
                                               }            
                         
                         } 
    
    printf("%d",stding[0]);
    for(i=1;i<t;i++) printf(" %d",stding[i]);
    scanf("%d",&t);
                } 
	return 0;
}

void ss(int start,int end){
     int i,j,t=start-end,tmp;
     for(i=0;i<t;i++){
         for(j=start;j<end;j++){
              if(b[stding[j]]<b[stding[j+1]]){
                    tmp=stding[j];stding[j]=stding[j+1];stding[j+1]=tmp;                  
                                      }             
                            
                            }             
                      
                      }     

     }
