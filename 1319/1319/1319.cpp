// 1319.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdio.h>
#include <string.h>
#include <iostream>

using namespace std;
int citynum=0,ssid,eeid;
int steped[100],minstep;

/*
struct line{
       int citystart;
       int cityend;
       int s;
       int t;
   };
*/
   
struct city{
       
       char name[30];
       int line[20];
       int linenum;
       
       }cityinstant[100];
bool pro(int s, int t){
     if (s>6&&s<18) return false;
     if (t>12) return false;
     if (s+t>30) return false;
     return true;
     
     }

int nameid(char s[]){
    int i;
    for(i=0;i<citynum;i++){
         if(strcmp(cityinstant[i].name,s)==0)
             return i;
                           
                           }
    strcpy(cityinstant[i].name,s);
    citynum++;
    return i;
    
    }

int step(int cityid,int stepnum){
     
	steped[stepnum]=cityid;
     /////
   //  printf("stepmun=%d\n",stepnum);
     
     /////
     bool reached=false;
     int i,j;
     for(j=0;j<cityinstant[cityid].linenum;j++){
       if(cityinstant[cityid].line[j]==eeid){
               if((minstep==0)||(stepnum<minstep)) minstep=stepnum;
       //        printf(".......");
               return;                             
                                            }                                           
     
         for(i=0;i<stepnum;i++){
          if (steped[i]==cityinstant[cityid].line[j]){
                reached=true;
                break;
                                 }                  
                            }
          if(!reached){
              step(cityinstant[cityid].line[j],stepnum+1);         
                       }
          
        
        
                                                }
	   return;  
     }



int _tmain(int argc, _TCHAR* argv[])
{
	freopen("1.txt","r+",stdin);
    freopen("2.txt","w+",stdout);
    
    int n,m,i,j,s,t,tta,ttb/* ,onboard=0,days*/;
   // line connect[1000];
    
    char ss[30],ee[30],start[30],end[30];
    
    
    scanf("%d",&n);
    for(i=0;i<n;i++){
       citynum=0;
     //  onboard=0;
     //  days=0;
       minstep=0;
///////////////////////////////////  
    /////////////////////////
       scanf("%d",&m);
       for(j=0;j<m;j++){
         cin>>start;
         cin>>end;
         cin>>s;
         cin>>t;
      if(pro(s,t)){
     // connect[j].citystart=nameid(start) ;
		  tta=nameid(start);
      cityinstant[tta].line[cityinstant[tta].linenum++]=nameid(end);
     // connect[j].cityend=nameid(end);
    //  connect[j].s=s;
    //  connect[j].t=t;            
                  }                        
                        }      
    /////////////////////////
    /*
    for(days=0;days<10;days++){
           printf("%s\n",cityinstant[days].name);
      for(onboard=0;onboard<cityinstant[days].linenum;onboard++)
           printf("%d ",cityinstant[days].line[onboard])  ;    
		   */
   //////////////////////
    cin>>ss;
    cin>>ee;
    ssid=nameid(ss);
    eeid=nameid(ee);
    
    /////////////////////////
    step(ssid,0);
    
    /////////////////////////   
     
                        
     printf("Test Case %d.\n",i+1);                
     if(minstep!=0){                 
     printf("Vladimir needs %d litre(s) of blood\n",minstep);                   
                      }
     else printf("There is no route Vladimir can take.\n"); 
/////////////////////////////////////
                     }
}

