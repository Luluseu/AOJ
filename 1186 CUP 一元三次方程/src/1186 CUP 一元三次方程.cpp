#include <iostream>
#include <math.h>
using namespace std;

float a,b,c,d; //定义外部变量，使全局可以调用
float f(float x) //x函数
{
 float y;
 y=a*x*x*x+b*x*x+c*x+d;
 return y;
}

float xpoint(float x1,float x2) //求弦与x轴交点坐标
{
 float y;
 y=(x1*f(x2)-x2*f(x1))/(f(x2)-f(x1));
 return y;
}

float root(float x1,float x2) //求根函数
{
 float x,y,y1;
 y1=f(x1); //y1为x1纵坐标
 do
 {
  x=xpoint(x1,x2); //求x1与x2之间弦与x轴交点赋值于x
  y=f(x); //代入方程中求得y
  if(y*y1>0) //判断y与y1是否同号
  {
   x1=x;
      y1=y;
  }
  else
      x2=x;
 }
   while(fabs(y)>=0.00001); //设定精度
   return(x);
}

int main() {
	int  T;
	float r,R,H,v;
	cin>>T;
	while(T--)
	{
		cin>>r>>R>>H>>v;
		a=(R-r)*(R-r)/3/H/H;
		b=r*(R-r)/H;
		c=r*r;
		d=-v;
		cout<<root(0,101)<<endl;
	}
	return 0;
}
