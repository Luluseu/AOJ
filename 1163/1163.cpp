#include <stdio.h>


class rect22
{
public:
	__int64 a11,a12,a21,a22;
public:
	rect22():a11(0),a12(0),a21(0),a22(0){}
	rect22(__int64 a,__int64 b,__int64 c,__int64 d):a11(a),a12(b),a21(c),a22(d){};

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
	__int64 a11,a21;
public:
	rect21( ):a11(0),a21(0){};
	rect21(__int64 a,__int64 b):a11(a),a21(b){};
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
	r.a11=(a.a11*b.a11+a.a12*b.a21);
	r.a12=(a.a11*b.a12+a.a12*b.a22);
	r.a21=(a.a21*b.a11+a.a22*b.a21);
	r.a22=(a.a21*b.a12+a.a22*b.a22);
	return r;
}

rect21 operator*(const rect22 &a,const rect21 &b)
{
	rect21 r;
	r.a11=(a.a11*b.a11+a.a12*b.a21);
	r.a21=(a.a21*b.a11+a.a22*b.a21);
	
	return r;
}


int main()
{
	int n,i,k;
	__int64 sss=1564564654;
	rect22 ss[10];
	rect22 a(1,1,1,0),t;
	t=a;

	ss[1]=a;
	for(i=2;i<10;++i)
	{
		t=t*t;
		ss[i]=t;
	}

	scanf("%d",&n);
	while(n!=0)
	{
		if(n==0) break;
		rect22 sum(1,0,0,1);
		k=0;
		n+=1;
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

		printf("%I64d\n",sum.a12);

		scanf("%d",&n);
	}
}