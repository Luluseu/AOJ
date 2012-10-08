#include <iostream>
#include <math.h>
using namespace std;

class rect22
{
public:
	int a11,a12,a21,a22;
public:
	rect22():a11(0),a12(0),a21(0),a22(0){}
	rect22(int a,int b,int c,int d):a11(a),a12(b),a21(c),a22(d){};

	rect22 & operator=(const rect22 &b)
	{
		a11=b.a11;
		a12=b.a12;
		a21=b.a21;
		a22=b.a22;
		return *this;
	}

};

class rect21
{
public:
	int a11,a21;
public:
	rect21( ):a11(0),a21(0){};
	rect21(int a,int b):a11(a),a21(b){};
	rect21 & operator=(const rect21 &b)
	{
		a11=b.a11;
		a21=b.a21;
		return *this;
	}

};

rect22 operator*(const rect22 &a,const rect22 &b)
{
	rect22 r;
	r.a11=(a.a11*b.a11+a.a12*b.a21)%10003;
	r.a12=(a.a11*b.a12+a.a12*b.a22)%10003;
	r.a21=(a.a21*b.a11+a.a22*b.a21)%10003;
	r.a22=(a.a21*b.a12+a.a22*b.a22)%10003;
	return r;
}

rect21 operator*(const rect22 &a,const rect21 &b)
{
	rect21 r;
	r.a11=(a.a11*b.a11+a.a12*b.a21)%10003;;
	r.a21=(a.a21*b.a11+a.a22*b.a21)%10003;;
	
	return r;
}


int main()
{
	int n,i,k,x,y,p,q;
	rect22 ss[2000];

	
	while(cin>>x)
	{
		if(x==0) break;
		cin>>y>>p>>q>>n;

		rect22 a(p,q,1,0),t,t2(1,0,0,1);
		t=a;
		ss[0]=t2;
		ss[1]=a;
		for(i=2;i<(log(n))/log(2)+2;++i)
		{
			t=t*t;
			ss[i]=t;
		}


		rect22 sum(1,0,0,1);
		rect21 begin(y,x),result;
		k=0;
		--n;
		while (n!=0)
		{
			i=n%2;
			++k;
			if (i)
			{
				sum=sum*ss[k];
			}
			n/=2;
			
		}

		result=sum*begin;

	//	cout<<result.a11<<" "<<result.a21<<endl;
		cout<<result.a21<<endl;
	}
}