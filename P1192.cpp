//转移方程 f[i]+=f[i-j];
//动态规划 递推
#include <cstdio>
using namespace std;

int n, k, f[100010];
int main()
{
    scanf("%d%d", &n, &k);
    f[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= k && (i - j) >= 0; j++)
        {
            f[i] += f[i - j];
        }
        f[i] %= 100003;
    }
    printf("%d", f[n]);
    return 0;
}