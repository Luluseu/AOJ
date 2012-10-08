/************************************************************************/
/* 需要下列头文件
#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
                                                                       */
/************************************************************************/
/************************************************************************/
/*                    声明部分                                          */
/************************************************************************/
#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
using namespace std;
 
class BigInt
{
public:
    vector<int> i_data;
public:
    BigInt(const vector<int> &a):i_data(a){};
    BigInt(int);
    BigInt()
    {
        i_data.clear();
        i_data.push_back(0);
    }
public:
    BigInt& operator+=(const BigInt& b);
    BigInt& operator-=(const BigInt& b);
    BigInt& operator*=(const BigInt& b);
    BigInt& operator/=(const BigInt& b);
public:
    bool isSame(const BigInt& b) const;
    bool isSmaller(const BigInt& b)const;
    bool isBigger(const BigInt& b)const;
 
 
 
};
bool operator==(const BigInt& a,const BigInt& b);
bool operator<(const BigInt& a,const BigInt& b);
bool operator>(const BigInt& a,const BigInt& b);
BigInt operator+(const BigInt& a,const BigInt& b);
BigInt operator-(const BigInt& a,const BigInt& b);
BigInt operator*(const BigInt& a,const BigInt& b);
BigInt operator/(const BigInt& a,const BigInt& b);
BigInt operator%(const BigInt& a,const BigInt& b);
ostream& operator<<(ostream& out,const BigInt &num);
istream& operator>>(istream& in,BigInt &num);
 
 
void string2vecint(string in,vector<int> &out);
void func_power(vector<int> &out,vector<int> base,int exp);
//vector<int> func_multi(vector<int> a,vector<int> b);
vector<int> func_multi(const vector<int> &a,const vector<int> &b);
vector<int> func_multi(vector<int> a,int b);
//void func_add(vector<int> &sum,vector<int> a,int n);
void func_add(vector<int> &sum,const vector<int> &a,int n);
void func_minus(vector<int> &a,const vector<int> &b);
//void print(const vector<int> &sum,int nlog);
string vecint2string(const vector<int> &sum,int nlog);
void mitoa(int a,char *s,int c);
 
/************************************************************************/
/*       函数定义部分                                                   */
/************************************************************************/
BigInt::BigInt(int a)
{
    int i;
    i_data.clear();
    if (a==0)
    {
        i_data.push_back(0);
    }
    else
    while (a!=0)
    {
        i_data.push_back(a%10000);
        a/=10000;
    }
 
 
}
 
bool BigInt::isSame(const BigInt& b) const
{
    int i;
    if (i_data.size()!=b.i_data.size())
    {
        return false;
    }
    for (i=0;i<i_data.size();++i)
    {
        if (i_data[i]!=b.i_data[i])
        {
            return false;
        }
    }
    return true;
}
 
bool BigInt::isSmaller(const BigInt& b) const
{
    int i;
    if (i_data.size()>b.i_data.size())
    {
        return false;
    }
    if (i_data.size()<b.i_data.size())
    {
        return true;
    }
 
    for (i=i_data.size()-1;i>-1;--i)
    {
        if (i_data[i]>b.i_data[i])
        {
            return false;
        }
        else
        if (i_data[i]<b.i_data[i])
        {
            return true;
        }
        if (i==0)
        {
            return false;
        }
    }
}
 
bool BigInt::isBigger(const BigInt& b) const
{
    int i;
    if (i_data.size()>b.i_data.size())
    {
        return true;
    }
    if (i_data.size()<b.i_data.size())
    {
        return false;
    }
    for (i=i_data.size()-1;i>-1;--i)
    {
        if (i_data[i]<b.i_data[i])
        {
            return false;
        }
        else
            if (i_data[i]>b.i_data[i])
            {
                return true;
            }
            if (i==0)
            {
                return false;
            }
    }
}
 
BigInt& BigInt::operator+=(const BigInt& b)
{
    func_add(i_data,b.i_data,0);
    return *this;
}
BigInt& BigInt::operator-=(const BigInt& b)
{
    func_minus(i_data,b.i_data);
    return *this;
}
//BigInt& BigInt::operator-=(const BigInt& b);
BigInt& BigInt::operator*=(const BigInt& b)
{
    i_data=func_multi(i_data,b.i_data);
    return *this;
}
 
//BigInt& BigInt::operator/=(const BigInt& b);
/************************************************************************/
/*       重载非成员操作符部分                                           */
/************************************************************************/
 
 
    bool operator==(const BigInt& a,const BigInt& b)
    {
        return a.isSame(b);
    }
 
    bool operator<(const BigInt& a,const BigInt& b)
    {
        return a.isSmaller(b);
    }
 
    bool operator>(const BigInt& a,const BigInt& b)
    {
        return a.isBigger(b);
    }
    BigInt operator+(const BigInt& a,const BigInt& b)
    {
        BigInt r(a);
        func_add(r.i_data,b.i_data,0);
        return r;
    }
    BigInt operator-(const BigInt& a,const BigInt& b)
    {
        BigInt r(a);
        func_minus(r.i_data,b.i_data);
        return r;
    }
    BigInt operator*(const BigInt& a,const BigInt& b)
    {
        BigInt r;
        r.i_data=func_multi(a.i_data,b.i_data);
        return r;
    }
 
    ostream& operator<<(ostream& out,const BigInt &num)
    {
        string s;
        s=vecint2string(num.i_data,0);
        out<<s;
        return out;
    }
    istream& operator>>(istream& in,BigInt &num)
    {
        string s;
        in>>s;
 
        string2vecint(s,num.i_data);
        return in;
    }
 
 
 
/************************************************************************/
/*          其它运算函数部分                                            */
/************************************************************************/
 
