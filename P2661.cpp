#include <bits/stdc++.h>
using namespace std;

int n,v[500010],ne[500010],head[500010];
int cont = 0;
int vis[500010];
int num = 0;
int minn = 1000000000;
void add(int x,int y)
{
    ++num;
    v[num] = y;
    ne[num] = head[num];
    head[num] = num;
}
void dfs(int u)
{
    if(vis[v[u]]) return;
    cont++;
    for(int i = head[u];i;i = ne[u])
    {
        vis[v[i]] = true;
        dfs(v[i]);
    }
    minn = min(minn,cont);
}

int main()
{
    freopen("testdata.in","r",stdin);
    for(int i = 1;i<=n;i++) vis[i] = false;
    scanf("%d",&n);
    for(int i = 1;i<=n;i++)
    {
        int a;
        scanf("%d",&a);
        add(i,a);
    }
    dfs(1);
    printf("%d",minn);
    return 0;
}
