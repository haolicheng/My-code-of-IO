#include<iostream>
#include<string>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

int n;
int ans[100010],c[100010];

int lowbit(int x){return x&(-x);}

void update(int x,int y)
{
    for(int i = x;i<= 100010;i+=lowbit(i))
        c[i] += y;
}

int getsum(int x)
{
    int ans = 0;
    for(int i = x;i>0;i -= lowbit(i))
        {ans+=c[i];}
    return ans;
}

int main()
{
    scanf("%d",&n);
    for(int i = 0;i<n;i++)
    {
        int m,n;
        scanf("%d%d",&m,&n);
        m++;
        ans[getsum(m)]++;
        update(m,1);
    }
    for(int i = 0;i<n;i++) printf("%d\n",ans[i]);
    return 0;
}