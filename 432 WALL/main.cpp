#include <iostream>
#include <cmath>
#include <cstdio>
#include <algorithm>
using namespace std;

struct point { double x, y; };
bool mult(point sp, point ep, point op){
	return (sp.x - op.x) * (ep.y - op.y)
		>= (ep.x - op.x) * (sp.y - op.y);
}
bool operator < (const point &l, const point &r){
	return l.y < r.y || (l.y == r.y && l.x < r.x);
}
int graham(point pnt[], int n, point res[]){
	int i, len, k = 0, top = 1;
	sort(pnt, pnt + n);
	if (n == 0) return 0; res[0] = pnt[0];
	if (n == 1) return 1; res[1] = pnt[1];
	if (n == 2) return 2; res[2] = pnt[2];
	for (i = 2; i < n; i++) {
		while (top && mult(pnt[i], res[top], res[top-1]))
		top--;
		res[++top] = pnt[i];
		}
		len = top; res[++top] = pnt[n - 2];
		for (i = n - 3; i >= 0; i--) {
		while (top!=len && mult(pnt[i], res[top], res[top-1])) top--;
		res[++top] = pnt[i];
		}
		return top; // 返回凸包中点的个数
}

double dis(const point &a, const point &b)
{
	double x=a.x-b.x;
	double y=a.y-b.y;
	return  sqrt(x*x+y*y);
}

double getlen(point pnt[], int n)
{
	int i;
	double sum=0;
	for (i=0;i<n-1;++i)
	{
		sum+=dis(pnt[i],pnt[i+1]);
	}
	sum+=dis(pnt[0],pnt[n-1]);
	return sum;
}

int main()
{
	int N,i,L;
	point PN[1005],POUT[1005];
	
	scanf("%d%d",&N,&L);
	for (i=0;i<N;++i)
	{
		scanf("%lf%lf",&PN[i].x,&PN[i].y);
	}
	int n=graham(PN,N,POUT);
//	cout<<n<<endl;
//	cout<<getlen(POUT,n)<<endl;
	printf("%d\n",int(getlen(POUT,n)+3.1415926*L*2+0.5));
}