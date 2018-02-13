#include <bits/stdc++.h>
using namespace std;
int n;
int i = 4;
bool not_prime[10005]={0};

int main()
{
	for(int i=2;i<=10000;i++){
		if(!not_prime[i]){
			//not_prime[i] = false;
			for(int j=i;j*i<=10000;j++){
				not_prime[j*i]=true;
			}
		}
	}
			cin>>n;
			L:
			for(;i<=n;)
			{
			for(int a = 2;a<10000;a++)
			{
				if(not_prime[a])continue;
				for(int b = 2;b<10000;b++)
				{
					if(not_prime[b])continue;
					if(i == (a+b))
					{
					cout<<i<<'='<<a<<'+'<<b<<endl;				
					i+=2;
 					goto L;
				    }
				}
			}
			}
	return 0;
}
