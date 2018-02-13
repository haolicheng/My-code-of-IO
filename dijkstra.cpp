#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int T,N,sum =0;
bool vis[2005];
int dis[2005],g[2005][2005];
//struct node{
//int cost;int last;int value;int next;
//}e[2005];

/*void add(int x,int y,int z)
{
	++sum;
	e[sum].value = y;
	e[sum].cost = z;
	e[sum].next = head[x];
	head[x] = sum;
}*/

int main()
{
	scanf("%d%d",&T,&N);
	for(int i =0;i<=N;i++)
		for(int j = 0;j<=N;j++)
			g[i][j] = 1000000000;
	for(int i=1;i<=T;i++)
	{
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		//add(x,y,z);
		g[x][y]=min(g[x][y],z);
		g[y][x]=min(g[y][x],z);
	}
	for(int i = 0;i <=N;i++) dis[i] = 1000000000;
	//memset(dis,1000000000,T);
	memset(vis,0,sizeof(vis));//vis表示最小值是否固定
	dis[1]=0;
	for(int i =1;i<=N;i++)
	{
		int t = -1;
		for(int j=1;j<=N;j++)
		{
			if(vis[j] == 0 && (t == -1 || dis[j]<dis[t]))
			{
				t = j;
			}
		}
		vis[t]= 1;
		for(int j=1;j<=N;j++)
			{
			if(vis[j]==0) dis[j]=min(dis[j],dis[t]+g[t][j]);
		}
	}
	printf("%d\n",dis[N]);
	return 0;
}
