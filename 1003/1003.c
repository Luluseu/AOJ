#include <stdio.h>

int main(){
    int x,y;
    int a,b;
    do{
    scanf("%d%d",&a,&b);
    if(a==0&&b==0) break;
    
    if(b%2!=0)
       {printf("Error\n");continue;}
    x=2*a-b/2;
    y=b/2-a;
    if(x<0||y<0) 
        {printf("Error\n"); continue;}
    printf("%d %d\n",x,y);    
                  
    
    }while(1);
   
    
    return 0;   
    
    }
