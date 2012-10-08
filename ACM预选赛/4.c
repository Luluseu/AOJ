#include <stdio.h>
int i,yy,mm,dd;
int main(){
int days(int,int,int); 
int i;
int n,y[50],m[50],d[50],r[50];
scanf("%d%d%d",&yy,&mm,&dd);  
scanf("%d",&n);
for(i=0;i<n;i++){
        scanf("%d%d%d",&y[i],&m[i],&d[i]);         
              }
for(i=0;i<n;i++) r[i]=days(y[i],m[i],d[i]);            
for(i=0;i<n;i++) printf("%d\n",r[i]);
system("pause");
    }

int days(int y,int m,int d){
    int r=0;
   int i,md[]={31,28,31,30,31,30,31,31,30,31,30,31};
   //1
   r+=365*(y-yy);
    //2
    if(y-yy>=1){
      for(i=yy;i<y;i++){
          if(((i%4==0)&&i%100!=0)||i%400==0) r++;                
                   }
              }
    //3
    for(i=0;i<m-1;i++) r+=md[i];
    //4
    r+=d;
    if(((y%4==0)&&y%100!=0)||y%400==0){
          if(m>=3) r++;                             
                                        }
    //5
    for(i=0;i<mm-1;i++) r=r-md[i];
    r=r-dd;
     if(((yy%4==0)&&yy%100!=0)||yy%400==0){
          if(mm>=3) r--;                        
                                        }
    
    return r;
    }
