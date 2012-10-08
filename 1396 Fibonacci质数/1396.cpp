#include <iostream>
#include <math.h>

using namespace std;
#define  MAX 1000000
bool bsushu[MAX+1];//below 1000001
int sushu[MAX/10];
int len;

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
	r.a11=(a.a11*b.a11+a.a12*b.a21)%10003;
	r.a21=(a.a21*b.a11+a.a22*b.a21)%10003;
	
	return r;
}

void dabiao()
{
	int i,j;
	int bound=sqrt(MAX);
	for (i=2;i<=MAX;i+=2)
	{
		bsushu[i]=1;
	}
	for (i=3;i<bound;i+=2)
	{
		if(!bsushu[i])
		for (j=i+i;j<=MAX;j+=i)
		{
			bsushu[j]=1;
		}	
	}
	sushu[0]=2;
	j=0;
	for (i=3;i<MAX+1;i+=2)
	{
		if (!bsushu[i])
		{
			sushu[++j]=i;
		}
	}
	len=j+1;
}
int main()
{
	int i,nf,n,k;
	dabiao();
	
	rect22 ss[20];
	rect22 a(1,1,1,0),t;
	t=a;
	
	ss[1]=a;
	for(i=2;i<20;++i)
	{
		t=t*t;
		ss[i]=t;
	}
	/*/////////////////*
	for(i=0;i<100;++i)
	{
		cout<<sushu[i]<<" ";
	}
	*/////////////////
	cin>>n;
	while (n!=0)
	{
		nf=sushu[n-1];
		if (nf<5)
		{
			nf+=1;
		}
		rect22 sum(1,0,0,1);
		k=0;
		while (nf!=0)
		{
			i=nf%2;
			++k;
			if (i)
			{
				sum=sum*ss[k];
			}
			nf/=2;
			
		}
		cout<<sum.a12<<endl;

		cin>>n;
	}
}