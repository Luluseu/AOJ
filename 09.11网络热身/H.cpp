#include <stdio.h>

int main(){
freopen("1.txt","r+",stdin);
freopen("2.txt","w+",stdout);
    int x,y;
    char c;
    while(scanf("%c",&c)!=EOF)
            {
       scanf("%d%d\n",&x,&y);
       if(c=='L') printf("%d\n",x>y?x:y);
       else if(c=='S')  printf("%d\n",x<y?x:y);
       else printf("Input error!\n") ;                    
                               
                               
            }
    
    
    
         }
