#include <iostream>
#include <math.h>
using namespace std;

float a,b,c,d; //�����ⲿ������ʹȫ�ֿ��Ե���
float f(float x) //x����
{
 float y;
 y=a*x*x*x+b*x*x+c*x+d;
 return y;
}

float xpoint(float x1,float x2) //������x�ύ������
{
 float y;
 y=(x1*f(x2)-x2*f(x1))/(f(x2)-f(x1));
 return y;
}

float root(float x1,float x2) //�������
{
 float x,y,y1;
 y1=f(x1); //y1Ϊx1������
 do
 {
  x=xpoint(x1,x2); //��x1��x2֮������x�ύ�㸳ֵ��x
  y=f(x); //���뷽�������y
  if(y*y1>0) //�ж�y��y1�Ƿ�ͬ��
  {
   x1=x;
      y1=y;
  }
  else
      x2=x;
 }
   while(fabs(y)>=0.00001); //�趨����
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
