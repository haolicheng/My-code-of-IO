#include <bits/stdc++.h>
using namespace std;

int R,C,sum;
int a[110][110];
int mx[]={1,-1,0,0},my[]={0,0,1,-1};

int move(int x,int y)
{
	int nx = x,ny = y;
	if(x == R && y == C)
	{
		return sum;
	}
	for(int i = 0;i < 4;i++)
	{
		nx += x + mx[i];
		ny += y + my[i];
		if(nx>=0 && nx<=R && ny>=0 && ny<=C)
		{
			sum += a[nx][ny];
			move(nx,ny);
		}
	}	
}

int main()
{
	cin >> R>>C;
	for(int i = 1;i <= R;i++)
	{
		for(int k =1;k<=C;k++)
		{
			cin >> a[i][k];
		}
	}
	cout << f(1,1);
	return 0;
}
