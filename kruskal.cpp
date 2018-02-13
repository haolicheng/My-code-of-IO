/*
https://www.luogu.org/problemnew/show/P1546
最小生成树 kruskal算法
入门经典 P356 
*/
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int n;
struct node{
	int value;int head;int ass;int no;
}g[100010];
bool vis[1000][1000];
int fa[100010];
int sum = 1;
int N;
void add(int x,int y,int z)
{
	++sum;
	g[sum].value = z;
	g[sum].head = x;
	g[sum].ass = y;
}

bool cmp(struct node a,struct node b){
	return a.value<b.value;
}

int find(int x)
{
	if(fa[x]==x) return x;
	return fa[x] = find(fa[x]);
}

int kruskal()
{
	int ans = 0;
	for(int i=1;i<=N;i++) fa[i] = i;
	sort(g+1,g+N+1,cmp);
	/*for(int k = 1;k<=N;k++)
	{
	printf("%d的值是%d\n",k,g[k]);
	}*/
	for(int j=1;j<=N;j++)
	{
		int nx = find(g[j].head);
		int ny = find(g[j].ass);
		if(nx != ny)
		{
			fa[nx] = ny;
			ans += g[j].value;
		}
	} 
	return ans;
}
int main()
{
	memset(vis,false,sizeof(vis));
	scanf("%d",&n);
	N = n*n;
	for(int i = 1;i <= n;i++)
	{
		for(int j =1;j<=n;j++)
		{
			int a;
			scanf("%d",&a);
			if(!vis[i][j] && !vis[j][i])
		{
			add(i,j,a);
			vis[i][j] = true;
			vis[j][i] = true;
		}
		}
	}
	printf("%d\n",kruskal());
	return 0;
}
