#include<bits/stdc++.h>
using namespace std;

int n,m;

int main()
{
    cin>>n;
    m = n%123;
    if(m>=97 && m<=122) printf("%c",m);
    else{
        n = n%91;
        if(n>=65&&n<=90) printf("%c",n);
        else cout<<"*";
    }
    return 0;
}
