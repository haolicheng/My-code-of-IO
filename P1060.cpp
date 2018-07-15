//0-1背包问题
#include <bits/stdc++.h>
using namespace std;

int m,n;
long long ans[100010],w[100010],money[100010];

int main()
{
    scanf("%d%d",&m,&n);
for(int i = 1;i<=n;i++)
{        int x,y;
        scanf("%d%d",&x,&y);
        w[i] = x*y;
        money[i] = x;
}
    for(int i =1;i<=n;i++)
    {
         for(int j=m;j>=money[i];j--)
          {  if(j>=money[i])
            {
                ans[j]=max(ans[j],ans[j-money[i]]+w[i]);
            }
            }
    }
    printf("%d",ans[m]);
    return 0;
}