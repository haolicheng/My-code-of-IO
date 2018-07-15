#include<bits/stdc++.h>
using namespace std;

int m,n;

int main()
{
    cin>>m>>n;
    if((m+n)<10) cout<<"water";
    else{
        if(m>n) cout<<"tree";
        if(m<=n)cout<<"tea";
    }
    return 0;
}
