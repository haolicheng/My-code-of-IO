#include<bits/stdc++.h>
using namespace std;

int a[5];
int t;

int main()
{
    cin>>a[1]>>a[2]>>a[3];
    sort(a+1,a+4);
    if(a[3] <a[1]+a[2]&&a[1]>a[3]-a[2])
    {
        if(a[1]==a[2]&&a[2]==a[3])
    {
        cout<<"Equilateral";
        return 0;
    }
    if(a[3]*a[3] == a[1]*a[1]+a[2]*a[2])
    {
        cout<<"Right";
        return 0;
    }
    cout<<"General";
    }else cout << "NO";
    return 0;
}
