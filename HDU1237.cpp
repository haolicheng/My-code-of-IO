#include<bits/stdc++.h>
// #include<iostream>
// #include<string>
// #include<cstring>
// #include<cstdio>
// #include<algorithm>
// #include<cmath>
// #include<stdio.h>
using namespace std;
char a[100010];
double s[100010];
int top = 0;
int sum = 0;

void push(double x)
{
    //cout <<'#'<< x<<endl;
    s[++top] = x;
    //cout <<'#'<< s[top]<<endl;
}
double pop()
{
    top--;
    return s[top+1];
}

int main()
{
    while(1)
    {
        scanf("%[^\n]",a);
        getchar();
        if (a[0] == 48) return 0;
        for(int i = 0;i<strlen(a);i++)
        {
            //cout<<i<<'*'<<int(a[i])<<endl;
            if(47<a[i] && a[i]<58)
            {
                sum = a[i]-48+ sum*10;
               // cout<<i<<'*'<<sum<<endl;
            }
            if(a[i] == 43)
            {
               push(pop() + pop());
            }
            if(a[i] == 45)
            {
                push(pop()-pop());
            }
            if(a[i] == 42)
            {
                push(pop()*pop());
            }
            if(a[i] == 47)
            {
                push(pop()/pop());
            }
            if(a[i] == 32)
            {
                if(sum != 0)
                {
                 push(sum);
                 sum=0;
                }
            }
        }
      cout<<pop()<<endl;
      memset(a,0,sizeof(a));
    }
    return 0;
}