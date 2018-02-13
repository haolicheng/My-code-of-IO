#include <bits/stdc++.h>
using namespace std;

int a[505],b[505];

int ans[505] = {0};

char c[505],d[505];

int main()
{
	gets(c);
	gets(d);
	int m = strlen(c);
	int n = strlen(d);
	for(int i = 1;i <= strlen(c);i++)
	{
		a[i] = int(c[m]);
		m--;
	}
	for(int i = 1;i <= strlen(d);i++)
	{
		b[i] = int(d[n]);
		n--;
	}
	for(int i =1;i<=500;i++)
	{
		ans[i]=a[i]+b[i];
		ans[i+1] += ans[i]/10;
		ans[i] = ans[i]%10;
	}
	
	for(int N = length(ans);N >= 0;N--)
	{
		cout<<ans[N];
	}
	return 0;
}