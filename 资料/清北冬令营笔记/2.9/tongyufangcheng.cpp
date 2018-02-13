#include<cstdio>
using namespace std;

long long exgcd(long long a,long long b,long long &x,long long &y){
	long long t;
	if(!b) {x=1;y=0;return a;}
	t=exgcd(b,a%b,y,x);
	y-=(a/b)*x;
	return t;
}

int main(){
	long long a,b;
	scanf("%lld%lld",&a,&b);
	long long x,y;
	exgcd(a,b,x,y);
	x=(x%b+b)%b;
	printf("%lld\n",x);
	return 0;
}
