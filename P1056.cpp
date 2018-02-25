#include <iostream>
#include <cstdio>
#include <algorithm>
#include <set>
using namespace std;

int m, n, k, l, d;
struct node{
    int n, p;
}rans[100010], lans[100010];

bool cmp(struct node a,struct node b)
{
    return a.n > b.n;
}
bool cmp1(struct node a,struct node b)
{
    return a.p < b.p;
}

int main()
{
    scanf("%d%d%d%d%d", &m, &n, &k, &l, &d);
    for (int i = 1; i <= d; i++)
    {
        int Xi, Yi, Pi, Qi;
        scanf("%d%d%d%d", &Xi, &Yi, &Pi, &Qi);
        if (Xi == Pi)
        {
            int a = min(Yi, Qi);
            if (0 < a <= n)
            {
                rans[a].p = a;
                rans[a].n++;
            }
        }
        else if (Yi == Qi)
        {
            int b = min(Xi, Pi);
            if (0 < b <= m)
            {
                lans[b].p = b;
                lans[b].n++;
            }
        }
    }
    sort(rans + 1, rans + n + 1, cmp);
    sort(lans + 1, lans + m + 1, cmp);
    sort(rans + 1, rans + l + 1, cmp1);
    sort(lans + 1, lans + k + 1, cmp1);
    for (int i = 1; i <= k; i++)
    {
        printf("%d ", lans[i].p);
    }
    printf("\n");
    for (int i = 1; i <= l; i++)
    {
        printf("%d ", rans[i].p);
    }
    return 0;
}