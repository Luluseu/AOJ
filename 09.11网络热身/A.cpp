
#include <stdio.h>

int main()
{
//freopen("1.txt","r+",stdin);
//freopen("2.txt","w+",stdout);
int n,i,j,a,d[100001]={0};
int p;
scanf("%d",&n);
while(n!=0){
   if(n>0){
	a=1;
	if(n/100>99999){p=99999;}
	else p=n/100;
	for(j=p;j>0;j--){
       if(d[j]!=0){
          a=d[j];
                   
          break;
                   }               
                      }
              
 
	for(i=j*100;i<n;i++){
    
    	a*=2;
    	if(a>9973) 	a%=9973;
    	if((i+1)%100==0)  d[(i+1)/100]=a;
                	}
    printf("%d\n",a-1);
          }
scanf("%d",&n);
             }
	
}
