#include <cstdio>
using namespace std;

int N,M,S;
int sum = 0;
int head[500010];
struct edge{
int y;int next;int value;int x;
}line[500010];
//int line[500010]
int add(int x,int y,int z)
{
	++sum;
	line[sum].x = x;
	line[sum].y = y;
	line[sum].value = z;
	line[sum].next = head[x];
	head[x] = sum;
}

bool vis[500010];
int dis[500010];
int main()
{
	scanf("%d%d%d",&N,&M,&S);
	for(int i=1;i<=M;i++)
	{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		add(a,b,c);
	}
	memset(vis,false,sizeof(vis));
	memset(dis,2147483647,sizeod(dis));
	dis[1]=0;
	for(int i = 1;i<=N;i++)
	{
		int t = -1;
		for(int j = 1;j<=N;j++)
		{
			if(!vis[j]&&(t == -1||dis[j]<dis[t]))
			{
				t = j;
			}
		}
		vis[t] = true;
		for (int j=head[t];j!=-1;j=edge[j].next)
		{
			if(!vis[line[j].y])
			{
				dis[line[j].y] = min(dis[line[j].y],dis[line[t].x]+line[j].value);
			}
		}
	}
	printf("%d",dis[S]);
	return 0;
}