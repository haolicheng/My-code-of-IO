#include <bits/stdc++.h>
#include <cmath>
using namespace std;

int n;

int main()
{
	scanf("%d",&n);
    n = n + n*1000;
    n = n/1001;
	printf("%d",n);
	return 0;
	}
