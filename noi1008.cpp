#include<bits/stdc++.h>
using namespace std;

int a[4],n,s=0;

int main()
{
    cin>>n;
    a[1] = n/100;
    a[2] = (n/10)%10;
    a[3] = n%10;
    for(int i = 1;i<=3;i++) s+= pow(a[i],3);
    if(s == n) cout<<"YES";
    else cout<<"NO";
    return 0;
}
