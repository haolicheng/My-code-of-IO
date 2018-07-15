#include <bits/stdc++.h>
using namespace std;

double R,X,P;

int main()
{
    cin>>R>>X>>P;
    double Y= X*pow(((100+R)/100),P);
    printf("%.2f",Y);
    return 0;
}
