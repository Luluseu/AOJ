#include <iostream>

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
	r.a11=(a.a11*b.a11+a.a12*b.a21)%10000;
	r.a12=(a.a11*b.a12+a.a12*b.a22)%10000;
	r.a21=(a.a21*b.a11+a.a22*b.a21)%10000;
	r.a22=(a.a21*b.a12+a.a22*b.a22)%10000;
	return r;
}

rect21 operator*(const rect22 &a,const rect21 &b)
{
	rect21 r;
	r.a11=(a.a11*b.a11+a.a12*b.a21)%10000;;
	r.a21=(a.a21*b.a11+a.a22*b.a21)%10000;;
	
	return r;
}


int main()
{
	int n,i,k;
	rect22 ss[2000];
	rect22 a(1,1,1,0),t;
	t=a;

	ss[1]=a;
	for(i=2;i<2000;++i)
	{
		t=t*t;
		ss[i]=t;
	}
/*
	for(i=1;i<100;++i)
	{
		cout<<ss[i].a11<<" "<<ss[i].a12<<endl<<ss[i].a21<<" "<<ss[i].a22<<endl<<endl;
	}
*/	
	while(cin>>n)
	{
		if(n==0) break;
		rect22 sum(1,0,0,1);
		k=0;
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
	//	cout<<sum.a11<<" "<<sum.a12<<endl<<sum.a21<<" "<<sum.a22<<endl<<endl;
		cout<<sum.a12<<endl;
	}
}