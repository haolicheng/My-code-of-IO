#include <bits/stdc++.h>
#include <cmath>
using namespace std;

double a,b,c;

int main()
{
	cin>>a>>b>>c;
	double p = (a+b+c)/2;
	double s = sqrt(p*(p-a)*(p-b)*(p-c));
	printf("%.4f",s);
	return 0;
	}
