#include <iostream>
#include <list>
#include <algorithm>

//#define DEBUG

struct xy
{
	int x,y;
};


using namespace std;
int main()
{
//	freopen("data1.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	char a[20][20],c;
	bool b[20][20]; //�㼣
	list<xy> li;
	list<xy>::iterator p;
	xy start,end,temp;

	int m,n,t,i,j,num,r;
	cin>>n>>m>>t;
	while(m!=0)
	{
		for(i=0;i<m;++i)
		{
			for(j=0;j<n;++j)
			{
				b[i][j]=0;			//�����㼣
				cin>>a[i][j];
				if(a[i][j]=='S')
				{
					start.x=i;
					start.y=j;
					b[i][j]=1;		//����㼣
				}
				else if(a[i][j]=='P')
				{
					end.x=i;
					end.y=j;
				}
			}
			getchar();
		}
		///////////////////////////��ʼ����
		num=1;r=0;
		li.clear();
		li.push_back(start);		//����ǰ��
		for (p=li.begin();li.size()!=0;)
		{
			if(num>t) break;
#ifdef DEBUG
			cout<<"��ǰλ�� "<<p->x<<p->y<<endl;
#endif			//������~
			if (p->x>0)
			{
#ifdef  DEBUG
				cout<<"UP S"<<endl;
#endif				
				temp.x=p->x-1;
				temp.y=p->y;
				if (b[temp.x][temp.y]==0&&a[temp.x][temp.y]!='*')
				{
					if (a[temp.x][temp.y]=='P')
					{
						r=num;
						break;
					}
					b[temp.x][temp.y]=1;
					li.push_front(temp);
				}
			}
			//������
			if (p->x<m-1)
			{
#ifdef DEBUG
				cout<<"down S"<<endl;
#endif
				temp.x=p->x+1;
				temp.y=p->y;
				if (b[temp.x][temp.y]==0&&a[temp.x][temp.y]!='*')
				{
					if (a[temp.x][temp.y]=='P')
					{
						r=num;
						break;
					}
					b[temp.x][temp.y]=1;
					li.push_front(temp);

				}
			}

			//������
			if (p->y>0)
			{
#ifdef DEBUG
				cout<<"left S"<<endl;
#endif
				temp.x=p->x;
				temp.y=p->y-1;
				if (b[temp.x][temp.y]==0&&a[temp.x][temp.y]!='*')
				{
					if (a[temp.x][temp.y]=='P')
					{
						r=num;
						break;
					}
					b[temp.x][temp.y]=1;
					li.push_front(temp);
				}
			}

			//������
			if (p->y<n-1)
			{
#ifdef DEBUG
				cout<<"right S"<<endl;
#endif
				temp.x=p->x;
				temp.y=p->y+1;
				if (b[temp.x][temp.y]==0&&a[temp.x][temp.y]!='*')
				{
					if (a[temp.x][temp.y]=='P')
					{
						r=num;
						break;
					}
					b[temp.x][temp.y]=1;
					li.push_front(temp);
				}
			}
			//ɾ���˸�
			p=li.erase(p);
			//���ָ�뵽ͷ���ұ�Ϊ�գ���ǰ������������p���ر�ͷ����ʼ��һ������


			if (p==li.end()&&li.size()!=0)
			{
#ifdef DEBUG
				cout<<"---------------"<<num<<"li.size="<<li.size()<<endl;
#endif
				++num;
				p=li.begin();
			}

		
		}

#ifdef DEBUG
		cout<<"r="<<r<<endl;
#endif
		if (r<=t&&r!=0)
		{
			cout<<"YES"<<endl;
		}
		else
			cout<<"NO"<<endl;

		cin>>n>>m>>t;
	}
}