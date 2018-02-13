#include <iostream>
using namespace std;

int n,m,a;

bool judge(int x)
{
	if(x == 1) return false;
	for(int k = 2;k*k<=x;k++)
	{
		if(x%k == 0) return false;
	}
	return true;
}

int main()
{
	cin >>n>>m;
	for(int i =1;i<=m;i++)
	{
		cin >> a;
		cout <<endl;
		if(judge(a))
		{
			cout<<"Yes";
		}else{
			cout<<"No";
		}
	}

	return 0;
}