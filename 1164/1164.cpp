#include <stdio.h>

int main(){
    freopen("1.txt","r",stdin);
    freopen("2.txt","w",stdout);
    int a=0,b=0,c=0,d=0,flag=0;
    char t;
    
    while(1){
    a=0;b=0;c=0;d=0;
    while((t=getchar())!='\n'){
    if(t==EOF){flag=1;break;}
    if(t=='\b'||t=='\t') continue;     
     if((t>='A'&&t<='Z')||(t>='a'&&t<='z'))
			a++;
		else if(t>='0'&&t<='9')
			b++;
		else if(t==' ')
			c++;
		else 
			d++;
        
                              }
        if(flag) return 0;
        printf("%d %d %d %d\n",a,b,c,d);
    
                   }
    
    
    }
