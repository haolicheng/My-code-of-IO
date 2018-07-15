#include<bits/stdc++.h>
using namespace std;

double a,b,c;

int main()
{
    cin>>a>>b;
    c = fmod(a,b);
    printf("%.2f",c);
    return 0;
}
