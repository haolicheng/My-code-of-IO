#include <iostream>
#include <cstdio>
using namespace std;

long long n,m,a;
long long x,y;

int main()
{
    cin>>n>>m>>a;
    x = n/a;
    y = m/a;
    cout<<x*y;
    return 0;
}
