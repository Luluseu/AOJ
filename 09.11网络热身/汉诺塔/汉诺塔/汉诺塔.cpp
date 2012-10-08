// 汉诺塔.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdio.h>

int _tmain(int argc, _TCHAR* argv[])
{
int n,i,a;
scanf("%d",&n);
while(n!=0){
if(n>0){
	a=1;
	for(i=0;i<n;i++){
	a*=2;
	a%=9973;
                 	}
    printf("%d\n",a-1);
           }
scanf("%d",&n);
}
	return 0;
}

