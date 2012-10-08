#include<stdio.h>
int main(){int n,i;__int64 r=0,c=1;scanf("%d",&n);for(i=1;i<=n;++i){r+=(c*=i);}printf("%I64d\n",r);}
