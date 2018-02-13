#include <bits/stdc++.h>
using namespace std;

struct man{
	int cost;int sum;
};
struct man a[5005];

int n,m,ans=0,sum=0;

int cmp(struct man a,struct man b){return a.cost<b.cost;}

int main()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>a[i].cost>>a[i].sum;
	}
	sort(a+1,a+m+1,cmp);
	for(int i=1;i<=m;i++)
	{
	if(sum <= n){
		ans += a[i].cost*a[i].sum;
		sum += a[i].sum;
	}else{
		ans -= (sum-n)*a[i-1].cost;
		break;
	}
	}
	cout<<ans;
	return 0;
}

