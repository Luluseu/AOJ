/*
ID:dingyag1
LANG:C++
TASK:stall4
*/
#include <string.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <queue>
#include <map>
using namespace std;

//#########################
#define MAXN 1000  
#define INF 2110000000  
int mmap[MAXN][MAXN];
#define MIN(x,y) (x<y?x:y)  
 
int max_flow(int num,int map[][MAXN],int source,int sink)//�������壺������� ���� Դ�� ���  
{  
    int my_queue[MAXN],queue_first,queue_end;//���������� ʵ��BFS����·��   
    int pre[MAXN],min_flow[MAXN];//��¼���ĸ��ڵ� ��ǰ·������С��һ�ε�ֵ��Ҳ������ֵ  
    int flow[MAXN][MAXN];//��¼��ǰ�����е���  
    int ans=0;//���ս��  
    memset(flow,0,sizeof(flow));  
    while(1)//һֱѭ����ֱ������������·��  
    {  
        queue_first=0;//��ʼ������  
        queue_end=0;  
        my_queue[queue_end++]=source;  
        memset(pre,-1,sizeof(pre));  
        min_flow[source]=INF;  
        pre[source]=-2;//Դ��ĸ��ڵ��������ʾ  
        while(queue_first<queue_end)//BFSѰ������·��  
        {  
            int temp=my_queue[queue_first++];//������  
            for(int i=0;i<num;i++)//�ɽ��temp������չ  
            {  
                if(pre[i]==-1&&flow[temp][i]<map[temp][i])//�����i��δ��̽���������һ��п�������  
                {     
                    my_queue[queue_end++]=i;//�������  
                    pre[i]=temp;//��ʾ���ڵ�  
                    min_flow[i]=MIN(min_flow[temp],(map[temp][i]-flow[temp][i]));//���min_flow  
                }  
            }  
            if(pre[sink]!=-1)//sink�ĸ��ڵ㲻Ϊ��ʼֵ��˵��BFS�Ѿ��ҵ���һ��·��  
            {  
                int k=sink;  
                while(pre[k]>=0)  
                {  
                    flow[pre[k]][k]+=min_flow[sink];//���µ���������flow  
                    flow[k][pre[k]]=-flow[pre[k]][k];  
                    k=pre[k];  
                }  
                break;  
            }  
        }  
        if(pre[sink]==-1) return ans;//����������·��������  
        else ans+=min_flow[sink];  
    }     
}  

//###########################


int main()
{
	freopen("1.txt","r",stdin);
	freopen("2.txt","w",stdout);
	
	int i,n,a,b,c,j;
	int N,M;
	string s1,s2;
	map<string,int> index;
	N=0;
	cin>>a;
	for (i=0;i<a;++i)
	{	
		
		cin>>s1;
		if (index.count(s1)==0)
		{
			N++;
			index[s1]=N+1;
		}
	}
	cin>>b;
	for (i=0;i<b;++i)
	{
		cin>>s1>>s2;
		if (index.count(s1)==0)
		{
			N++;
			index[s1]=N+1;
		}
		mmap[1][index[s1]]=1;
		if (index.count(s2)==0)
		{
			N++;
			index[s2]=N+1;
		}
		mmap[index[s1]][index[s2]]=1;
	}
	cin>>c;
	for (i=0;i<c;++i)
	{
		cin>>s1>>s2;
		if (index.count(s1)==0)
		{
			N++;
			index[s1]=N+1;
		}
		if (index.count(s2)==0)
		{
			N++;
			index[s2]=N+1;
		}
		mmap[index[s1]][index[s2]]=INF;
	}

	for (i=2;i<a+2;++i)
	{
		mmap[i][N+2]=1;
	}

	M=N+2;
	int r=b-max_flow(M+1,mmap,1,M);
	if (r<0)
	{
		r=0;
	}
	cout<<r<<endl;
	return 0;
}
