//建图解决
//寻最短路 dijkstra算法
#include <algorithm>
#include <cstdio>
using namespace std;

int n, a, b;
int g[210][210];
int dis[100010];
bool vis[100010];
void dij()
{
    for (int i = 1; i <= n; i++)
        vis[i] = false;
    for (int i = 1; i <= n; i++)
        dis[i] = 1000000000;

    dis[a] = 0;
    for (int i = 1; i <= n; i++)
    {
        int t = -1;
        for (int j = 1; j <= n; j++)
        {
            if (!vis[j] && (t == -1 || dis[j] < dis[t]))
                t = j;
        }
        vis[t] = true;
        for (int j = 1; j <= n; j++)
        {
            if (!vis[j])
            {
                dis[j] = min(dis[j], dis[t] + g[t][j]);
            }
        }
    }
}

int main()
{
    scanf("%d%d%d", &n, &a, &b);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            g[i][j] = 1000000000;
    for (int i = 1; i <= n; i++)
    {
        int j;
        scanf("%d", &j);
        if (i + j <= n)
            g[i][i + j] = 1;
        if (i - j > 0)
            g[i][i - j] = 1;
    }
    dij();
    if(dis[b] != 1000000000 ) printf("%d\n", dis[b]);
    else printf("-1");
    return 0;
}