void string2vecint(string in,vector<int> &out)
{
  string::size_type i;
  int int_A;
  string stmp;
  out.clear();
 
  while((i=in.size())!=0)
  {
    if(i>=4)
    {
      stmp=in.substr(i-4);
      int_A=atoi(stmp.c_str());
      out.push_back(int_A);
      in.erase(i-4,4);
    }
    else
    {
      stmp=in.substr(0);
      int_A=atoi(stmp.c_str());
      out.push_back(int_A);
      in.erase(0,in.size());
    }
 
  }
}
 
void func_power(vector<int> &out,vector<int> base,int exp)
{
  int i;
  out.clear();
  out.push_back(1);
  for(i=0;i<exp;i++)
  {
    out=func_multi(out,base);
 
  }
}
 
vector<int> func_multi(const vector<int> &a,const vector<int> &b)
{
  vector<int> r,tmp;
  vector<int>::size_type i;
  for(i=0;i<b.size();i++)
  {
    tmp=func_multi(a,b[i]);
    func_add(r,tmp,i);
 
  }
  ///////消除多余的0/////
  for(i=r.size()-1;i>0;--i)
  {
      if (r[i]!=0)
                break;
 
          r.pop_back();
 
  }
  return r;
}
 
vector<int> func_multi(vector<int> a,int b)
{
  vector<int>::size_type i;
  for(i=0;i<a.size();i++)
  {
    a[i]*=b;
  }
  for(i=0;i<a.size();i++)
  {
    if(a[i]>=10000)
    {
      if(i==a.size()-1) a.push_back(0);
      a[i+1]+=a[i]/10000;
      a[i]=a[i]%10000;
    }
  }
  return a;
}
 
void func_add(vector<int> &sum,const vector<int> &a,int n)
{
  vector<int>::size_type i;
  for(i=0;i<a.size();i++)
  {
    if(i+n+1>sum.size()) sum.insert(sum.end(),i+n+1-sum.size(),0);
    sum[i+n]+=a[i];
  }
 // cout<<"输出add函数中sum:"<<endl;
 // print(sum,4);
 
  for(i=0;i<sum.size();i++)
  {
    if(sum[i]>=10000)
    {
      if(i==sum.size()-1) sum.push_back(0);
      sum[i+1]+=sum[i]/10000;
      sum[i]=sum[i]%10000;
    }
  }
 
}
 
void func_minus(vector<int> &a,const vector<int> &b)
{
    vector<int>::size_type i;
    BigInt a1(a),b1(b);
    /***判断处理A<B***/
    if (a1<b1)
    {
        return;
    }
    if (a1==b1)
    {
        a.clear();
        a.push_back(0);
        return;
    }
    /****计算*****/
    for(i=0;i<b.size();i++)
    {
        a[i]-=b[i];
        if (a[i]<0)
        {
            a[i]+=10000;
            --a[i+1];
        }
 
    }
 
}
 
string vecint2string(const vector<int> &sum,int nlog)
{
    vector<int>::size_type i;
    string s;
    int tmp;
    bool f=0;
    char ss[10]={0};
    for (i=0;i<sum.size();++i)
    {
        if (sum[i]!=0)
        {
            f=1;
            break;
        }
    }
    if (!f)
    {
        s="0";
    }
    else
    {
    //取头
    mitoa(sum[sum.size()-1],ss,10);
    s+=ss;
    if(sum.size()>1){
        //取中间
        for(i=sum.size()-2;i>0;i--)
        {
            if(sum[i]<10)
            {
                s+="000";
            }
            else if(sum[i]<100)
            {
                s+="00";
            }
            else if(sum[i]<1000)
            {
                s+="0";
            }
            mitoa(sum[i],ss,10);
            s+=ss;
        }
        //取尾
        if(sum[0]<10)
        {
            s+="000";
        }
        else if(sum[0]<100)
        {
            s+="00";
        }
        else if(sum[0]<1000)
        {
            s+="0";
        }
        mitoa(sum[0],ss,10);
        s+=ss;            }
 
 
    //处理小数点
    tmp=s.size();
    if(nlog==0)
    {
 
    }
    else if(nlog>0)
    {
        s.append(nlog,'0');
    }
    else if(nlog>-tmp)
    {
        s.insert(tmp+nlog,1,'.');
        i=s.find_last_not_of('0');
        s.erase(i+1,s.size()-i-1);
        if(s[s.size()-1]=='.') s.erase(s.size()-1,1);
    }
    else
    {
        s.insert((string::size_type)0,-(tmp+nlog),'0');
        s.insert((string::size_type)0,"0.");
        i=s.find_last_not_of('0');
        s.erase(i+1,s.size()-i-1);
        if(s[s.size()-1]=='.') s.erase(s.size()-1,1);
    }
    //删除前面的0
    i=s.find_first_not_of('0');
    s.erase(0,i);
    //cout<<""<<s;
    //  cin>>s;
 
    }
 
    return s;
}
 
void mitoa(int a,char *s,int c)
{  int n,i=0;
   char s2[10];
 
     do
     {
        s2[i++]=a%c+'0';
        a=a/c;
     }while(a>0);
     for(n=0;n<i;n++) s[n]=s2[i-n-1];
     s[n]='\0';
}
 
 
int main()
{
    
	string s;
	int i;
    while(cin>>s)
    {

		cout<<s<<" [8] = 0";
		s.erase(string::size_type(0),2);
		
		BigInt a(0),base(1),I125(125),I1000(1000);
		for (i=0;i<s.size();++i)
		{
			base*=I125;
			BigInt tmp(s[i]-'0');
			a+=base*tmp;	
			a*=I1000;
		}
		s=vecint2string(a.i_data,(-3)*(s.size()+1));
		cout<<s<<" [10]"<<endl;
    }
}