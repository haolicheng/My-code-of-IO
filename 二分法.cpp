#include <bits/stdc++.h>
using namespace std;

int n,m,a[100010],b;

int l=1,r;

int cmp(int a,int b){return a<b;}

int search(int x)
{
	while(1)
	{
	int num = (l+r)/2;
	if(a[num]== x) return num;
	if(a[num] > x) 
	{
		r=num-1;
	}else{
		l=num+1;
	}
}
}

int main()
{
	cin >> n;
	r = n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1,cmp);
	cin>>m;
	for(int k=1;k<=m;k++) 
		{
			cin>>b; l=1; r=n;
			int ans = search(b);
			b = 0;
			cout<<ans<<endl;
		}
	return 0;
}
