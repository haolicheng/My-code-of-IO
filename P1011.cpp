#include <bits/stdc++.h>
using namespace std;

int a,n,m,x;
int ans[25],s[25];

int main()
{
    scanf("%d%d%d%d",&a,&n,&m,&x);
    for(int j = 0; j<=25;j++)
    {
    for(int i = 1;i<=n;i++)
    {
        ans[i] = 0;
    }
    s[1] = a;
    s[2] = j;
    ans[1] = a;
    ans[2] = a;
    for(int i  =  3;i<=n;i++)
    {
        ans[i] = ans[i-1];
        ans[i] += s[i-1]+s[i-2];
        ans[i] -=  s[i-1];
        s[i] =  s[i-1]+s[i-2];
    }
   if(ans[n-1] == m) break;
}
printf("%d",ans[x]);
    return 0;
}